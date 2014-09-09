/**
 * @file   VerilogAst.h
 * @author Minh D. Nguyen
 * @date   Mon Apr  2 11:32:42 2012
 * 
 * @brief  Headerfile Class Verilog Abstract Syntax Tree
 * The class verilog ast is a tree of VerilogNode. Each verilog node 
 * present a syntax element of the verilog language. Each verilog node
 * is assigned an VerilogId which is its index in a vector of nodes. 
 * 
 * 
 */

#ifndef VERILOG_AST_H
#define VERILOG_AST_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "VerilogNode.h"

class VerilogNode;

class VerilogAst
{


public:
	typedef unsigned int VerilogAstId;		
	/** 
	 * Destructor: free memory allocation of the verilog nodes
	 * 
	 * 
	 * @return 
	 */
	virtual ~VerilogAst();
	/** 
	 * Default Constructor
	 * @param id
	 * Set up a vector containing AstNode
	 */
 	VerilogAst(VerilogAstId id):mId(id),mRootNode(NULL){
	
	}
	/** 
	 * Add a Verilog Language Node to the tree. The node should be allocated before added
	 * The node is added to the vector of nodes. If it is successfully added,
	 * a node id is returned. Otherwise, 0 is returned.
	 * The function will check if the node fanouts have already been created. 
	 * @param mNewNode:
	 */
	unsigned AddVerilogNode(VerilogNode* new_node);

	
	/** 
	 * Get a Verilog node by its id
	 * 
	 * @param id
	 * 
	 * @return the component with the given id
	 */
	VerilogNode* GetVerilogNode(unsigned id);

	void DFS(fstream &file, VerilogNode *rootNode);
	/** 
	 * Print out the verilog ast to a file
	 * 
	 */
	friend std::ostream& operator<<(std::ostream& out, const VerilogAst& verilogast);

	/** 
	 * Return the verilog file name that is parsed to the current AST
	 * 
	 * 
	 * @return 
	 */
	std::string GetFilename() { return mFilename;}
	void SetFilename(std::string name) { mFilename=name;}

	/**
	* Return the root node of ast
	*/
	  VerilogNode* GetRootNode(){return mRootNode;}
	 void SetRootNode(VerilogNode* node){ this->mRootNode=node;}
	
	
protected:
	/// The ast identifier, it can be used as index of the ast in the vector of ast
	VerilogAstId mId;
	/// The root node of the verilog ast
  	VerilogNode* mRootNode;
	/// The vector consists of all verilog node that are in the verilog ast
	std::vector<VerilogNode*> mVerilogNodes;
	/// The verilog file name that is parsed to the current ast
	std::string mFilename;
	
};
#endif 
