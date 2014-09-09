/**
 * @file   VerilogNode.h
 * @author Minh D. Nguyen
 * @date   Mon Apr  2 14:42:39 2012
 * 
 * @brief  Class header file VerilogNode.
 * Declare data structure to store verilog language syntax elements as nodes of the AST
 * 
 * 
 */

#ifndef VERILOG_NODE
#define VERILOG_NODE

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "VerilogAst.h"

class VerilogAst;

class VerilogNode 
{
 public:
	typedef unsigned VerilogId;
	
	typedef enum 
	{
		NO_TYPE,
		/* top level things */
		FILE_ITEMS,
		MODULE, 
		/* VARIABLES */
		INPUT, 
		OUTPUT, 
		INOUT,
		WIRE,
		REG,
		PARAMETER,
		PORT,
		/* OTHER MODULE ITEMS */
		MODULE_ITEMS, 
		VAR_DECLARE,
		VAR_DECLARE_LIST,
		ASSIGN,
		/* primitives */
		GATE,
		GATE_INSTANCE,
		/* Module instances */
		MODULE_CONNECT_LIST,
		MODULE_CONNECT,
		MODULE_PARAMETER_LIST,
		MODULE_PARAMETER,
		MODULE_NAMED_INSTANCE,
		MODULE_INSTANCE,
		/* statements */
		BLOCK, 
		NON_BLOCKING_STATEMENT,
		BLOCKING_STATEMENT,
		CASE,
		CASE_LIST,
		CASE_ITEM,
		CASE_DEFAULT,
		ALWAYS,
		IF,
		IF_Q,
		FOR,
		/* Delay Control */
		DELAY_CONTROL,
		EVENT_CONTROL,
		POSEDGE,
		NEGEDGE, 
		/* expressions */
		EXPRESSION_LIST,
		BINARY_OPERATION, 
		UNARY_OPERATION,
		/* basic primitives */
		ARRAY_REF, 
		RANGE_REF,
		CONCATENATE,
		/* basic identifiers */
		IDENTIFIERS,
		NUMBERS, 
		/* Hard Blocks */
		HARD_BLOCK, 
		HARD_BLOCK_NAMED_INSTANCE, 
		HARD_BLOCK_CONNECT_LIST,
		HARD_BLOCK_CONNECT,
		// EDDIE: new enum value for ids to replace MEMORY from operation_t
		RAM
	} VerilogType;

 public:
	
	/** 
	 * Constructor
	 * 
	 * @param id : node id (index) in the vector of nodes in AST
	 * @param type : node type 
	 * @param name : node name
	 */
 VerilogNode(VerilogType type=NO_TYPE, std::string name="", VerilogId id=0):mType(type),mName(name),mId(id){};
	/** 
	 * Default destructor
	 * 
	 * 
	 * @return 
	 */
	virtual ~VerilogNode();
	/** 
	 * Add a node child to the vector contains children nodes of the current node
	 * 
	 * @param child : child node to be added
	 */
	void AddChild(VerilogNode* child);
	/** 
	 * Return the verilog file name
	 * 
	 * 
	 * @return filename
	 */
	std::string GetFileName() { return mFilename;}
	/** 
	 * Set the file name
	 * 
	 * @param filename 
	 */
	void SetFileName(std::string filename) {mFilename = filename;}
	/** 
	 * Return the verilog statement line number in the verilog file 
	 * 
	 * 
	 * @return line number 
	 */
	int GetLineNumber() { return mLineNumber;}
	void SetLineNumber(int line) {mLineNumber = line;}

	VerilogId GetID() { return mId;}
	void SetId(VerilogId id) {mId = id;}
	std::string GetName() { return mName;}
	VerilogType GetType() {return mType;}
	/** 
	 * Return the string name for the node type
	 * For example: "MODULE"
	 * 
	 * @return 
	 */
	std::string GetTypeName() const { return std::string(VerilogTypeName[unsigned(mType)]);} 
	/** 
	 * Output function to print out the node information
	 * 
	 * @param out 
	 * @param node 
	 * 
	 * @return 
	 */
	friend std::ostream& operator<< (std::ostream& out, const VerilogNode& node);
	
	
	/**
	* Set current node to AST 	
	*/
	void SetVerilogAst(VerilogAst* verilogast) {mVerilogAst = verilogast;}
	VerilogAst* GetVerilogAst() { return mVerilogAst;}
	std::vector<VerilogNode*>& GetChildrenNode(){ return mChildrenNodes;}

	/**
	 * DFS for this node
	 * @return pointer point this current node
	 */
	VerilogNode* DFS();
	
	/*
	 * 
	 */
	void SetName(string name)
	{
	  mName=name;
	}
	
	
 protected:
	/// the type of the current node.
	VerilogType mType;
	/// the node name
	std::string mName;
	/// the node id which is its index in the vector of nodes in the VerilogAst
	VerilogId mId;
	/// the VerilogAst that contains the current node
	VerilogAst* mVerilogAst;
	/// the vector contains the children nodes of the current node in the AST. (The current node's fanout)
	std::vector<VerilogNode*> mChildrenNodes;
	/// the verilog filename that is parsed to the current node
	std::string mFilename;
	/// the line number of the verilog statement that is parsed to the current node
	int mLineNumber;
	/// array to convert verilog type into string
	static char VerilogTypeName[][30];
};
#endif 
