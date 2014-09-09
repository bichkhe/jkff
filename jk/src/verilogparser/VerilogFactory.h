/*! \file VerilogFactory.h
    \brief This file provdes an abstract interface for creating
    verilog language syntax nodes. It is to be implemented by users of the VerilogParser.

    \author  Minh Nguyen

	\copyright (c) EDABK, TUKL 2012
*/

#ifndef VERILOG_FACTORY_H
#define VERILOG_FACTORY_H

#include <string>
#include <vector>
#include <exception>
#include "VerilogNode.h"
/*!
  \class VerilogFactory
  \brief This class is an abstract interface which is driven by
  the VerilogParser and must be implemented by its users.
  It defines abstract (pure virtual) methods for each syntax element
  the parser is reading from a Verilog file.
  There are two sides of the interface:
  a) The parser side, driving the interface (using its methods) which has
  knowledge about the content (language syntax) of a Verilog file.
  b) The user side, implementing the interface and providing the
  parser with results (VerilogNode pointer) of the interface methods.
  There are methods belonging to each section and language elements of the file.
  Each function must return a unique pointer corresponding to the result
  on the user side. 
*/
class VerilogFactory {

public:
	virtual ~VerilogFactory(){}; // keep GCC happy

	//! \brief This exception may be thrown by each of the factory functions
	//! of \a VerilogFactory and is catched within \a VerilogParser, which in
	//! turn throws \a Verilog_Exception, containing the line number and token,
	//! that must be catched by the user of the parser.
	class Exception : public std::exception
	{
	public:
		Exception(const std::string what) : m_What(what) {}
		~Exception() throw() {}
		const char* what() const throw() { return m_What.c_str(); }

	private:
		const std::string	m_What;
	};

	//! Returns the name of this factory.
	virtual std::string name() const = 0;

	virtual VerilogNode* MakeModule(string module_name){return NULL;}
	virtual VerilogNode* MakePort(string port_name){return NULL;}
	virtual VerilogNode* MakePortList(){return NULL;}
	virtual VerilogNode* MakeVarDeclareList(){return NULL;}
	virtual VerilogNode* MakeIdentifier(string name){return NULL;}
	virtual VerilogNode* MakeModuleItem(){return NULL;}
	virtual VerilogNode* MakeVarDeclare(){return NULL;}
	virtual VerilogNode* MakeBinaryOperation(){return NULL;}
	virtual VerilogNode* MakeAssign(){return NULL;}
	virtual VerilogNode* MakeBlockingStatement(){return NULL;}
	virtual VerilogNode* MakeNumber(int number){return NULL;}
	
	// make always 27-04
	virtual VerilogNode* MakeEventControl(){return NULL;}
	virtual VerilogNode* MakeBlock(){return NULL;}
	virtual VerilogNode* MakeAlways(){return NULL;}
	
	// make always 03-05
	virtual VerilogNode* MakePosedge(){return NULL;}
	virtual VerilogNode* MakeNegedge(){return NULL;}
	virtual VerilogNode* MakeNonBlockingStatement(){return NULL;}
	virtual VerilogNode* MakeUnaryOperation(){return NULL;}
	virtual VerilogNode* MakeIf(){return NULL;}
	virtual VerilogNode* MakeRange(){return NULL;}
	
	// make case 04-05
	virtual VerilogNode* MakeCase(){return NULL;}
	virtual VerilogNode* MakeCaseList(){return NULL;}
	virtual VerilogNode* MakeCaseItem(){return NULL;}
	virtual VerilogNode* MakeCaseDefault(){return NULL;}
	virtual VerilogNode* MakeIfQuestion(){return NULL;}

	// 10-05 make parameter, gate
	virtual VerilogNode* MakeGate(){return NULL;}
	virtual VerilogNode* MakeGateInstance(){return NULL;}

	// 16-05 make For
	virtual VerilogNode* MakeFor(){return NULL;}
	virtual VerilogNode* MakeRealNumber(string real_num_str){return NULL;}
	virtual VerilogNode* MakeBitBase(string bit_base_string){return NULL;}
	virtual VerilogNode* MakeConcatenate(){return NULL;}
	virtual VerilogNode* MakeExpressionList(){return NULL;}
	virtual VerilogNode* MakeArrayRef(){return NULL;}
};

#endif
