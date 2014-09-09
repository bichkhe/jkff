
%{
/**
 * @file   Verilog.y
 * @author Minh D. Nguyen
 * @date   Wed Apr  4 09:14:17 2012
 * 
 * @brief  Verilog parser using C++ class. Modified version from Hu-Hsi Yeh
 * 
 * 
 */

/****************************************************************************
  FileName     [ vlpYacc.y ]
  Package      [ vlp ]
  Synopsis     [ Verilog parser ]
  Author       [ Hu-Hsi(Louis)Yeh ]
  Copyright    [ Copyleft(c) 2005 LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

//#include "VLGlobe.h"
//#include "vlpModule.h"
//#include "vlpCtrlNode.h"
//#include "vlpSubElement.h"
//#include "vlpDesign.h"
//#include "vlpItoStr.h"
//#include "vlpStack.h"
//#include "vlpDefine.h"
#include <string>
#include <stack>
#include <stdlib.h>
#include <iostream>
#include <set>
#include "VerilogParser.h"
#include "VerilogScanner.h"
#include "VerilogException.h"

using namespace std;
#undef yyparse
#define yyparse VerilogParser::yyparse
#undef yylval
#define yylval Veriloglval

//#define YYPARSE_PARAM param
//#define YYLEX_PARAM &yylval
//forward declare

//union YYSTYPE;
//extern int yylex(YYSTYPE*, void*);

//extern int yylex(YYSTYPE*);

// extern int yylex();

// void YYTRACE(string);
// extern void yyerror(char*);
// External Declarations
// extern LY_usage* LY;
// extern VlpDesign& VLDesign;
 extern VerilogParser* VP;

%}

/* YYSTYPE */
%union {
   int             	ival;
  string*        	stringPtr;
											 
   VerilogNode*      	designPtr;
   VerilogNode*      	modulePtr;
   VerilogNode* 	vlpIONodePtr;
   VerilogNode*		instancePtr;
   VerilogNode*    	basePtr;
   VerilogNode*   	paramPtr;
   VerilogNode*  	assignPtr;
   VerilogNode*  	alwaysPtr;
   VerilogNode*   	primitivePtr;
   VerilogNode*    	functionPtr;

};


/* starting symbol */
%start source_text

/* tokens */
%token <stringPtr> YYID           /* verilog user defined identifier */
%token <stringPtr> YYDEF_ID       /*`macro (Louis add)*/
%token <ival> YYINUMBER           /* integer */
%token <stringPtr> YYRNUMBER                 /* real */
%token <stringPtr>YYBIT_BASE_STRING         /* Ex : 2'b11, 2'hff....  add by louis*/
/*%token YYSTRING*/                  /* string quoted by "" */
/*%token YYALLPATH*/                 /* *> */
%token YYALWAYS                  /* always */
%token YYAND                     /* and */
%token YYASSIGN                  /* assign */
%token YYBEGIN                   /* begin */
%token YYBUF                     /* buf */
%token YYBUFIF0                  /* bufif0 */
%token YYBUFIF1                  /* bufif1 */
%token YYCASE                    /* case */
%token YYCASEX                   /* casex */
%token YYCASEZ                   /* casez */
/*%token YYCMOS*/                    /* cmos */
/*%token YYCONDITIONAL*/             /* ?: */
/*%token YYDEASSIGN*/                /* deassign */
%token YYDEFAULT                 /* default */
%token YYDEFPARAM                /* defparam */
/*%token YYDISABLE*/                 /* disable */
%token YYELSE                    /* else */
%token YYEDGE                    /* edge */
%token YYEND                     /* end */
%token YYENDCASE                 /* endcase */
%token YYENDMODULE               /* endmodule */
%token YYENDFUNCTION             /* endfunction */
/*%token YYENDPRIMITIVE*/            /* endprimitive */
/*%token YYENDSPECIFY*/              /* endspecify */
/*%token YYENDTABLE*/                /* endtable */
%token YYENDTASK                 /* endtask */
/*%token YYEVENT*/                   /* event */
%token YYFOR                     /* for */
/*%token YYFOREVER*/                 /* forever */
/*%token YYFORK*/                    /* fork */
%token YYFUNCTION                /* function */
%token YYGEQ                     /* >= */
%token YYHIGHZ0                  /* highz0 */
%token YYHIGHZ1                  /* highz1 */
%token YYIF                      /* if */
/*%token YYINITIAL*/                 /* initial */
%token YYINOUT                   /* inout */
%token YYINPUT                   /* input */
%token YYINTEGER                 /* integer */
/*%token YYJOIN*/                    /* join */
/*%token YYLARGE*/                   /* large */
/*%token YYLEADTO*/                  /* => */
%token YYLEQ                     /* =< */
%token YYLOGAND                  /* && */
%token YYCASEEQUALITY            /* === */
%token YYCASEINEQUALITY          /* !== */
%token YYLOGNAND                 /* ~& */
%token YYLOGNOR                  /* ~| */
%token YYLOGOR                   /* || */
%token YYLOGXNOR                 /* ~^ or ^~ */
%token YYLOGEQUALITY             /* == */
%token YYLOGINEQUALITY           /* != */
%token YYLSHIFT                  /* << */
/*%token YYMACROMODULE*/             /* macromodule */
/*%token YYMEDIUM*/                  /* medium */
%token <stringPtr> YYMODULE                  /* module */
/*%token YYMREG*/   	         /* mreg */
%token YYNAND                    /* nand */
%token YYNBASSIGN                /* <= non-blocking assignment */
%token YYNEGEDGE                 /* negedge */
/*%token YYNMOS*/                    /* nmos */
%token YYNOR                     /* nor */
%token YYNOT                     /* not */
/*%token YYNOTIF0*/                  /* notif0 */
/*%token YYNOTIF1*/                  /* notif1 */
%token YYOR                      /* or */
%token YYOUTPUT                  /* output */
%token YYPARAMETER               /* parameter */
/*%token YYPMOS*/                    /* pmos */
%token YYPOSEDGE                 /* posedge */
/*%token YYPRIMITIVE*/               /* primitive */
%token YYPULL0                   /* pull0 */
%token YYPULL1                   /* pull1 */
/*%token YYPULLUP*/                  /* pullup */
/*%token YYPULLDOWN*/                /* pulldown */
/*%token YYRCMOS*/                   /* rcmos */
/*%token YYREAL*/                    /* real */
%token YYREG                     /* reg */
/*%token YYREPEAT*/                  /* repeat */
/*%token YYRIGHTARROW*/              /* -> */
/*%token YYRNMOS*/                   /* rnmos */
/*%token YYRPMOS*/                   /* rpmos */
%token YYRSHIFT                  /* >> */
/*%token YYRTRAN*/                   /* rtran */
/*%token YYRTRANIF0*/                /* rtranif0 */
/*%token YYRTRANIF1*/                /* rtranif1 */
/*%token YYSCALARED*/                /* scalared */
/*%token YYSMALL*/                   /* small */
/*%token YYSPECIFY*/                 /* specify */
/*%token YYSPECPARAM*/               /* secparam */
%token YYSTRONG0                 /* strong0 */
%token YYSTRONG1                 /* strong1 */
%token YYSUPPLY0                 /* supply0 */
%token YYSUPPLY1                 /* supply1 */
%token YYSWIRE                   /* swire */
/*%token YYTABLE*/                   /* table */
%token YYTASK                    /* task */
/*%token YYTIME*/                    /* time */
/*%token YYTRAN*/                    /* tran */
/*%token YYTRANIF0*/                 /* tranif0 */
/*%token YYTRANIF1*/                 /* tranif1 */
%token YYTRI                     /* tri */
%token YYTRI0                    /* tri0 */
%token YYTRI1                    /* tri1 */
%token YYTRIAND                  /* triand */
%token YYTRIOR                   /* trior */
/*%token YYTRIREG*/                  /* trireg */
/*%token YYVECTORED*/                /* vectored */
/*%token YYWAIT*/                    /* wait */
%token YYWAND                    /* wand */
%token YYWEAK0                   /* weak0 */
%token YYWEAK1                   /* weak1 */
/*%token YYWHILE*/                   /* while */
%token YYWIRE                    /* wire */
%token YYWOR                     /* wor */
%token YYXNOR                    /* xnor */
%token YYXOR                     /* xor */
/*%token YYsysSETUP*/                /* $setup */
/*%token YYsysID*/                   /* $... */
%token YYDEFINE                  /*`define (add by Louis)*/
%token YYDEF_NULL                /*`define null*/
%token PARALLEL_CASE 
%token FULL_CASE   

//%right YYCONDITIONAL
%right '?' ':'
%left YYOR
%left YYLOGOR
%left YYLOGAND
%left '|'
%left '^' YYLOGXNOR
%left '&'
%left YYLOGEQUALITY YYLOGINEQUALITY YYCASEEQUALITY YYCASEINEQUALITY
%left '<' YYLEQ '>' YYGEQ YYNBASSIGN
%left YYLSHIFT YYRSHIFT
%left '+' '-'
//%left '*' '/' '%'
%left '*'
%right '~' '!' YYUNARYOPERATOR

//%type <A> source_text
%type <modulePtr> description
%type <modulePtr> module
//%type <A> primitive
%type <basePtr> port_list_opt port_list
//%type <vlpIONodePtr> port
%type <basePtr> port
%type <basePtr> port_expression_opt port_expression
 //%type <VerilogNode*> port_ref_list
%type <basePtr> port_reference
 //%type <VerilogNode*> port_reference_arg
%type <basePtr> module_item
%type <basePtr> module_item_clr
%type <paramPtr> parameter_declaration
%type <basePtr> input_declaration output_declaration //inout_declaration
%type <basePtr> reg_declaration
%type <basePtr> net_declaration
//%type <A> time_declaration event_declaration
%type <basePtr> integer_declaration /*real_declaration*/
%type <primitivePtr> gate_instantiation
//%type <A> module_or_primitive_instantiation
%type <paramPtr> parameter_override
%type <assignPtr> continuous_assign
%type <alwaysPtr> /*initial_statement*/ always_statement
%type <basePtr> task
//%type <functionPtr> function
%type <basePtr> variable_list //primitive_declaration_eclr
//%type <A> table_definition
//%type <A> table_entries combinational_entry_eclr sequential_entry_eclr
//%type <A> combinational_entry sequential_entry
//%type <A> input_list level_symbol_or_edge_eclr
//%type <A> output_symbol state next_state 
//%type <A> level_symbol edge level_symbol_or_edge edge_symbol
//%type <A> primitive_declaration
//%type <A> tf_declaration_clr tf_declaration_eclr
%type <basePtr> statement_opt
//%type <A> range_or_type_opt range_or_type
%type <basePtr> range
//%type <A> tf_declaration
%type <basePtr> assignment_list
%type <basePtr> range_opt
%type <basePtr> expression
//%type <A> drive_strength_opt drive_strength 
//%type <A> charge_strength_opt charge_strength
%type <basePtr> nettype
//%type <A> expandrange_opt expandrange
//%type <A> delay_opt delay
%type <basePtr> register_variable_list
//%type <A> name_of_event_list
%type <basePtr> identifier
%type <basePtr> register_variable
%type <basePtr> name_of_register
//%type <A> name_of_event
%type <ival> strength0 strength1
%type <basePtr> assignment
%type <primitivePtr> gate_instance_list //drive_delay_clr
%type <primitivePtr> gatetype //drive_delay
%type <primitivePtr> gate_instance
%type <primitivePtr> terminal_list
%type <basePtr> name_of_gate_instance name_of_module_or_primitive
%type <basePtr> terminal
//%type <A> module_or_primitive_option_clr
//%type <A> module_or_primitive_option
//%type <A> module_or_primitive_instance_list
//%type <A> delay_or_parameter_value_assignment
%type <instancePtr> module_or_primitive_instance
%type <instancePtr> module_connection_list module_port_connection_list
%type <instancePtr> named_port_connection_list
%type <basePtr> module_port_connection named_port_connection
%type <basePtr> statement
%type <basePtr> statement_clr case_item_eclr
%type <basePtr> case_item
%type <basePtr> delay_control
%type <basePtr> event_control
%type <basePtr> lvalue
%type <basePtr> expression_list
%type <basePtr> seq_block
//%type <A> par_block
%type <basePtr> name_of_block          //dummy
%type <basePtr> block_declaration_clr  //dummy
//%type <A> block_declaration
%type <basePtr> task_enable
%type <basePtr> concatenation multiple_concatenation
//%type <A> mintypmax_expression_list
%type <basePtr> mintypmax_expression
%type <basePtr> primary
%type <basePtr> function_call
%type <basePtr> event_expression ored_event_expression
%type <basePtr> target_statement
%type <basePtr> bitExpression
%type <basePtr> bit_exp
%type <basePtr> connect_port
%type <basePtr> synopsys_directive

%%

/* F.1 Source Text */

source_text
        :
          {
             YYTRACE("sorce_text:");
          }
        | source_text description
          {
             YYTRACE("source_text: source_text description");
           
          }
        ;

description 
	: module
          {
             YYTRACE("description: module");
            
          }
/*| define
          {
             YYTRACE("description: define");
    
          }
	| primitive
          {
             YYTRACE("description: primitive");
          }*/
	;


/*define                                           //new rule (added by Louis) 
        : YYDEFINE { (state) = DEFINE; } YYID//can't use identifier instead of YYID,
                                                 //it will has a strange bug : the point of identifer
                                                 //will be modify to the next YYID token. I still don't know
                                                 //the reason, but use YYID is ok.
          { 
                   YYTRACE("define: YYDEFINE YYID target_statement");
            
          }
           target_statement
          {
             
             state = S_NULL;
          }
        ;*/

target_statement  //new rule 
        : expression
        {
           YYTRACE("target_statement: expression");
        }
        | expression ':' expression
        {
           YYTRACE("target_statement: expression : expression");
        }
        | YYDEF_NULL
        {
           YYTRACE("target_statement: YYDEF_NULL");
        }
        ;
module 
: YYMODULE YYID 
  	{
  		VP->currentModulePtr = mFactory->MakeModule(*$2);
	
  	}
	port_list_opt ';' module_item_clr YYENDMODULE
         {
           	YYTRACE("module: YYMODULE YYID port_list_opt ';' module_item_clr YYENDMODULE");
	   	cout<<"Make ModuleNode\n";
	   	$$ = VP->currentModulePtr;
		$$-> AddChild($4);
		$$-> AddChild($6);
         }
	;

port_list_opt               
	:
          /*{
             YYTRACE("port_list_opt:");
          }
	|*/ '(' port_list ')'
          {
             YYTRACE("port_list_opt: '(' port_list ')'");
		$$ = $2;
          }        
	/*| '(' io_declaration_list ')'//louis add
          {
             YYTRACE("port_list_opt: '(' io_declaration_list ')'");
          }*/
	;

port_list                      
	: port
          {
             YYTRACE("port_list: port");
		cout<<"Make Port List\n";
		$$ = mFactory->MakePortList();
		$$->AddChild($1);
          }
	| port_list ',' port
          {
             YYTRACE("port_list: port_list ',' port");
		$$->AddChild($3);
          }
	;

port                           
	: port_expression_opt
          {
             YYTRACE("port: port_expression_opt");
		$$ =$1;
          }
		
	;

port_expression_opt            
	:
           {
              YYTRACE("port_expression_opt:");
               $$ = NULL;
           }
	|  port_expression
           {
              YYTRACE("port_expression_opt: port_expression");
		$$ = $1;
           }
	;

port_expression                
	: port_reference
          {
             YYTRACE("port_expression: port_reference");
           	$$ = $1;
          }

        ;
/*
port_ref_list
	: port_reference
          {
             YYTRACE("port_ref_list: port_reference");
          }
	| port_ref_list ',' port_reference
          {
             YYTRACE("port_ref_list: port_ref_list ',' port_reference");
          }
	;
*/
port_reference
	: YYID 
          {
		cout<<"Make Port\n";
            	$$ = mFactory->MakeIdentifier(*$1);
	  }
          /*port_reference_arg
          {
             YYTRACE("port_reference: YYID port_reference_arg");
		
          }*/
	;

/*port_reference_arg
        :
          {
             YYTRACE("port_reference_arg:");             
          }
        | '[' expression ']' 
	{
             YYTRACE("port_reference_arg: '[' expression ']'");
             
          }
        | '[' expression ':' expression ']'
          {
             YYTRACE("port_reference_arg: '[' expression ':' expression ']'");
            
          }
        ;*/
io_declaration_list 
        : io_declaration
          {
          }
	| io_declaration_list ',' io_declaration
          {
          }
        ;

io_declaration   /*louis new add @ 07/01/16*/
        : YYINPUT range_opt identifier
          {
             YYTRACE("io_declaration: YYINPUT range_opt identifier");
             
          }
        | YYOUTPUT range_opt identifier
          {
             YYTRACE("io_declaration: YYOUTPUT range_opt identifier");
             
          }
        | YYINOUT range_opt identifier
          {
             YYTRACE("io_declaration: YYINOUT range_opt identifier");
            
          }
        ;

module_item_clr                          
        :
	
          {
             YYTRACE("module_item_clr:");
		$$=mFactory->MakeModuleItem();
          }
        | module_item_clr module_item
          {
             YYTRACE("module_item_clr: module_item_clr module_item");
		$$->AddChild($2);
          }
        ;

module_item  /*only using in module descripation*/
	: parameter_declaration            
          {
             YYTRACE("module_item: parameter_declaration");
		$$ = $1;
          }
	| input_declaration                 
          {
             YYTRACE("module_item: input_declaration");
		
		$$ = $1;
          }
	| output_declaration                
          {
             YYTRACE("module_item: output_declaration");
		$$ = $1;
          }
	| inout_declaration                 
          {
             YYTRACE("module_item: inout_declaration");
          }
	| net_declaration                   //special case will be linked in dataflow
          {
             YYTRACE("module_item: net_declaration");
            	$$ = $1;
          }
	| reg_declaration                 
          {
             YYTRACE("module_item: reg_declaration");
		$$ = $1;
          }
/*	| time_declaration
          {
             YYTRACE("module_item: time_declaration");
          }*/
	| integer_declaration             
          {
             YYTRACE("module_item: integer_declaration");
          }
/*	| real_declaration
          {
             YYTRACE("module_item: real_declaration");
             LY->modulePtr -> setDataFlow($1);
          }*/
/*	| event_declaration
          {
             YYTRACE("module_item: event_declaration");
          }*/
	| gate_instantiation                           
          {
             YYTRACE("module_item: gate_instantiation");
		$$=$1;
          }
	| module_or_primitive_instantiation            
          {
             YYTRACE("module_item: module_or_primitive_instantiation");
          }
	| parameter_override                             
          {
             YYTRACE("module_item: parameter_override");
          }
	| continuous_assign                                //link in dataflow
          {
             YYTRACE("module_item: continous_assign");
		$$=$1;
          }
/*	| specify_block
          {
             YYTRACE("module_item: specify_block");
          }
	| initial_statement
          {
             YYTRACE("module_item: initial_statement");
          }*/
	| always_statement                                 //link in dataflow
          {
             YYTRACE("module_item: always_statement");
             $$ = $1;
          }
	| task
          {
             YYTRACE("module_item: task");
          }
	| function
          {
             YYTRACE("module_item: function");
          }
/* | define//Louis add
          {
             YYTRACE("description: define");
            
          }*/
	;
task
	: YYTASK YYID  
          {
             scopeState = TASK;
	          
					}
          ';' tf_declaration_clr statement_opt 
          YYENDTASK
          {
             YYTRACE("YYTASK YYID ';' tf_declaration_clr statement_opt YYENDTASK");
             
             scopeState = MODULE;
             
          }
	;

function
        : YYFUNCTION range_or_type_opt YYID 
          {
	          
             scopeState = FUNCTION;
           
	  }
          ';' tf_declaration_eclr statement_opt
          YYENDFUNCTION
          {
             YYTRACE("YYFUNCTION range_or_type_opt YYID ';' tf_declaration_eclr statement_opt YYENDFUNCTION");
           
             scopeState = MODULE;
            
          }
        ;

range_or_type_opt     /*used in function description*/
        :
          {
             YYTRACE("range_or_type_opt:");
            
          }
        | range_or_type
          {
             YYTRACE("range_or_type_opt: range_or_type");
          }
        ;

range_or_type         /*used in function description*/
        : range
          {
             YYTRACE("range_or_type: range");
             isInteger = false;
          }
        | YYINTEGER
          {
             YYTRACE("range_or_type: YYINTEGER");
             
             isInteger = true;
          }
/*        | YYREAL
          {
             YYTRACE("range_or_type: YYREAL");
          }*/
        ;

tf_declaration_clr/*using in task description*/
        :
          {
             YYTRACE("tf_declaration_clr:");
          }
        | tf_declaration_clr tf_declaration
          {
             YYTRACE("tf_declaration_clr: tf_declaration_clr tf_declaration");
          }
        ;

tf_declaration_eclr/*using in function description*/
        : tf_declaration
          {
             YYTRACE("tf_declaration_eclr: tf_declaration");
          }
        | tf_declaration_eclr tf_declaration
          {
             YYTRACE("tf_declaration_eclr: tf_decalration_eclr tf_declaration");
          }
        ;

tf_declaration/*using in task and function description in the above rules*/
        : parameter_declaration
          {
             YYTRACE("tf_declaration: parameter_decalration");
          }
        | input_declaration
          {
             YYTRACE("tf_declaration: input_declaration");
          }
        | output_declaration
          {
             YYTRACE("tf_declaration: output_declaration");
             
             if (scopeState == FUNCTION) {
                  }     
          }
        | inout_declaration
          {
             YYTRACE("tf_declaration: inout_declaration");
            
             if (scopeState == FUNCTION) {
            
             }                
          }
        | reg_declaration
          {
             YYTRACE("tf_declaration: reg_declaration");
             //local variables
          }
/*      | time_declaration
          {
             YYTRACE("tf_declaration: time_declaration");
          }*/
        | integer_declaration
          {
             YYTRACE("tf_declaration: integer_declaration");
          }
/*      | real_declaration
          {
             YYTRACE("tf_declaration: real_declaration");
          }*/
/*      | event_declaration
          {
             YYTRACE("tf_declaration: event_declaration");
          }*/
        ;

/* F.2 Declarations */

parameter_declaration /*using in module, task, and function descripation*/
        : YYPARAMETER range_opt { state = PARAM; } assignment_list ';'//range_opt is dummy! useless!!
          {                                                           //ignore the syntax "range_opt"
             YYTRACE("parameter_declaration: YYPARAMETER assignment_list ';'");
            
             state = S_NULL;
		$$ = mFactory->MakeVarDeclareList();
		$$->SetName("PARAMETER");
		$$->AddChild($4);
		if($2!=NULL)
		{
			$$->AddChild($2->GetChildrenNode()[0]);
			$$->AddChild($2->GetChildrenNode()[1]);
			delete $2;
		}
          }
        ;

/* ------------Tao bo cong n bit---------------
 * author: Quandvk54
 * date: 27-04
 * description: replace range_opt by '[' expression ':' expression ']'
 */
input_declaration
        : YYINPUT range_opt 
          {
             state = IO;
          }
          variable_list ';'
          {
             YYTRACE("input_declaration: YYINPUT range_opt variable_list ';'");
            
             state = S_NULL;
		$$ = $4;
		$$->SetName("INPUT");
		if($2!=NULL)
		{
			$$->AddChild($2->GetChildrenNode()[0]);
			$$->AddChild($2->GetChildrenNode()[1]);
			delete $2;
		}
		
          }
/*	| YYINPUT
          {
             state = IO;
          }
          variable_list ';'
          {
             YYTRACE("input_declaration: YYINPUT range_opt variable_list ';'");
            
             state = S_NULL;
		$$ = $3;
		$3->SetName("INPUT");
          }*/
        ;


output_declaration
        : YYOUTPUT range_opt
          {
             state = IO;
            
          }
          variable_list ';'
          {
             YYTRACE("output_declaration: YYOUTPUT range_opt variable_list ';'");
             state = S_NULL;
		$$=$4;
		$$->SetName("OUTPUT");
		if($2!=NULL)
		{
			$$->AddChild($2->GetChildrenNode()[0]);
			$$->AddChild($2->GetChildrenNode()[1]);
			delete $2;
		}
          }
	/*| YYOUTPUT
          {
             state = IO;
            
          }
          variable_list ';'
          {
             YYTRACE("output_declaration: YYOUTPUT range_opt variable_list ';'");
             
             state = S_NULL;
		$$ = $3;
		$$->SetName("OUTPUT");
          }*/
        ;

inout_declaration
        : YYINOUT range_opt 
          {
             state = IO;
            
          }
          variable_list ';'
          {
             YYTRACE("inout_declaration: YYINOUT range_opt variable_list ';'");
             state = S_NULL;
          }
        ;

net_declaration
        : nettype /*drive_strength_opt expandrange_opt delay_opt*/ assignment_list ';'//link in dataflow under 
          {                                                                           //the condition
             YYTRACE("net_declaration: nettype drive_strength_opt expandrange_opt delay_opt assignment_list ';'");
             	$$ = mFactory->MakeVarDeclareList();
		$$->SetName("WIRE");
		$$->AddChild($2);
             state = S_NULL;
             
          }
        | nettype /*drive_strength_opt expandrange_opt /*delay_opt*/ variable_list ';'
          {
             YYTRACE("net_declaration: nettype drive_strength_opt expandrange_opt delay_opt variable_list ';'");
                state = S_NULL;
             	$$ = $2;
		$$->SetName("WIRE");
          }
/*      | YYTRIREG charge_strength_opt expandrange_opt delay_opt 
            variable_list ';'
          {
             YYTRACE("net_declaration: YYTRIREG charge_strength_opt expandrange_opt delay_opt variable_list ';'");
          }*/
        ;

nettype
        : YYSWIRE
          {
             YYTRACE("nettype: YYSWIRE");
              state = NET;
          }
        | YYWIRE
          {
             YYTRACE("nettype: YYWIRE");
             state = NET;
		//$$ = mFactory->MakeVarDeclareList();
		//$$->SetName("WIRE");
		$$ = NULL;
          }
        | YYTRI
          {
             YYTRACE("nettype: YYTRI");
              state = NET;
          }
        | YYTRI1
          {
             YYTRACE("nettype: YYTRI1");
             
             state = NET;
          }
        | YYSUPPLY0
          {
             YYTRACE("nettype: YYSUPPLY0");
            
             state = NET;
          }
        | YYWAND
	  {
             YYTRACE("nettype: YYWAND");
             
             state = NET;
	  }
        | YYTRIAND
          {
	     YYTRACE("nettype: YYTRIAND");
             
             state = NET;
	  }
        | YYTRI0
          {
	     YYTRACE("nettype: YYTRI0");
             
             state = NET;
	  }
        | YYSUPPLY1
          {
	     YYTRACE("nettype: YYSUPPLY1");
           
             state = NET;
	  } 
        | YYWOR
          {
             YYTRACE("nettype: YYWOR");
             
             state = NET;
          }
        | YYTRIOR
          {
             YYTRACE("nettype: YYTRIOR");
            
             state = NET;
          }
       ;

/*
 * it's still not clear difference between <range>, SCALAREd <range>, and
 * VECTORED <range>. All of them are treated as <range> now. 10/8/92
 */
expandrange_opt
        :
          {
             YYTRACE("expandrange_opt:");
          }
        | expandrange
          {
             YYTRACE("expandrange_opt: expandrange");
          }
        ;

expandrange
        : range
          {
             YYTRACE("expandrange: range");
          }
/*      | YYSCALARED range
          {
             YYTRACE("expandrange: YYSCALARED range");
          }
        | YYVECTORED range
          {
             YYTRACE("expandrange: YYVECTORED range");
          }*/
        ;

reg_declaration
        : YYREG range_opt 
          {
             state = REG; 
             
          }
          register_variable_list ';'
          {
             YYTRACE("reg_declaration: YYREG range_opt register_variable_list ';'");
             
             state = S_NULL;
		$$ = $4;
		$$->SetName("REG");
		if($2!=NULL)
		{
			$$->AddChild($2->GetChildrenNode()[0]);
			$$->AddChild($2->GetChildrenNode()[1]);
			delete $2;
		}
          }
/*      | YYMREG range_opt register_variable_list ';'
          {
             YYTRACE("reg_declaration: YYMREG range_opt register_variable_list ';'");
          }*/
        ;
/*
time_declaration
        : YYTIME register_variable_list ';'
          {
             YYTRACE("time_declaration: YYTIME register_variable_list ';'");
          }
        ;*/

integer_declaration
        : YYINTEGER 
          {
             state = INT;
          }
          register_variable_list ';'
          {
             YYTRACE("integer_declaration: YYINTEGER register_variable_list ';'");
             
             state = S_NULL;
          }
        ;
/*
real_declaration
        : YYREAL variable_list ';'
          {
             YYTRACE("real_declaration: YYREAL variable_list ';'");
          }
        ;*/
/*
event_declaration
        : YYEVENT name_of_event_list ';'
          {
             YYTRACE("event_declaration: YYEVENT name_of_event_list ';'");
          }
        ;
*/
continuous_assign              
        : YYASSIGN { state = ASSIGN; }/*drive_strength_opt delay_opt*/ 

	  assignment_list ';'
          {
             YYTRACE("continuous_assign: YYASSIGN drive_strength_opt delay_opt assignment_list ';'");
             
             state = S_NULL;
		$$=mFactory->MakeAssign();
		$$->AddChild($3);
          }
        ;
//====================================still need to modify====================================//
parameter_override
        : YYDEFPARAM { (state) = PARAM_NOL; } assignment_list ';'//use parameter node
          {
             YYTRACE("parameter_override: YYDEFPARAM assign_list ';'");
             (state) = S_NULL;         
          }
        ;
//=============================================================================================//
variable_list //for "input, output, inout, nettype, trireg, real" usage
        : identifier
          {
             YYTRACE("variable_list: identifier");
		$$=mFactory->MakeVarDeclareList();
		$$->AddChild($1);
           
          }
        | variable_list ',' identifier
          {
             YYTRACE("variable_list: variable_list ',' identifier");
           	$$->AddChild($3);
          
	}
        ;

register_variable_list    //use in reg and integer declaration
        : register_variable
          {
             YYTRACE("register_variable_list: register_variable");
		//$$ = mFactory->MakeVarDeclareList();
		//$$->AddChild($1);
		$$ = $1;
          }
        | register_variable_list ',' register_variable
          {
             YYTRACE("register_variable_list: register_variable_list ',' register_variable");
		$$->AddChild($3);
          }
        ;
        
register_variable
        : name_of_register
          {
             YYTRACE("register_variable: name_of_register");
		$$ = mFactory->MakeVarDeclareList();
     		$$->AddChild($1);
          }
        | name_of_register '[' expression ':' expression ']'//Arrays  Ex:  reg  [7:0]Memory[0:1023]                     //need to test
          {                                                 //ref. 5-11 in Verilog book
             YYTRACE("register_variable: name_of_register '[' expression ':' expression ']'");
		$$ = mFactory->MakeVarDeclareList();
		$$->AddChild($3);
		$$->AddChild($5);
          	//$$ = NULL;
          }
        | name_of_register '[' YYDEF_ID ']' // Louis adds the rule used in mocro definite.
          {
             YYTRACE("register_variable: name_of_register '[' YYDEF_ID ']'");
		//$$ = mFactory->MakeVarDeclareList();
		//$$->AddChild($3);
		$$ = NULL;
          }
        ;

name_of_register
        : YYID
          {
             YYTRACE("name_of_register: YYID");   
        	$$ = mFactory->MakeIdentifier(*$1);
          }
        ;
/*
name_of_event_list
        : name_of_event
          {
             YYTRACE("name_of_event_list: name_of_event");
          }
        | name_of_event_list ',' name_of_event
          {
             YYTRACE("name_of_event_list: name_of_event_list ',' name_of_event");
          }
        ;

name_of_event
        : YYID
          {
             YYTRACE("name_of_event: YYID");
          }
        ;
*/
/*
charge_strength_opt   //SUPPLY??   //use only in "trireg"
        :
          {
             YYTRACE("charge_strength_opt:");
          }
        | charge_strength //use only in "trireg"
          {
             YYTRACE("charge_strength_opt: charge_strength");
          }
        ;

charge_strength      //SUPPLY??   //use only in "trireg"
        : '(' YYSMALL ')'
          {
             YYTRACE("charge_strength: '(' YYSMALL ')'");
          }
        | '(' YYMEDIUM ')'
          {
             YYTRACE("charge_strength: '(' YYMEDIUM ')'");
          }
        | '(' YYLARGE ')'
          {
             YYTRACE("charge_strength: '(' YYLARGE ')'");
          }
        ;
*/
drive_strength_opt  
        :
          {
             YYTRACE("drive_strength_opt:");
	     // $$=NULL;
          }
        | drive_strength
          {
             YYTRACE("drive_strength_opt: drive_strength");
          }
        ;

drive_strength     
        : '(' strength0 ',' strength1 ')'
          {
             YYTRACE("drive_strength: '(' strength0 ',' strength1 ')'");
                          
          }
        | '(' strength1 ',' strength0 ')'
          {
             YYTRACE("drive_strength: '(' strength1 ',' strength0 ')'");
                     
          }
        ;

strength0    
        : YYSUPPLY0
          {
             YYTRACE("strength0: YYSUPPLY0");
             
          }
        | YYSTRONG0
          {
             YYTRACE("strength0: YYSTRONG0");
            
          }
        | YYPULL0
          {
             YYTRACE("strength0: YYPULL0");
          
          }
        | YYWEAK0
          {
           YYTRACE("strength0: YYWEAK0");
          
          }
        | YYHIGHZ0
          {
             YYTRACE("strength0: YYHIGHZ0");
            
          }
        ;

strength1   
        : YYSUPPLY1
          {
             YYTRACE("strength1: YYSUPPLY1");
            
          }
        | YYSTRONG1
          {
             YYTRACE("strength1: YYSTRONG1");
           
          }
        | YYPULL1
          {
             YYTRACE("strength1: YYPULL1");
          
          }
        | YYWEAK1
          {
             YYTRACE("strength1: YYWEAK1");
            
          }
        | YYHIGHZ1
          {
             YYTRACE("strength1: YYHIGHZ1");
          
          }
        ;

range_opt//used in "input" "output" "inout" "reg"
        :
          {
             YYTRACE("range_opt: abacsdafa");
            	$$=NULL;
          }
        | range
          {
             YYTRACE("range_opt: range");
	     	$$ = $1;
          }
        ;

range    //range_opt(input, output, inout, reg), range_or_type(function), expandrange(nettype)   
        : '[' expression ':' expression ']'
          {
             YYTRACE("range: '[' expression ':' expression ']'");
		$$ = mFactory->MakeRange();
	     	$$->AddChild($2);
	     	$$->AddChild($4);
          }
        | '[' YYDEF_ID ']'
          {
             YYTRACE("range: '[' YYDEF_ID ']'");
		$$ = NULL;
          }
        ;

//assignment_list using in 
//    1. parameter(parameter_declaration)
//    2. nettype(net_declaration)(swire wire wand wor tri tri0 tri1 triand trior supply0 supply1)
//    3. assign(continuous_assign)
//    4. defparam(parameter_override)
assignment_list  
        : assignment
          {//linking
             YYTRACE("assignment_list: assignment");
             $$=$1;             
          }
        | assignment_list ',' assignment
          {
             YYTRACE("assignment_list: assignment_list ',' assignment");
		$$->AddChild($3);
          }
        ;

/* F.3 Primitive Instances */

gate_instantiation
        : gatetype /*drive_delay_clr*/ gate_instance_list ';'
          {
             YYTRACE("gate_instantiation: gatetype drive_delay_clr gate_instance_list ';'");
		$$=$2;
            
          }
        ;
/*
drive_delay_clr
        :
          {
             YYTRACE("drive_delay_clr:");
          }
        | drive_delay_clr drive_delay
          {
             YYTRACE("drive_delay_clr: drive_delay_clr drive_delay");
          }
        ;*/
/*
drive_delay
        : drive_strength
          {
             YYTRACE("drive_delay: drive_strength");
          }
        | delay
          {
             YYTRACE("drive_delay: delay");*/
	      /* to save space and encode/decode effort */
              /* we use lsb as an indicator whether drive_delay */
	      /* is drive (lsb==0) or delay (lsb==1) */
//        }
//      ;

gatetype
        : YYAND
          {
	     YYTRACE("gatetype: YYAND");
             // LY->gateType = 1;
		$$=NULL;
	  }
        | YYNAND
          {
	     YYTRACE("gatetype: YYNAND");
           //  LY->gateType = 2;
	  }
        | YYOR
          {
	     YYTRACE("gatetype: YYOR");
             // LY->gateType = 3;
	  }
        | YYNOR
          {
             YYTRACE("gatetype: YYNOR");
          //   LY->gateType = 4;
	  }
        | YYXOR
          {
	     YYTRACE("gatetype: YYXOR");
           //  LY->gateType = 5;
		$$=NULL;
	  }
        | YYXNOR
          {
	     YYTRACE("gatetype: YYXNOR");
            // LY->gateType = 6;
	  }
        | YYBUF
          {
	     YYTRACE("gatetype: YYBUF");
             // LY->gateType = 7;
	  }
        | YYBUFIF0
          {
             YYTRACE("gatetype: YYBIFIF0");
          //  LY->gateType = 8;
	  }
        | YYBUFIF1
          {
	     YYTRACE("gatetype: YYBIFIF1");
            
	  }
        | YYNOT
          {
	     YYTRACE("gatetype: YYNOT");
            // LY->gateType = 10;
	  }
/*      | YYNOTIF0
          {
	     YYTRACE("gatetype: YYNOTIF0");
	  }
        | YYNOTIF1
          {
	     YYTRACE("gatetype: YYNOTIF1");
	  }
        | YYPULLDOWN
          {
             YYTRACE("gatetype: YYPULLDOWN");
	  }
        | YYPULLUP
          {
	     YYTRACE("gatetype: YYPULLUP");
	  }
        | YYNMOS
          {
	     YYTRACE("gatetype: YYNMOS");
	  }
        | YYPMOS
          {
             YYTRACE("gatetype: YYPMOS");
	  }
        | YYRNMOS
          {
	     YYTRACE("gatetype: YYRNMOS");
	  }
        | YYRPMOS
          {
	     YYTRACE("gatetype: YYRPMOS");
	  }
        | YYCMOS
          {
             YYTRACE("gatetype: YYCMOS");
	  }
        | YYRCMOS
          {
	     YYTRACE("gatetype: YYRCMOS");
	  }
        | YYTRAN
          {
	     YYTRACE("gatetype: YYTRAN");
	  }
        | YYRTRAN
          {
             YYTRACE("gatetype: YYRTRAN");
	  }
        | YYTRANIF0
          {
	     YYTRACE("gatetype: YYTRANIF0");
	  }
        | YYRTRANIF0
          {
	     YYTRACE("gatetype: YYRTRANIF0");
	  }
        | YYTRANIF1
          {
	     YYTRACE("gatetype: YYTRANIF1");
	  }
        | YYRTRANIF1
          {
	     YYTRACE("gatetype: YYRTRANIF1");
	  }*/
        ;

gate_instance_list
        : gate_instance
          {
             YYTRACE("gate_instance_list: gate_instance");
		$$=mFactory->MakeGate();
		$$->AddChild($1);  
          }
        | gate_instance_list ',' gate_instance
          {
             YYTRACE("gate_instance_list: gate_instance_list ',' gate_instance");
                $$->AddChild($3);
          }
        ;

gate_instance
        : '(' terminal_list ')'//omit gate name
          {
             YYTRACE("gate_instance: '(' terminal_list ')'");
            	$$=$2;
          }
        | name_of_gate_instance '(' terminal_list ')'
          {
             YYTRACE("gate_instance: name_of_gate_instance '(' terminal_list ')'");
		$$=$3;
		$$->AddChild($1);
          }
        ;

name_of_gate_instance
        : YYID
          {
             YYTRACE("name_of_gate_instance: YYID");
             $$=mFactory->MakeIdentifier(*$1);
          }
        ;

terminal_list
        : terminal
          {
             YYTRACE("terminal_list: terminal");
		$$=mFactory->MakeGateInstance();
		$$->AddChild($1);
           
          }
        | terminal_list ',' terminal
          {
             YYTRACE("terminal_list: terminal_list ',' terminal");
		$$->AddChild($3);
            
          }
        ;

terminal
        : expression
          {
             YYTRACE("terminal: expression");
           	$$=$1;
          }
        ;

/* F.4 Module Instantiations */

module_or_primitive_instantiation
        : name_of_module_or_primitive module_or_primitive_option_clr
             module_or_primitive_instance_list ';' /*delay and drive strength don't supply*/
          {
             YYTRACE("module_or_primitive_instantiation: name_of_module_or_primitive module_or_primitive_option_clr module_or_primitive_instance_list ';'");
           
          }
        ;

name_of_module_or_primitive
        : YYID
          {
             YYTRACE("name_of_module_or_primitive: YYID");
             
          }
        | YYDEF_ID
          {
             YYTRACE("name_of_module_or_primitive: YYDEF_ID");
		
          }
        ;

//==========================================still not complete========================================// 

module_or_primitive_option_clr
        :
          {
             YYTRACE("module_or_primitive_option_clr:");
          }
        | module_or_primitive_option_clr module_or_primitive_option
          {
             YYTRACE("module_or_primitive_option_clr: module_or_primitive_option_clr module_or_primitive_option");
          }

        ;

module_or_primitive_option // only support parameter, no support drive_strength and delay
/*        : drive_strength
          {
             YYTRACE("module_or_primitive_option:");
          }*/
        : delay_or_parameter_value_assignment // only support parameter
          {
             YYTRACE("module_or_primitive_option: delay");
          }
        ;

delay_or_parameter_value_assignment
        : '#' YYINUMBER    // delay 
          {
	     YYTRACE("delay_or_parameter_value_assignment: '#' YYINUMBER");
             //ignore!!
	  }
        | '#' YYRNUMBER    // delay 
          {
	     YYTRACE("delay_or_parameter_value_assignment: '#' YYRNUMBER");
             //ignore!!
	  }
        | '#' identifier   // delay 
          {
	     YYTRACE("delay_or_parameter_value_assignment: '#' identifier");
             //ignore!!
	  }
        | '#' '(' mintypmax_expression_list ')' // delay | parameter_assign 
          {
	     YYTRACE("delay_or_parameter_value_assignment: '#' '(' mintypmax_expression_list ')'");
	  }
        ;

//========================================================================================================// 
module_or_primitive_instance_list
        : module_or_primitive_instance
          {
             YYTRACE("module_or_primitive_instance_list: module_or_primitive_instance");
		
          }
        | module_or_primitive_instance_list ',' module_or_primitive_instance
          {
             YYTRACE("module_or_primitive_instance_list: module_or_primitive_instance_list ',' module_or_primitive_instance");
            
          }
        ;

/* terminal_list in primitive_instance ca be derived from 
 * module_connection -> module_port ->expression
 */
module_or_primitive_instance
        : '(' module_connection_list ')'
          {
             YYTRACE("module_or_primitive_instance: '(' module_connection_list ')'");
        
          }
        | identifier {  } '(' module_connection_list ')'
          {
             YYTRACE("module_or_primitive_instance: '(' module_connection_list ')'");
          
          }
        ;

module_connection_list
        : module_port_connection_list
          {
             YYTRACE("module_connection_list: module_port_connection_list");
            
          }
        | named_port_connection_list
          {
             YYTRACE("module_connection_list: named_port_connection_list");
             
          }
        ;

module_port_connection_list
        : module_port_connection
          {
             YYTRACE("module_port_connection_list: module_port_connection");
                        
          }
        | module_port_connection_list ',' module_port_connection
          {
             YYTRACE("module_port_connection_list: module_port_connection_list ',' module_port_connection");
             
          }
        ;

named_port_connection_list
        : named_port_connection
          {
             YYTRACE("named_port_connection_list: named_port_connection");
	
          }
        | named_port_connection_list ',' named_port_connection
          {
             YYTRACE("named_port_connection_list: named_port_connection_list ',' name_port_connection");
          
          }
        ;

module_port_connection
        :
          {
             YYTRACE("module_port_connection:");
           
          }
        | expression
          {
             YYTRACE("module_port_connection: expression");
            
          }
        ;

named_port_connection
        : '.' identifier { } '(' connect_port ')'
          {
             YYTRACE("named_port_connection: '.' identifier '(' connect_port ')'");
           
          }
        ;

connect_port  //new rule
        :
          {
             YYTRACE("connect_port:");
           
          } 
        | expression
          {
             YYTRACE("connect_port: expression");
           
          }
        ;

/* F.5 Bahavioral Statements */
/*
initial_statement
        : YYINITIAL statement
          {
             YYTRACE("initial_statement: YYINITIAL statement");
          }
        ;
*/
always_statement
        : YYALWAYS statement                                                
          {
             if ((state) == EVENT)
             {
                YYTRACE("always_statement: YYALWAYS statement");
	
                state = S_NULL;
             }
             else;
		$$ = $2;
                
          }
        ;

statement_opt   //using task and function
        :
          {
             YYTRACE("statement_opt:");
            
          }
        | statement
          {
             YYTRACE("statement_opt: statement");
             
          }
        ;     

statement_clr /* using in "seq_block : YYBEGIN statement_clr YYEND" */      /*linking*/
        :
          {
             YYTRACE("statement_clr:");
           	$$ = NULL;
          }
        | statement_clr statement                                           
          {
             YYTRACE("statement_clr: statement_clr statement");
		$$ = $2;
           
          }
        ;

statement
        : ';'//The three rules {assignment ';'}, {lvalue YYNBASSIGN expression ';'},
          {  //and {lvalue '=' expression ';'} won't use this.
             YYTRACE("statement: ';'");
           	$$ = NULL;
          }
        | assignment ';' //The rule includes => statement : lvalue '=' expression ';'
          {              //                               | lvalue YYNBASSIGN delay_control expression ';'
             YYTRACE("statement: assignment ';'");
		$$ = $1;
          
          }
        | YYIF '(' expression ')' statement
          {
             YYTRACE("statement: YYIF '(' expression ')' statement");
		$$=mFactory->MakeIf();
		$$->AddChild($3);
             	$$->AddChild($5);
          }
        | YYIF '(' expression ')' statement YYELSE statement
          {
             YYTRACE("statement: YYIF '(' expression ')' statement YYELSE statement");
		$$=mFactory->MakeIf();
		$$->AddChild($3);
             	$$->AddChild($5);   
           	$$->AddChild($7);
	  } 
        | YYCASE '(' expression ')' synopsys_directive case_item_eclr YYENDCASE    // case, casex, casez are modified by Louis.
          {
             YYTRACE("statement: YYCASE '(' expression ')' case_item_eclr YYENDCASE");
		$$ = mFactory->MakeCase();
		$$->AddChild($3);
		$$->AddChild($6);
            
          }
        | YYCASEZ '(' expression ')' synopsys_directive  case_item_eclr YYENDCASE
          {
             YYTRACE("statement: YYCASEZ '(' expression ')' case_item_eclr YYENDCASE"); 
            
          }
        | YYCASEX '(' expression ')' synopsys_directive case_item_eclr YYENDCASE
          {
             YYTRACE("statement: YYCASEX '(' expression ')' case_item_eclr YYENDCASE");
          
          }
/*      | YYFOREVER statement
          {
             YYTRACE("statement: YYFOREVER statement");
          }
        | YYREPEAT '(' expression ')' statement
          {
             YYTRACE("statement: YYREPEAT '(' expression ')' statement");
          } 
        | YYWHILE '(' expression ')' statement
          {
             YYTRACE("statement: YYWHILE '(' expression ')' statement");
          }*/
        | YYFOR '(' assignment ';' expression ';' assignment ')' statement 
          {
             YYTRACE("statement: YYFOR '(' assignment ';' expression ';' assignment ')' statement");
		$$ = mFactory->MakeFor();
		$$->AddChild($3);
		$$->AddChild($5);
             	$$->AddChild($7);
		$$->AddChild($9);
          }
 /*     | delay_control statement
          {
             YYTRACE("statement: delay_control statement");
          }*/
        | event_control statement //always      //if function or task uses the rule ==> stntax error ==> lintting
          {
             YYTRACE("statement: event_control statement");
             state = EVENT;
		$$ = mFactory->MakeAlways();
		$$->AddChild($1);
		$$->AddChild($2);
          }
        | lvalue '=' delay_control expression ';'//when state the delay expression, then use the rule,
          {                                      //but to ignore delay
             YYTRACE("statement: lvalue '=' delay_control expression ';'");
            
          }
/*      | lvalue '=' event_control expression ';'  
          {
             YYTRACE("statement: lvalue '=' event_control expression ';'");
          }*/
        | lvalue YYNBASSIGN delay_control expression ';'// when state the delay expression, then
          {                                             // use the rule, but to ignore delay
             YYTRACE("statement: lvalue YYNBASSIGN delay_control expression ';'");
           
          }
/*      | lvalue YYNBASSIGN event_control expression ';'  
          {
             YYTRACE("statement: lvalue YYNBASSIGN event_control expression ';'");
          }*/
/*      | YYWAIT '(' expression ')' statement
          {
             YYTRACE("statement: YYWAIT '(' expression ')' statement");
          }
        | YYRIGHTARROW name_of_event ';'
          {
             YYTRACE("statement: YYRIGHTARROW name_of_event ';'");
          }*/
        | seq_block
          {
             YYTRACE("statement: seq_block");
           	$$ = $1;
          }
/*      | par_block
          {
             YYTRACE("statement: par_block");
          }*/
        | task_enable  //function can't use another task ==> lintting
          {            //task can use another task and function
             YYTRACE("statement: task_enable");
             if (scopeState == FUNCTION) {
             }
          }
/*      | system_task_enable
          {
             YYTRACE("statement: system_task_enable");
          }
        | YYDISABLE YYID 
          {
	  }
          ';'  // name of task or block 
          {
             YYTRACE("statement: YYDISABLE YYID ';'");
          }*/
        | YYASSIGN assignment ';'
          {
             YYTRACE("statement: YYASSIGN assignment ';'");
		$$ = mFactory->MakeAssign();
		$$->AddChild($2);
            
          }
/*      | YYDEASSIGN lvalue ';'
          {
             YYTRACE("statement: YYDEASSIGN lvalue ';'");
          }*/
        ;

synopsys_directive
        :                              
	{ 
		/*LY->stack_d.push(false); LY->stack_d.push(false); */
		$$ = NULL;
	}
        //| FULL_CASE                    { /*LY->stack_d.push(true) ; LY->stack_d.push(false); */}
        //| PARALLEL_CASE                { /*LY->stack_d.push(false); LY->stack_d.push(true); */ }
        //| FULL_CASE PARALLEL_CASE      { /*LY->stack_d.push(true);  LY->stack_d.push(true);  */}
        //| PARALLEL_CASE FULL_CASE      { /*LY->stack_d.push(true);  LY->stack_d.push(true); */ }
        
;
assignment
        : lvalue '=' expression
          {
             YYTRACE("assignment: lvalue '=' expression");
		$$=mFactory->MakeBlockingStatement();
		$$->AddChild($1);
		$$->AddChild($3);
             
          }
        | lvalue YYNBASSIGN expression
          {
             YYTRACE("assignment: lvalue YYNBASSIGN expression");
            	$$=mFactory->MakeNonBlockingStatement();
		$$->AddChild($1);
		$$->AddChild($3);
          }
        ;

case_item_eclr
        : case_item
          {
             YYTRACE("case_item_eclr: case_item");
           	$$ = mFactory->MakeCaseList();
		$$->AddChild($1);
          }
        | case_item_eclr case_item
          {
             YYTRACE("case_item_eclr: case_item_eclr case_item");
           	$$->AddChild($2);
          }
        ;

case_item
        : expression_list ':' statement
          {
             YYTRACE("case_item: expression_list ':' statement");
           	$$ = mFactory->MakeCaseItem();
		$$->AddChild($1);
		$$->AddChild($3);
          }
        | YYDEFAULT ':' statement
          {
             YYTRACE("case_item: YYDEFAULT ':' statement");
		$$ = mFactory->MakeCaseDefault();
            	$$->AddChild($3);
          }
        | YYDEFAULT  statement      //guess "default ; " (ie. null default expression)  
          {
             YYTRACE("case_item: YYDEFAULT statement");
          	$$ = NULL;
          }
        ;

seq_block
        : YYBEGIN statement_clr YYEND
          {
             YYTRACE("seq_block: YYBEGIN statement_clr YYEND");
		$$= mFactory->MakeBlock();
		$$->AddChild($2);
         
          }
        | YYBEGIN ':' name_of_block block_declaration_clr statement_clr YYEND                                        
          {
             YYTRACE("seq_block: YYBEGIN ':' name_of_block block_declaration_clr statement_clr YYEND");
           
          }
        ;

/*par_block
        : YYFORK statement_clr YYJOIN
          {
             YYTRACE("par_block: YYFORK statement_clr YYJOIN");
          }
        | YYFORK ':' name_of_block block_declaration_clr statement_clr YYJOIN
          {
             YYTRACE("par_block: YYFORK ':' name_of_block block_declaration_clr statement_clr YYJOIN");
          }
        ;*/

name_of_block
        : YYID
          {
             YYTRACE("name_of_block: YYID");
		$$ = mFactory->MakeIdentifier(*$1);
          }
        ;

block_declaration_clr     //seq_block 
        :
          {
             YYTRACE("block_declaration_clr:");
          }
        | block_declaration_clr block_declaration
          {
             YYTRACE("block_declaration_clr: block_declaration_clr block_declaration");
            
          }
        ;

block_declaration        
        : parameter_declaration
          {
             YYTRACE("block_declaration: parameter_declaration");
          }
        | reg_declaration
          {
             YYTRACE("block_declaration: reg_declaration");
          }
/*        | integer_declaration
          {
             YYTRACE("block_declaration: integer_declaration");
          }
        | real_declaration
          {
             YYTRACE("block_declaration: real_declaration");
          }
        | time_declaration
          {
             YYTRACE("block_delcaration: time_declaration");
          }
        | event_declaration
          {
             YYTRACE("block_declaration: event_declaration");
          }*/
        ;

/* YYID is the name of a task */
task_enable
        : YYID 
          { 
          }
          ';'
          {
             YYTRACE("task_enable: YYID ';'");
           
          }
        | YYID 
          {
          
					}
         '(' expression_list ')' ';'
          {
             YYTRACE("task_enable: YYID '(' expression_list ')' ';'");
            
          }
        ;

/*system_task_enable
        : name_of_system_task ';'
          {
             YYTRACE("system_task_enable: name_of_system_task ';'");
          }
        | name_of_system_task '(' expression_list ')'
          {
             YYTRACE("system_task_enable: name_of_system_task '(' expression_list ')'");
          }
        ;

name_of_system_task
        : system_identifier
          {
             YYTRACE("name_of_system_task: system_identifier");
          }
        ;*/

/* F.6 Specify section */

/*specify_block
        : YYSPECIFY specify_item_clr YYENDSPECIFY
          {
             YYTRACE("specify_block: YYSPECIFY specify_item_clr YYENDSPECIFY");
          } 
        ;

specify_item_clr
        :
        | specify_item_clr specify_item
        ;

specify_item
        : specparam_declaration
        | path_declaration
        | level_sensitive_path_declaration
        | edge_sensitive_path_declaration
        | system_timing_check
        ;

specparam_declaration
        : YYSPECPARAM assignment_list ';'
        ;

path_declaration
        : path_description '=' path_delay_value ';'
        ;
                                         
path_description
        : '(' specify_terminal_descriptor YYLEADTO specify_terminal_descriptor ')'
        | '(' path_list YYALLPATH path_list_or_edge_sensitive_path_list ')'
        ;

path_list
        : specify_terminal_descriptor
        | path_list ',' specify_terminal_descriptor
        ;

specify_terminal_descriptor
        : YYID
        | YYID '[' expression ']'
        | YYID '[' expression ';' expression ']'
        ;

path_list_or_edge_sensitive_path_list
        : path_list
        | '(' path_list ',' specify_terminal_descriptor
              polarity_operator YYCONDITIONAL 
              expression ')'
        ;

path_delay_value
        : path_delay_expression
        | '(' path_delay_expression ',' path_delay_expression ')'
        | '(' path_delay_expression ',' path_delay_expression ',' 
              path_delay_expression ')'
        | '(' path_delay_expression ',' path_delay_expression ','
              path_delay_expression ',' path_delay_expression ','
              path_delay_expression ',' path_delay_expression ')'
        ;

path_delay_expression
        : expression
        ;
*/
/* grammar rules for system timing check hasn't been done yet, includes:
 *  <system_timing_check>
 *  <timign_check_event>
 *  <controlled_timing_check_event>
 *  <timing_check_event_control>
 *  <timing_check_condidtion>
 *  <SCALAR_EXPRESSION>
 *  <timing_check_limit>
 *  <scalar_constant>
 *  <notify_register>
 *  in page 211. 
*/
/*
system_timing_check
        : YYsysSETUP '(' ')' ';'

level_sensitive_path_declaration
        : YYIF '(' expression ')'
            '(' specify_terminal_descriptor polarity_operator_opt YYLEADTO
                spec_terminal_desptr_or_edge_sensitive_spec_terminal_desptr
        | YYIF '(' expression ')'
            '(' path_list ',' specify_terminal_descriptor 
                polarity_operator_opt YYALLPATH path_list ')'
                path_list '=' path_delay_value ';'
        ;

spec_terminal_desptr_or_edge_sensitive_spec_terminal_desptr
        : specify_terminal_descriptor ')' path_list '=' path_delay_value ';'
        | '(' specify_terminal_descriptor polarity_operator YYCONDITIONAL
              expression ')' ')' '=' path_delay_value ';'


polarity_operator_opt
        :
        | polarity_operator
        ;

polarity_operator
        : '+'
        | '-'
        ;

edge_sensitive_path_declaration
        : '(' specify_terminal_descriptor YYLEADTO
            '(' specify_terminal_descriptor polarity_operator YYCONDITIONAL
                expression ')' ')' '=' path_delay_value ';'
        | '(' edge_identifier specify_terminal_descriptor YYLEADTO
            '(' specify_terminal_descriptor polarity_operator YYCONDITIONAL
                expression ')' ')' '=' path_delay_value ';'
        | '(' edge_identifier specify_terminal_descriptor YYALLPATH
            '(' path_list ',' specify_terminal_descriptor
                polarity_operator YYCONDITIONAL 
                expression ')' ')' '=' path_delay_value ';'
        | YYIF '(' expression ')'
            '(' specify_terminal_descriptor YYALLPATH
              '(' path_list ',' specify_terminal_descriptor
                  polarity_operator YYCONDITIONAL 
                  expression ')' ')' '=' path_delay_value ';'
        | YYIF '(' expression ')'
            '(' edge_identifier specify_terminal_descriptor YYLEADTO
              '(' specify_terminal_descriptor polarity_operator YYCONDITIONAL
                  expression ')' ')' '=' path_delay_value ';'
        | YYIF '(' expression ')'
            '(' edge_identifier specify_terminal_descriptor YYALLPATH
              '(' path_list ',' specify_terminal_descriptor
                  polarity_operator YYCONDITIONAL 
                  expression ')' ')' '=' path_delay_value ';'
        ;

edge_identifier
        : YYPOSEDGE
        | YYNEGEDGE
        ;*/

/* F.7 Expressions */

lvalue
        : identifier
       	{
		YYTRACE("lvalue: YYID");
		$$=$1;
	}

        | identifier { } bitExpression
          {
	     YYTRACE("lvalue: YYID '[' expression ']'");
		$$ = $3;
		$$->AddChild($1);
					}
        | concatenation
          {
	     YYTRACE("lvalue: concatenation");
		$$ = $1;
            
	  }
        | YYDEF_ID bit_exp// added by Louis
          { 
	     YYTRACE("lvalue: YYDEF_ID");
            
  	  }
        ;

bit_exp 
        :                  { $$ = NULL; }
        | bitExpression    { $$ = $1; }
        ;
   
//==========================================still not complete========================================// 
mintypmax_expression_list// only use in instance parameter overload
        : mintypmax_expression
          {
	     YYTRACE("mintypmax_expression_list: mintypmax_expression");
           
	  }
        | mintypmax_expression_list ',' mintypmax_expression
          {
             YYTRACE("mintypmax_expression_list: mintypmax_expression_list ',' mintypmax_expression");
            
	  }
        ;
//=================================================================================================//
mintypmax_expression
        : expression
          {
	     YYTRACE("mintypmax_expression: expression");
            
					}
/*        | expression ':' expression ':' expression // It may be used in UDP, so won't be supported
          {
	     YYTRACE("mintypmax_expression: expression ':' expression ':' expression");
	  }*/
        ;

expression_list   //case_item, concatenation, multiple_concatenation, function_call, task_enable
        : expression
          {/*expression is used in case, task, and concatenate*/
	     YYTRACE("expression_list: expression");
            	$$=mFactory->MakeExpressionList();
		$$->AddChild($1);
	  }
        | expression_list ',' expression     
          {
	     YYTRACE("expression_list: expression_list ',' expression");
           	//$$=$1;
		$$->AddChild($3);
	  }
        ;

expression
        : primary
          {
	     YYTRACE("expression: primary");
           	$$=$1;
	  }
        | '+' primary %prec YYUNARYOPERATOR
          {
	     YYTRACE("expression: '+' primary %prec YYUNARYOPERATOR");
		$$ = mFactory->MakeUnaryOperation();
		$$->SetName("ADD");
		$$->AddChild($2);
           
	  } 
        | '-' primary %prec YYUNARYOPERATOR
          {
	     YYTRACE("expression: '-' primary %prec YYUNARYOPERATOR");
		$$ = mFactory->MakeUnaryOperation();
		$$->SetName("MINUS");
		$$->AddChild($2);
	  }
        | '!' primary %prec YYUNARYOPERATOR
          {
	     YYTRACE("expression: '!' primary %prec YYUNARYOPERATOR");
           	$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_NOT");
		$$->AddChild($2);
	  }
        | '~' primary %prec YYUNARYOPERATOR
          {
             YYTRACE("expression: '~' primary %prec YYUNARYOPERATOR");
		$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_NOT");
		$$->AddChild($2);
            
	  }
        | '&' primary %prec YYUNARYOPERATOR
          {
	     YYTRACE("expression: '&' primary %prec YYUNARYOPERATOR");
            	$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_AND");
		$$->AddChild($2);
	  }
        | '|' primary %prec YYUNARYOPERATOR
          {
	     YYTRACE("expression: '|' primary %prec YYUNARYOPERATOR");
           	$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_OR");
		$$->AddChild($2);
	  }
        | '^' primary %prec YYUNARYOPERATOR
          {/*The rule is added by Louis.*/
	     YYTRACE("expression: '^' primary %prec YYUNARYOPERATOR");
           	$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_XOR");
		$$->AddChild($2);
	  }
        | YYLOGNAND primary %prec YYUNARYOPERATOR
          {
	     YYTRACE("expression: YYLOGNAND primary %prec YYUNARYOPERATOR");
            	$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_NAND");
		$$->AddChild($2);
	  }
        | YYLOGNOR primary %prec YYUNARYOPERATOR
          {
             YYTRACE("expression: YYLOGNOR primary %prec YYUNARYOPERATOR");
            	$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_NOR");
		$$->AddChild($2);
	  }
        | YYLOGXNOR primary %prec YYUNARYOPERATOR
          {
	     YYTRACE("expression: YYLOGXNOR primary %prec YYUNARYOPERATOR");
           	$$ = mFactory->MakeUnaryOperation();
		$$->SetName("BITWISE_XNOR");
		$$->AddChild($2);
	  }
        | expression '+' expression
          {
	     YYTRACE("expression: expression '+' expression");
		$$=mFactory->MakeBinaryOperation();
		$$->SetName("ADD");
		$$->AddChild($1);
		$$->AddChild($3);
            
	  }
        | expression '-' expression
          {
	     YYTRACE("expression: expressio '-' expression");
		$$=mFactory->MakeBinaryOperation();
		$$->SetName("MINUS");
		$$->AddChild($1);
		$$->AddChild($3);
            
	  }
        | expression '*' expression
          {
	     YYTRACE("expression: expression '*' expression");
		$$=mFactory->MakeBinaryOperation();
		$$->SetName("MULTIPLY");
		$$->AddChild($1);
		$$->AddChild($3);
            
	  }
/*      | expression '/' expression
          {
	     YYTRACE("expression: expression '/' expression");
		$$=mFactory->MakeBinaryOperation();
		$$->SetName("DIV");
		$$->AddChild($1);
		$$->AddChild($3);

	  }
        | expression '%' expression
          {
             YYTRACE("expression: expression '%' expression");
	  }*/
        | expression YYLOGEQUALITY expression
          {
	     YYTRACE("expression: expression YYLOGEQUALITY expression");
		$$ = mFactory->MakeBinaryOperation();
		$$->SetName("LOGICAL_EQUAL");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression YYLOGINEQUALITY expression
          {
	     YYTRACE("expression: expression YYLOGINEQUALITY expression");
          	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("NOT_EQUAL");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression YYCASEEQUALITY expression	// ===
          {
	     YYTRACE("expression: expression YYCASEEQUALITY expression");
            	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("CASE_EQUAL");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression YYCASEINEQUALITY expression
          {
	     YYTRACE("expression: expression YYCASEINEQUALITY expression");
		$$ = mFactory->MakeBinaryOperation();
		$$->SetName("CASE_NOT_EQUAL");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression YYLOGAND expression
          {
	     YYTRACE("expression: expression YYLOGAND expression");
		$$ = mFactory->MakeBinaryOperation();
		$$->SetName("LOGICAL_AND");
		$$->AddChild($1);
        	$$->AddChild($3);
          
	  }
        | expression YYLOGOR expression
          {
	     YYTRACE("expression: expression YYLOGOR expression");
           	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("LOGICAL_OR");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression '<' expression
          {
	     YYTRACE("expression: expression '<' expression");
         	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("LT");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression '>' expression
          {
	     YYTRACE("expression: expression '>' expression");
           	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("GT");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression '&' expression
          {
	     YYTRACE("expression: expression '&' expression");
       		$$ = mFactory->MakeBinaryOperation();
		$$->SetName("BITWISE_AND");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression '|' expression
          {
	     YYTRACE("expression: expression '|' expression");
		$$ = mFactory->MakeBinaryOperation();
		$$->SetName("BITWISE_OR");
		$$->AddChild($1);
        	$$->AddChild($3);
          }
        | expression '^' expression
          {
	     YYTRACE("expression: expression '^' expression");
          	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("BITWISE_XOR");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression YYLEQ expression
          {
	     YYTRACE("expression: expression YYLEQ expression");
		$$=mFactory->MakeBinaryOperation();
		$$->SetName("LEQ");
		$$->AddChild($1);
		$$->AddChild($3);
	  }
        | expression YYNBASSIGN expression
          {
	     YYTRACE("expression: expression YYLEQ expression");
		$$=mFactory->MakeNonBlockingStatement();
		$$->AddChild($1);
     		$$->AddChild($1);
	  }
        | expression YYGEQ expression
          {
	     YYTRACE("expression: expression YYGEQ expression");
		$$=mFactory->MakeBinaryOperation();
		$$->SetName("GEQ");
		$$->AddChild($1);
		$$->AddChild($3);
           }
        | expression YYLSHIFT expression
          {
	     YYTRACE("expression: expression YYLSHIFT expression");
          	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("LS");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression YYRSHIFT expression
          {
	     YYTRACE("expression: expression YYRSHIFT expression");
           	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("RS");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression YYLOGXNOR expression
          {
	     YYTRACE("expression: expression YYLOGXNOR expression");
            	$$ = mFactory->MakeBinaryOperation();
		$$->SetName("LOGICAL_XNOR");
		$$->AddChild($1);
        	$$->AddChild($3);
	  }
        | expression '?' expression ':' expression
          {
	     YYTRACE("expression: expression '?' expression ':' expression");
           	$$ = mFactory->MakeIfQuestion();
		$$->AddChild($1);
		$$->AddChild($3);
		$$->AddChild($5);
	  }

        ;

primary
        : YYINUMBER
          {
	     YYTRACE("primary: YYINUMBER");
		//cout<<$1 <<endl;
		$$ = mFactory->MakeNumber($1);
          }
        | YYRNUMBER
          {
             YYTRACE("primary: YYRNUMBER");
		//cout<<*$1<<endl;
         	$$ = mFactory->MakeRealNumber(*$1);
	}
        | identifier
          {
	     YYTRACE("primary: identifier");
		$$=$1;
					}
        | identifier {  } bitExpression
          {
	     YYTRACE("primary: identifier bitExpression");
		//$$=mFactory->MakeArrayRef();
		$$ = $3;
		$$->AddChild($1);
	  }
        | concatenation
          {
	     YYTRACE("primary: concatenation");
             	$$ = $1;
	  }
        | multiple_concatenation
	  {
	     YYTRACE("primary: multiple_concatenatin");
		$$ = $1;
            
	  }
        | function_call
          {
	     YYTRACE("primary: function_call");
             
	  }
        | YYBIT_BASE_STRING//action is same as "primary: identifier", 
          {                //but put in different BNF to make modify easily in the future
             YYTRACE("primary: BIT_BASE_NUMBER");
		$$ = mFactory->MakeBitBase(*$1);
             
          }
        | '(' expression ')'//add by Louis   Ex: a = ~( b ^ c )    c = ~(clk)        
          {
	     YYTRACE("expression: ( expression )");
            	$$ = $2;
          }
        | YYDEF_ID bit_exp// added by Louis
          { 
             YYTRACE("primary: YYDEF_ID");
           
          }

/*        | '(' mintypmax_expression ')'        
          {
	     YYTRACE("primary: '(' mintypmax_expression ')'");
	  }*/
        ;

bitExpression //Add by Louis 
        : '[' expression ']'
          {
        	$$=mFactory->MakeArrayRef();
		$$->AddChild($2);
          }
        | '[' expression ':' expression ']'
          {
           	$$ = mFactory->MakeRange();
		$$->AddChild($2);
		$$->AddChild($4); 
          }
        ;

/*
 * number : decimal_number
 *        | unsigned number? base number
 *        | real_number
 *        ;
 *
 * is put in lex rules
 */

concatenation
        : '{' expression_list '}'
          {
	     YYTRACE("concatenation: '{' expression_list '}'");
		$$ = mFactory->MakeConcatenate();
		$$->AddChild($2);
          }
	//| '{' expression_list ',' expres'}'
        ;

multiple_concatenation
        : '{' expression '{' expression_list '}' '}'
	  {
	     YYTRACE("multiple_concatenation: '{' expression '{' expression_list '}' '}'");
		$$ = mFactory->MakeConcatenate();
		$$->AddChild($2);
		$$->AddChild($4);
           
	  }
    ;

function_call 
	 : identifier '(' {  }
          expression_list ')'
          {
	     YYTRACE("function_call: identifier '(' expression_list ')'");
					}
	;

/* F.8 General */
	  ;
identifier
        : YYID
          {//identifier => stringPtr 
             YYTRACE("identifier: YYID");
		$$ = mFactory->MakeIdentifier(*$1);
    
          }
          | identifier '.' {  } YYID
          //defparam use the rule(name mapping of parameter overload)
          //ps:it isn't instance name mapping syntax                                                                        
          {
             YYTRACE("identifier: identifier '.' YYID");
						 // $$ = $4;
          }
        ;


delay_control//ignore delay
        : '#' YYINUMBER
          {
	     YYTRACE("delay_control: '#' YYINUMBER");
	  }
        | '#' YYRNUMBER
          {
	     YYTRACE("delay_control: '#' YYRNUMBER");
	  }  
        | '#' identifier
          {
	     YYTRACE("delay_control: '#' identifier");
	  }
        | '#' '(' mintypmax_expression ')'
          {
	     YYTRACE("delay_control: '#' '(' mintypmax_expression ')'");
	  }
        ;

event_control // use in always
 /*       : '@' identifier      // It may be used in the BNF "lvalue = event_control expression"
          {                     // No supply
	     YYTRACE("event_control: '@' identifier");
             
	  }*/
        : '@' '(' event_expression ')'
          {
	     YYTRACE("event_control: '@' '(' event_expression ')'");
		$$ = mFactory->MakeEventControl();
		$$->AddChild($3);
           
	  }
        | '@' '(' ored_event_expression ')'
          {
		// 03-05 Make Always
	     YYTRACE("event_control: '@' '(' ored_event_expression ')'");
		$$ = $3;
	  }
        | '@' '*'
          {
             	$$ = NULL;
          }
        | '@' '(' '*' ')'
          {
          	$$ = NULL;
          }
        ;

/*
 * event_expression: event_expression YYOR event_expression 
 *
 * is replaced with
 *
 * event_expression: event_expression YYOR expression
 */
event_expression
        : expression
          {
	     YYTRACE("event_expression: expression");
             $$ = $1;
	  }
        | YYPOSEDGE expression
          {
	     YYTRACE("event_expression: YYPOSEDGE expression");
		$$ = mFactory->MakePosedge();
		$$->AddChild($2);
            
	  }
        | YYNEGEDGE expression
          {
	     YYTRACE("event_expression: YYNEGEDGE expression");
		$$ = mFactory->MakeNegedge();
		$$->AddChild($2);
           
	  }
	| YYEDGE expression
	  {
	     YYTRACE("event_expression: YYEDGE expression");
            $$=NULL;
          }
        ;

ored_event_expression
        : event_expression or_expression event_expression
          {
	     YYTRACE("ored_event_expression: event_expression YYOR event_expression");
		$$ = mFactory->MakeEventControl();
		$$->AddChild($1);
		$$->AddChild($3);
           
	  }
        | ored_event_expression or_expression event_expression
          {
	     YYTRACE("ored_event_expression: ored_event_expression YYOR event_expression");
		$$->AddChild($3);
             
	  }
        ;

or_expression  // new rule, added @090102
        : YYOR
        | YYLOGOR
        | ','
        ;

%%





