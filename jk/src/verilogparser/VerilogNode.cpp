/**
 * @file   VerilogNode.cpp
 * @author Minh D. Nguyen
 * @date   Mon Apr  2 15:40:54 2012
 * 
 * @brief  Implementation of verilog node in the AST
 * 
 * 
 */

#include "VerilogNode.h"
#include "../exceptions/defaultexception.h"
char VerilogNode::VerilogTypeName[][30] = {
		"NO_TYPE",
		/* top level things */
		"FILE_ITEMS",
		"MODULE", 
		/* VARIABLES */
		"INPUT", 
		"OUTPUT", 
		"INOUT",
		"WIRE",
		"REG",
		"PARAMETER",
		"PORT",
		/* OTHER MODULE ITEMS */
		"MODULE_ITEMS", 
		"VAR_DECLARE",
		"VAR_DECLARE_LIST",
		"ASSIGN",
		/* primitives */
		"GATE",
		"GATE_INSTANCE",
		/* Module instances */
		"MODULE_CONNECT_LIST",
		"MODULE_CONNECT",
		"MODULE_PARAMETER_LIST",
		"MODULE_PARAMETER",
		"MODULE_NAMED_INSTANCE",
		"MODULE_INSTANCE",
		/* statements */
		"BLOCK", 
		"NON_BLOCKING_STATEMENT",
		"BLOCKING_STATEMENT",
		"CASE",
		"CASE_LIST",
		"CASE_ITEM",
		"CASE_DEFAULT",
		"ALWAYS",
		"IF",
		"IF_Q",
		"FOR",
		/* Delay Control */
		"DELAY_CONTROL",
		"EVENT_CONTROL",
		"POSEDGE",
		"NEGEDGE", 
		/* expressions */
		"EXPRESSION_LIST",
		"BINARY_OPERATION", 
		"UNARY_OPERATION",
		/* basic primitives */
		"ARRAY_REF", 
		"RANGE_REF",
		"CONCATENATE",
		/* basic identifiers */
		"IDENTIFIERS",
		"NUMBERS", 
		/* Hard Blocks */
		"HARD_BLOCK", 
		"HARD_BLOCK_NAMED_INSTANCE", 
		"HARD_BLOCK_CONNECT_LIST",
		"HARD_BLOCK_CONNECT",
		// EDDIE: new enum value for ids to replace MEMORY from operation_t
		"RAM"
		};

VerilogNode::~VerilogNode()
{
		
}

void VerilogNode::AddChild(VerilogNode* child)
{
		mChildrenNodes.push_back(child);
}


std::ostream& operator<< (std::ostream& out, const VerilogNode& node)
{
	out << "Verilog Node:" << node.mId << ":" << node.mName << ":" << node.GetTypeName() << std::endl;
		return out;
}

VerilogNode*
VerilogNode::DFS()
{
 
	std::ofstream ofs;

	
	bool isFinished=false;
	// Breaking condition
	VerilogNode* node=this;
	if(this==NULL)
	  {
	    std::cout <<"Stop!"<<std::endl;
	  }
	else 
	  {
	    //Previous task
	    switch(node->GetType())
	      {
	      case NUMBERS:
	      case IDENTIFIERS:
		std::cout<<" IDENIFIERS node: "<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl;
		break;
	      case MODULE: std::cout <<" This is a module node"<<std::endl; break;
		// Chang lam gi ca 
		// Danh dau 2 node con cua no ben trai
	      case MODULE_ITEMS:
		std::cout << "Module items node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case INPUT:
		std::cout << "Input node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
		// Tao cac input component;
	      case OUTPUT:
		// Tao cac output component
		std::cout << "Output node:"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case REG:
		// Tao cac output component
		std::cout << "REG node:"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case ALWAYS:
		std::cout<<"ALWAYS node:"<<node->GetTypeName() <<" : "<<node->GetName()<<std::endl; break;
	      case BLOCK:
		std::cout<<"BLOCK node:"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case BINARY_OPERATION:
		std:: cout<<" BINARY OPERATION node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case IF: 
		std:: cout<<" IF node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      }
	    //std::cout<<node->GetChildrenNode().size();
	    // Not complete 
	    if(isFinished==false)
	      {
		//std::cout<<node->GetChildrenNode().size();
		for(int i=0; i<node->GetChildrenNode().size();i++)
		  {
		    //std::cout <<"--------";
		    VerilogNode* temp=node->GetChildrenNode()[i];
		    std::cout<<"\n"<<node->GetTypeName()<<" has child nodes:\n";
		    ofs.open("info.txt",std::fstream::app);
		    
		    ofs<< temp->GetName()<<"-->"<<std::endl;
		    temp->DFS();
		  }
	      }
	    //
	    
	    switch(this->GetType())
	      {
	      case MODULE: std::cout <<"Affer:  Module node is processing"<<std::endl;
	      case NUMBERS:
	      case IDENTIFIERS:
		std::cout<<"Affer: IDENIFIERS node: "<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl;
		break;
		// Chang lam gi ca 
		// Danh dau 2 node con cua no ben trai
	      case MODULE_ITEMS:
		std::cout << "Affer: Module items node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case INPUT:
		std::cout << "Affer: Input node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
		// Tao cac input component;
	      case OUTPUT:
		// Tao cac output component
		std::cout << "Affer:Output node:"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case REG:
		// Tao cac output component
		std::cout << "Affer: REG node:"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case ALWAYS:
		std::cout<<"Affer: ALWAYS node:"<<node->GetTypeName() <<" : "<<node->GetName()<<std::endl; break;
	      case BLOCK:
		std::cout<<"Affer: BLOCK node:"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case BINARY_OPERATION:
		std:: cout<<"Affer: BINARY OPERATION node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case IF: 
		std:: cout<<"Affer: IF node :"<<node->GetTypeName()<<" : "<<node->GetName()<<std::endl; break;
	      case DELAY_CONTROL :;
		
	      }
	  }
	
	std::cout<<"Finished succesfully! "<<this->GetName()<<std::endl;
}
