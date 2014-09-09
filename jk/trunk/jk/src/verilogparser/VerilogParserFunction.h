/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     YYID = 258,
     YYDEF_ID = 259,
     YYINUMBER = 260,
     YYRNUMBER = 261,
     YYBIT_BASE_STRING = 262,
     YYALWAYS = 263,
     YYAND = 264,
     YYASSIGN = 265,
     YYBEGIN = 266,
     YYBUF = 267,
     YYBUFIF0 = 268,
     YYBUFIF1 = 269,
     YYCASE = 270,
     YYCASEX = 271,
     YYCASEZ = 272,
     YYDEFAULT = 273,
     YYDEFPARAM = 274,
     YYELSE = 275,
     YYEDGE = 276,
     YYEND = 277,
     YYENDCASE = 278,
     YYENDMODULE = 279,
     YYENDFUNCTION = 280,
     YYENDTASK = 281,
     YYFOR = 282,
     YYFUNCTION = 283,
     YYGEQ = 284,
     YYHIGHZ0 = 285,
     YYHIGHZ1 = 286,
     YYIF = 287,
     YYINOUT = 288,
     YYINPUT = 289,
     YYINTEGER = 290,
     YYLEQ = 291,
     YYLOGAND = 292,
     YYCASEEQUALITY = 293,
     YYCASEINEQUALITY = 294,
     YYLOGNAND = 295,
     YYLOGNOR = 296,
     YYLOGOR = 297,
     YYLOGXNOR = 298,
     YYLOGEQUALITY = 299,
     YYLOGINEQUALITY = 300,
     YYLSHIFT = 301,
     YYMODULE = 302,
     YYNAND = 303,
     YYNBASSIGN = 304,
     YYNEGEDGE = 305,
     YYNOR = 306,
     YYNOT = 307,
     YYOR = 308,
     YYOUTPUT = 309,
     YYPARAMETER = 310,
     YYPOSEDGE = 311,
     YYPULL0 = 312,
     YYPULL1 = 313,
     YYREG = 314,
     YYRSHIFT = 315,
     YYSTRONG0 = 316,
     YYSTRONG1 = 317,
     YYSUPPLY0 = 318,
     YYSUPPLY1 = 319,
     YYSWIRE = 320,
     YYTASK = 321,
     YYTRI = 322,
     YYTRI0 = 323,
     YYTRI1 = 324,
     YYTRIAND = 325,
     YYTRIOR = 326,
     YYWAND = 327,
     YYWEAK0 = 328,
     YYWEAK1 = 329,
     YYWIRE = 330,
     YYWOR = 331,
     YYXNOR = 332,
     YYXOR = 333,
     YYDEFINE = 334,
     YYDEF_NULL = 335,
     PARALLEL_CASE = 336,
     FULL_CASE = 337,
     YYUNARYOPERATOR = 338
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


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




} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


