/**
 * @file   VerilogAst.cpp
 * @author Minh D. Nguyen
 * @date   Mon Apr  2 14:26:05 2012
 * 
 * @brief  Implementation of Verilog AST
 * 
 * 
 */
#include "VerilogAst.h"
#include "../exceptions/defaultexception.h"


VerilogNode* VerilogAst::GetVerilogNode(VerilogNode::VerilogId id)
{
		if (id < mVerilogNodes.size())
				return mVerilogNodes[id];
		else {
				std::cout<<"Default Exception"<<std::endl;
        std::string message="EXCEPTION: Trying to get out of bound verilog node";
        throw DefaultException(message);
		}
		return NULL;
}

VerilogAst::~VerilogAst()
{
  	for (unsigned i=0;i<mVerilogNodes.size();i++)
  			delete mVerilogNodes[i];
}


VerilogNode::VerilogId 
VerilogAst::AddVerilogNode(VerilogNode* new_node)
{

		VerilogNode::VerilogId new_id = mVerilogNodes.size();
		new_node->SetId(new_id);
		mVerilogNodes.push_back(new_node);
}


void VerilogAst::DFS(fstream &file, VerilogNode *rootNode)
{
  if(rootNode!=NULL)
    {
      
	for(int i=0; i < rootNode->GetChildrenNode().size(); i++)
	{
	  if(rootNode->GetChildrenNode()[i]!=NULL)
 	    {
		file << "\t" << rootNode->GetID() << "->" << rootNode->GetChildrenNode()[i]->GetID() << "\n";
		file	<< "\t" << rootNode->GetID()
			<< "[label=\"" << rootNode->GetTypeName() << " " << rootNode->GetName() << "\"]" << endl;
		file	<< "\t" << rootNode->GetChildrenNode()[i]->GetID() 
			<< "[label=\"" << rootNode->GetChildrenNode()[i]->GetTypeName()  << " " << rootNode->GetChildrenNode()[i]->GetName() << "\"]" << endl;
		DFS(file, rootNode->GetChildrenNode()[i]);
	    }
	}
  }
}

std::ostream& operator<<(std::ostream& out, const VerilogAst& verilogast)
{
 
	out << "Verilog AST:" << verilogast.mId << std::endl;
	//begin create graph and store in file .dot
	fstream dotAst;	
	dotAst.open("dotAst.dot",fstream::out);
	dotAst	<< "digraph G{\n";
	VerilogAst VA = (VerilogAst)(verilogast);
	VA.DFS(dotAst, VA.mVerilogNodes.back());
	dotAst	<< "\n}";
	dotAst.close();

	//end create graph
	
	/* DFS from VerilogNode 
	*
	*/		
	/*	out << "Verilog AST:" << verilogast.mId << std::endl;
	// This DFS for Verilog Ast
	  VerilogNode* module=verilogast.mRootNode;
	  if(module!=NULL)
			{
				std::cout<< module->GetID() <<"---" <<module->GetTypeName()<<std::endl;
			}
		module->DFS();*/
		
	return out;
}
