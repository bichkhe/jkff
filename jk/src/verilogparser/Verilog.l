%{

#include <string>
#include <iostream>
#include <cassert>
#include <stack>
#include "VerilogScanner.h"
#include "VerilogFactory.h"
#include "VerilogException.h"
#include "VerilogParser.h"
#include "VerilogParserFunction.h"


	using namespace std;
	extern YYSTYPE Veriloglval;
	extern VerilogParser* VP;

%}



%option c++
%option prefix="VerilogParser"
%option yyclass="VerilogScanner"
%option noyywrap



Space       [\r\t\b ]
Space1      [\r\t\b\n ]
Alpha       [a-zA-Z]
AlphaU      [a-zA-Z_]
AlphaNum    [a-zA-Z0-9]
AlphaNumU   [a-zA-Z0-9_]
Digit       [0-9]
DigitU      [0-9_]
Number      {Digit}{DigitU}*
Decimal     ({Number})?'[dD]{Space1}*{Number}
Octal       ({Number})?'[oO]{Space1}*[0-7xXzZ?][0-7xXzZ?_]*
Hexdecimal  ({Number})?'[hH]{Space1}*[0-9a-fA-FxXzZ?][0-9a-fA-FxXzZ?_]*
Binary      ({Number})?'[bB]{Space1}*[01xXzZ?][01xXzZ?_]*

%x COMMENT
%x COMMENT_L
%x INCLUDE
%x IFDEF
%x MARKED
%x MARKED_S
%x DIRECTIVE
%x DIRECTIVE_L
%x TRAN_OFF
%x TRAN_OFF_L
%x LIBRARY
%x DEFINE

%%

{Space}+          { VP->colNo = VP->colNo + strlen(yytext); continue; }
                           
\n                { 
                     (VP->lineNo)++;
                     VP->colNo = 1;
                     if (VP->defState) {
                        BEGIN 0;
                        VP->defState = false;
                        if (VP->defCount == 1) 
                           return YYDEF_NULL; 
                        else
                           continue;                              
                     }                            
                     else 
                        continue; 
                     VP->defCount = 0;
                  }
<LIBRARY>"//"        { (VP->colNo)+=2; BEGIN COMMENT_L; }
<LIBRARY>"/*"        { (VP->colNo)+=2; BEGIN COMMENT; }
"//"                 { (VP->colNo)+=2; BEGIN COMMENT_L; }
"/*"                 { (VP->colNo)+=2; BEGIN COMMENT; }

<COMMENT>synopsys    { if (VP->blackBox == false) BEGIN DIRECTIVE; }
<COMMENT_L>synopsys  { if (VP->blackBox == false) BEGIN DIRECTIVE_L; }

<COMMENT,COMMENT_L>. { (VP->colNo)++; continue; }

<COMMENT>\n          { (VP->lineNo)++; VP->colNo = 1; continue; }            
<COMMENT_L>\n        { (VP->lineNo)++; VP->colNo = 1;
                       if (VP->blackBox == true && VP->vLibComment == false && VP->modStart == true) 
                          BEGIN LIBRARY; 
                       else 
                          BEGIN 0;
                       
                     }
<COMMENT>"*/"        { (VP->colNo)+=2; 
                       if (VP->blackBox == true && VP->vLibComment == false && VP->modStart == true) 
                          BEGIN LIBRARY; 
                       else 
                          BEGIN 0; 
                     }
<DIRECTIVE>{Space}+         { (VP->colNo)++; continue; }
<DIRECTIVE>translate_off    { BEGIN TRAN_OFF; }
<DIRECTIVE>translate_on     { BEGIN COMMENT;  }
<DIRECTIVE>parallel_case    { return PARALLEL_CASE; }
<DIRECTIVE>full_case        { return FULL_CASE; }
<DIRECTIVE>"*/"             { (VP->colNo)+=2; BEGIN 0; }
<DIRECTIVE>.                { (VP->colNo)++; BEGIN COMMENT; }
<DIRECTIVE>\n               { (VP->lineNo)++; VP->colNo = 1; BEGIN COMMENT; }

<DIRECTIVE_L>{Space}+       { (VP->colNo)++; continue; }
<DIRECTIVE_L>translate_off  { BEGIN TRAN_OFF_L; }
<DIRECTIVE_L>translate_on   { BEGIN COMMENT_L;  }
<DIRECTIVE_L>parallel_case  { return PARALLEL_CASE; }
<DIRECTIVE_L>full_case      { return FULL_CASE; }
<DIRECTIVE_L>.              { (VP->colNo)++; BEGIN COMMENT_L; }
<DIRECTIVE_L>\n             { (VP->lineNo)++; VP->colNo = 1; BEGIN 0; }


<TRAN_OFF>synopsys { BEGIN DIRECTIVE; }
<TRAN_OFF>.        { (VP->colNo)++; continue; }
<TRAN_OFF>\n       { (VP->lineNo)++; VP->colNo = 1; continue; }
<TRAN_OFF>"*/"     { (VP->colNo)+=2; BEGIN MARKED_S; }

<TRAN_OFF_L>synopsys { BEGIN DIRECTIVE_L; }
<TRAN_OFF_L>.        { (VP->colNo)++; continue; }
<TRAN_OFF_L>\n       { (VP->lineNo)++; VP->colNo = 1; BEGIN MARKED_S; }

<MARKED_S>"//"       { (VP->colNo)+=2; BEGIN TRAN_OFF_L; }
<MARKED_S>"/*"       { (VP->colNo)+=2; BEGIN TRAN_OFF; }
<MARKED_S>.          { (VP->colNo)++; continue; }                    
<MARKED_S>\n         { (VP->lineNo)++; VP->colNo = 1; continue; }            

`define            { (VP->colNo)+=7; 
                     BEGIN DEFINE;
                     VP->defState = true;
                     VP->defCount = 0;
                     return YYDEFINE; 
                   
   /*
   `include{Space}*\" { BEGIN INCLUDE; VP->colNo+= strlen(yytext); continue; }
   <INCLUDE>[^\"]*    { BEGIN 0; parseInclude(yytext); BEGIN INCLUDE; continue; }
   <INCLUDE>[\"]{Space}*\n  { cout << "================hit===============" << endl; VP->lineNo++; VP->colNo = 1; BEGIN 0; }
   */
                   }

<DEFINE>`{AlphaU}{AlphaNumU}* {  
                                 VP->colNo = (VP->colNo) + strlen(yytext);               
                                 VP->yyid = yytext+1; //ignore the char '`'
                                 Veriloglval.stringPtr = &(VP->yyid);
                                 (VP->defCount)++;
                                 BEGIN 0;
                                 return YYDEF_ID;
                              }
<DEFINE>{AlphaU}{AlphaNumU}*  {
                                 VP->colNo = (VP->colNo) + strlen(yytext);               
                                 VP->yyid = yytext;
                                 Veriloglval.stringPtr = &(VP->yyid);
                                 (VP->defCount)++;
                                 BEGIN 0;
                                 return YYID;
                              }
<DEFINE>{Space}+   { (VP->colNo)++; continue; }

`include{Space}*\" { BEGIN INCLUDE; (VP->colNo)+= strlen(yytext); continue; }
<INCLUDE>[^\"]*    { VP->yyid = yytext; continue; }
<INCLUDE>\"{Space}*\n   { (VP->lineNo)++; VP->colNo = 1; /*parseInclude(VP->yyid);*/ BEGIN 0; }

`ifdef               { BEGIN IFDEF; }
<IFDEF>{Space}+      { VP->colNo = (VP->colNo) + strlen(yytext); continue; }

<IFDEF>{AlphaU}{AlphaNumU}*  {  if (1)
                                   BEGIN 0;
                                else
                                   BEGIN MARKED;
                             }
<MARKED>`else        { BEGIN 0; } 
<MARKED>`endif       { BEGIN 0; }       
<MARKED>.            { (VP->colNo)++; continue; }
<MARKED>\n           { (VP->lineNo)++; VP->colNo = 1; continue; }             
`else                { BEGIN MARKED; }
`endif               { BEGIN 0; }
`timescale[^\n]*     { continue; }
`celldefine          { continue; }
`endcelldefine       { continue; }

<LIBRARY>input     { if (VP->scopeState == VerilogParser::MODULE) 
                        { BEGIN 0; VP->vLibComment = true; return YYINPUT; } }
<LIBRARY>output    { if (VP->scopeState == VerilogParser::MODULE) 
                        { BEGIN 0; VP->vLibComment = true; return YYOUTPUT; } }
<LIBRARY>inout     { if (VP->scopeState == VerilogParser::MODULE) 
                        { BEGIN 0; VP->vLibComment = true; return YYINOUT; } }
<LIBRARY>parameter { if (VP->scopeState == VerilogParser::MODULE) 
                        { BEGIN 0; VP->vLibComment = true; return YYPARAMETER; } }
<LIBRARY>endmodule { BEGIN 0; VP->modStart = false; return YYENDMODULE; }
<LIBRARY>.         { continue; }
<LIBRARY>\n        { (VP->lineNo)++; VP->colNo = 1; continue; }

">="               { (VP->colNo)+=2; return YYGEQ; }
"=<"               { (VP->colNo)+=2; return YYLEQ; }
"&&"               { (VP->colNo)+=2; return YYLOGAND; }
"||"               { (VP->colNo)+=2; return YYLOGOR; }
"==="              { (VP->colNo)+=3; return YYCASEEQUALITY; }
"=="               { (VP->colNo)+=2; return YYLOGEQUALITY; }
"!=="              { (VP->colNo)+=3; return YYCASEINEQUALITY; }
"!="               { (VP->colNo)+=2; return YYLOGINEQUALITY; }
"^~"               { (VP->colNo)+=2; return YYLOGXNOR; }
"~^"               { (VP->colNo)+=2; return YYLOGXNOR; }
"~&"               { (VP->colNo)+=2; return YYLOGNAND; }
"~|"               { (VP->colNo)+=2; return YYLOGNOR; }
"<<"               { (VP->colNo)+=2; return YYLSHIFT; }
">>"               { (VP->colNo)+=2; return YYRSHIFT; }
 "?:"               { cerr << "No supply conditional" << endl; } //return YYCONDITIONAL;
 \"[^"]*            { cerr << "No supply string" << endl; } //return YYSTRING;

always             { (VP->colNo)+=6; return YYALWAYS; }
 "*>"               { /*return YYALLPATH;*/ }
and                { (VP->colNo)+=3; return YYAND; }
assign             { (VP->colNo)+=6; return YYASSIGN; }
begin              { (VP->colNo)+=5; return YYBEGIN; }
buf                { (VP->colNo)+=3; return YYBUF; }
bufif0             { (VP->colNo)+=6; return YYBUFIF0; }
bufif1             { (VP->colNo)+=6; return YYBUFIF1; }
case               { (VP->colNo)+=4; return YYCASE; }
casex              { (VP->colNo)+=5; return YYCASEX; }
casez              { (VP->colNo)+=5; return YYCASEZ; }
cmos               { /*return YYCMOS;*/ }
deassign           { /*return YYDEASSIGN;*/ }
default            { (VP->colNo)+=7; return YYDEFAULT; }
defparam           { (VP->colNo)+=8; return YYDEFPARAM; }
disable            { /*return YYDISABLE;*/ }
edge               { (VP->colNo)+=4; return YYEDGE; }
else               { (VP->colNo)+=4; return YYELSE; }
end                { (VP->colNo)+=3; return YYEND; }
endcase            { (VP->colNo)+=7; return YYENDCASE; }
endfunction        { (VP->colNo)+=11; return YYENDFUNCTION; }
endmodule          { (VP->colNo)+=9; return YYENDMODULE; }
endprimitive       { /*return YYENDPRIMITIVE;*/ }
endspecify         { /*return YYENDSPECIFY;*/ }
endtable           { /*scan_table = 0; return YYENDTABLE;*/ }
endtask            { (VP->colNo)+=7; return YYENDTASK; }
event              { /*return YYEVENT;*/ }
for                { (VP->colNo)+=3; return YYFOR; }
forever            { /*return YYFOREVER;*/ }
fork               { /*return YYFORK;*/ }
function           { (VP->colNo)+=8; return YYFUNCTION; }
highz0             { (VP->colNo)+=6; return YYHIGHZ0; }
highz1             { (VP->colNo)+=6; return YYHIGHZ1; }
if                 { (VP->colNo)+=2; return YYIF; }
initial            { /*return YYINITIAL;*/ }
inout              { (VP->colNo)+=5; return YYINOUT; }
input              { (VP->colNo)+=5; return YYINPUT; }
integer            { (VP->colNo)+=7; return YYINTEGER; }
join               { /*return YYJOIN;*/ }
large              { /*return YYLARGE;*/ }
"=>"               { /*return YYLEADTO;*/ }
macromodule        { /*return YYMACROMODULE;*/ }
medium             { /*return YYMEDIUM;*/ }
module             { 
                     if (VP->blackBox == true) {
                        VP->vLibComment = true;
                        VP->modStart = true;
                     }
                     (VP->colNo)+=6; return YYMODULE; }
mreg               { /*return YYMREG;*/ }
"<="               { (VP->colNo)+=2; return YYNBASSIGN;  }
nand               { (VP->colNo)+=4; return YYNAND; }
negedge            { (VP->colNo)+=7; return YYNEGEDGE; }
nmos               { /*return YYNMOS;*/ }
nor                { (VP->colNo)+=3; return YYNOR; }
not                { (VP->colNo)+=3; return YYNOT; }
notif0             { /*return YYNOTIF0;*/ }
notif1             { /*return YYNOTIF1;*/ }
or                 { (VP->colNo)+=2; return YYOR; }
output             { (VP->colNo)+=6; return YYOUTPUT; }
parameter          { (VP->colNo)+=9; return YYPARAMETER; }
pmos               { /*return YYPMOS;*/ }
posedge            { (VP->colNo)+=7; return YYPOSEDGE; }
primitive          { /*return YYPRIMITIVE;*/ }
pull0              { (VP->colNo)+=5; return YYPULL0; }
pull1              { (VP->colNo)+=5; return YYPULL1; }
pulldown           { /*return YYPULLDOWN;*/ }
pullup             { /*return YYPULLUP;*/ }
rcmos              { /*return YYRCMOS;*/ }
real               { /*return YYREAL;*/ }
reg                { (VP->colNo)+=3; return YYREG; }
repeat             { /*return YYREPEAT;*/ }
"->"               { /*return YYRIGHTARROW;*/ }
rnmos              { /*return YYRNMOS;*/ }
rpmos              { /*return YYRPMOS;*/ }
rtran              { /*return YYRTRAN;*/ }
rtranif0           { /*return YYRTRANIF0;*/ }
rtranif1           { /*return YYRTRANIF1;*/ }
scalered           { /*return YYSCALARED;*/ }
small              { /*return YYSMALL;*/ }
specify            { /*return YYSPECIFY;*/ }
specparam          { /*return YYSPECPARAM;*/ }
strong0            { (VP->colNo)+=7; return YYSTRONG0; }
strong1            { (VP->colNo)+=7; return YYSTRONG1; }
supply0            { (VP->colNo)+=7; return YYSUPPLY0; }
supply1            { (VP->colNo)+=7; return YYSUPPLY1; }
swire              { (VP->colNo)+=5; return YYSWIRE; }
table              { /*scan_table = 1; return YYTABLE;*/ }
task               { (VP->colNo)+=4; return YYTASK; }
time               { /*return YYTIME;*/ }
tran               { /*return YYTRAN;*/ }
tranif0            { /*return YYTRANIF0;*/ }
tranif1            { /*return YYTRANIF1;*/ }
tri                { (VP->colNo)+=3; return YYTRI; }
tri0               { (VP->colNo)+=4; return YYTRI0; }
tri1               { (VP->colNo)+=4; return YYTRI1; }
triand             { (VP->colNo)+=6; return YYTRIAND; }
trior              { (VP->colNo)+=5; return YYTRIOR; }
vectored           { /*return YYVECTORED;*/ }
wait               { /*return YYWAIT;*/ }
wand               { (VP->colNo)+=4; return YYWAND; }
weak0              { (VP->colNo)+=5; return YYWEAK0; }
weak1              { (VP->colNo)+=5; return YYWEAK1; }
while              { /*return YYWHILE;*/ }
wire               { (VP->colNo)+=4; return YYWIRE; }
wor                { (VP->colNo)+=3; return YYWOR; }
xnor               { (VP->colNo)+=4; return YYXNOR; }
xor                { (VP->colNo)+=3; return YYXOR; }

\$setup              { cerr << "Error: no supply $setup" << endl;/*return YYsysSETUP;*/ }
\${Alpha}+           { cerr << "Error: no supply ${Alpha}+" << endl;/*return YYsysID;*/ }
`{AlphaU}{AlphaNumU}* {  
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                         VP->yyid = yytext+1; //ignore the char '`'
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
                         return YYDEF_ID;
                      }
{AlphaU}{AlphaNumU}*  {
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                         VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
                         return YYID;
                      }
\\[^\n\t\b\r ]*       { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                         VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
                         return YYID;
                      }

{Number}*\.{Number}+  { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);
			 VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);       
                         if (VP->defState)
                            (VP->defCount)++;
			//cout<<"************"<<yytext<<endl;
                         return YYRNUMBER; 
                      }
{Number}+\.{Number}*  { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);
			VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
			//cout<<"*******a*****"<<yytext<<endl;
                         return YYRNUMBER; 
                      }
{Number}              { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                         //Veriloglval->ival = atoi(yytext);
                         Veriloglval.ival = atoi(yytext);
                         if (VP->defState)
                            (VP->defCount)++;
			 //cout<<"************"<<yytext<<"**********"<<Veriloglval.ival<<endl;
                         return YYINUMBER;  
                      }
{Binary}              { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                       	//VP->yyid = processWhite(yytext);
                         //Veriloglval->stringPtr = &VP->yyid;
			 VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
			cout<<"***********Binary**********"<<yytext<<endl;
                         return YYBIT_BASE_STRING; 
                      }
{Octal}               { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                     //    VP->yyid = processWhite(yytext);
                         //Veriloglval->stringPtr = &VP->yyid;
			VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
                         return YYBIT_BASE_STRING; 
                      }
{Decimal}             { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                         // VP->yyid = processWhite(yytext);
                         //Veriloglval->stringPtr = &VP->yyid;
			 VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
                         return YYBIT_BASE_STRING; 
                      }
{Hexdecimal}          { 
                         (VP->colNo) = (VP->colNo) + strlen(yytext);               
                        // VP->yyid = processWhite(yytext);
                         //Veriloglval->stringPtr = &VP->yyid;
			 VP->yyid = yytext;
                         Veriloglval.stringPtr = &(VP->yyid);
                         if (VP->defState)
                            (VP->defCount)++;
                         return YYBIT_BASE_STRING; 
                      }
.                     { 
                        (VP->colNo)++;
                        if (VP->blackBox == true && yytext[0] == ';') {
                           VP->vLibComment = false;
                           BEGIN LIBRARY;
                        }
                        return yytext[0]; 
                      }


%%    

