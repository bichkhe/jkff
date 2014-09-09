/**
 * @file   VerilogScanner.h
 * @author Minh D. Nguyen
 * @date   Tue Apr  3 10:33:27 2012
 * 
 * @brief  Wrapper for yyLexer to scan for Verilog token
 * 
 * 
 */


#ifndef __VERILOG_SCANNER_H__
#define __VERILOG_SCANNER_H__

#ifndef yyFlexLexer
//#undef yyFlexLexer
#define yyFlexLexer VerilogParserFlexLexer
#define FlexLexer rtplibFlexLexer
#include <FlexLexer.h>
//#undef yyFlexLexer
#endif // yyFlexLexer

#include <iostream>
#include <string>

class VerilogParserFlexLexer;
//! \brief This is the base class for \a VerilogParser, and it is not intended
//! for dircect use.
class VerilogScanner : public VerilogParserFlexLexer 
{

public: // constructors
   VerilogScanner() {}

public: // methods
	virtual int yylex();

protected: // members

};

#endif
