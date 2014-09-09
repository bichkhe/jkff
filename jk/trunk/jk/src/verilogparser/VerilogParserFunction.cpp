/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


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




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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


/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1889

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  256
/* YYNRULES -- Number of states.  */
#define YYNSTATES  454

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,     2,   102,     2,     2,    87,     2,
      97,    98,    92,    90,    99,    91,   103,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    96,
      88,   104,    89,    83,   107,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,   101,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   105,    85,   106,    93,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    95
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    10,    18,    22,    24,
      28,    30,    31,    33,    35,    37,    38,    41,    43,    45,
      47,    49,    51,    53,    55,    57,    59,    61,    63,    65,
      67,    69,    70,    78,    79,    88,    89,    91,    93,    95,
      96,    99,   101,   104,   106,   108,   110,   112,   114,   116,
     117,   123,   124,   130,   131,   137,   138,   144,   148,   152,
     154,   156,   158,   160,   162,   164,   166,   168,   170,   172,
     174,   175,   181,   182,   187,   188,   193,   194,   199,   201,
     205,   207,   211,   213,   220,   225,   227,   228,   230,   236,
     240,   242,   246,   250,   252,   254,   256,   258,   260,   262,
     264,   266,   268,   270,   272,   276,   280,   285,   287,   289,
     293,   295,   300,   302,   304,   305,   308,   310,   313,   316,
     319,   324,   326,   330,   334,   335,   341,   343,   345,   347,
     351,   353,   357,   358,   360,   361,   368,   369,   371,   374,
     375,   377,   378,   381,   383,   386,   392,   400,   408,   416,
     424,   434,   437,   443,   449,   451,   453,   457,   458,   462,
     466,   468,   471,   475,   479,   482,   486,   493,   495,   496,
     499,   501,   503,   504,   508,   509,   516,   518,   519,   523,
     525,   528,   529,   531,   533,   537,   539,   541,   545,   547,
     550,   553,   556,   559,   562,   565,   568,   571,   574,   577,
     581,   585,   589,   593,   597,   601,   605,   609,   613,   617,
     621,   625,   629,   633,   637,   641,   645,   649,   653,   657,
     663,   665,   667,   669,   670,   674,   676,   678,   680,   682,
     686,   689,   693,   699,   703,   710,   711,   717,   719,   720,
     725,   728,   731,   734,   739,   744,   749,   752,   757,   759,
     762,   765,   768,   772,   776,   778,   780
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     109,     0,    -1,    -1,   109,   110,    -1,   111,    -1,    -1,
      47,     3,   112,   113,    96,   119,    24,    -1,    97,   114,
      98,    -1,   115,    -1,   114,    99,   115,    -1,   116,    -1,
      -1,   117,    -1,   118,    -1,     3,    -1,    -1,   119,   120,
      -1,   130,    -1,   132,    -1,   134,    -1,   136,    -1,   138,
      -1,   140,    -1,   142,    -1,   155,    -1,   162,    -1,   146,
      -1,   144,    -1,   177,    -1,   121,    -1,   123,    -1,    -1,
      66,     3,   122,    96,   127,   178,    26,    -1,    -1,    28,
     125,     3,   124,    96,   128,   178,    25,    -1,    -1,   126,
      -1,   153,    -1,    35,    -1,    -1,   127,   129,    -1,   129,
      -1,   128,   129,    -1,   130,    -1,   132,    -1,   134,    -1,
     136,    -1,   140,    -1,   142,    -1,    -1,    55,   152,   131,
     154,    96,    -1,    -1,    34,   152,   133,   148,    96,    -1,
      -1,    54,   152,   135,   148,    96,    -1,    -1,    33,   152,
     137,   148,    96,    -1,   139,   154,    96,    -1,   139,   148,
      96,    -1,    65,    -1,    75,    -1,    67,    -1,    69,    -1,
      63,    -1,    72,    -1,    70,    -1,    68,    -1,    64,    -1,
      76,    -1,    71,    -1,    -1,    59,   152,   141,   149,    96,
      -1,    -1,    35,   143,   149,    96,    -1,    -1,    10,   145,
     154,    96,    -1,    -1,    19,   147,   154,    96,    -1,   206,
      -1,   148,    99,   206,    -1,   150,    -1,   149,    99,   150,
      -1,   151,    -1,   151,   100,   198,    84,   198,   101,    -1,
     151,   100,     4,   101,    -1,     3,    -1,    -1,   153,    -1,
     100,   198,    84,   198,   101,    -1,   100,     4,   101,    -1,
     182,    -1,   154,    99,   182,    -1,   156,   157,    96,    -1,
       9,    -1,    48,    -1,    53,    -1,    51,    -1,    78,    -1,
      77,    -1,    12,    -1,    13,    -1,    14,    -1,    52,    -1,
     158,    -1,   157,    99,   158,    -1,    97,   160,    98,    -1,
     159,    97,   160,    98,    -1,     3,    -1,   161,    -1,   160,
      99,   161,    -1,   198,    -1,   163,   164,   167,    96,    -1,
       3,    -1,     4,    -1,    -1,   164,   165,    -1,   166,    -1,
     102,     5,    -1,   102,     6,    -1,   102,   206,    -1,   102,
      97,   195,    98,    -1,   168,    -1,   167,    99,   168,    -1,
      97,   170,    98,    -1,    -1,   206,   169,    97,   170,    98,
      -1,   171,    -1,   172,    -1,   173,    -1,   171,    99,   173,
      -1,   174,    -1,   172,    99,   174,    -1,    -1,   198,    -1,
      -1,   103,   206,   175,    97,   176,    98,    -1,    -1,   198,
      -1,     8,   180,    -1,    -1,   180,    -1,    -1,   179,   180,
      -1,    96,    -1,   182,    96,    -1,    32,    97,   198,    98,
     180,    -1,    32,    97,   198,    98,   180,    20,   180,    -1,
      15,    97,   198,    98,   181,   183,    23,    -1,    17,    97,
     198,    98,   181,   183,    23,    -1,    16,    97,   198,    98,
     181,   183,    23,    -1,    27,    97,   182,    96,   198,    96,
     182,    98,   180,    -1,   209,   180,    -1,   192,   104,   208,
     198,    96,    -1,   192,    49,   208,   198,    96,    -1,   185,
      -1,   189,    -1,    10,   182,    96,    -1,    -1,   192,   104,
     198,    -1,   192,    49,   198,    -1,   184,    -1,   183,   184,
      -1,   197,    84,   180,    -1,    18,    84,   180,    -1,    18,
     180,    -1,    11,   179,    22,    -1,    11,    84,   186,   187,
     179,    22,    -1,     3,    -1,    -1,   187,   188,    -1,   130,
      -1,   140,    -1,    -1,     3,   190,    96,    -1,    -1,     3,
     191,    97,   197,    98,    96,    -1,   206,    -1,    -1,   206,
     193,   201,    -1,   202,    -1,     4,   194,    -1,    -1,   201,
      -1,   196,    -1,   195,    99,   196,    -1,   198,    -1,   198,
      -1,   197,    99,   198,    -1,   199,    -1,    90,   199,    -1,
      91,   199,    -1,    94,   199,    -1,    93,   199,    -1,    87,
     199,    -1,    85,   199,    -1,    86,   199,    -1,    40,   199,
      -1,    41,   199,    -1,    43,   199,    -1,   198,    90,   198,
      -1,   198,    91,   198,    -1,   198,    92,   198,    -1,   198,
      44,   198,    -1,   198,    45,   198,    -1,   198,    38,   198,
      -1,   198,    39,   198,    -1,   198,    37,   198,    -1,   198,
      42,   198,    -1,   198,    88,   198,    -1,   198,    89,   198,
      -1,   198,    87,   198,    -1,   198,    85,   198,    -1,   198,
      86,   198,    -1,   198,    36,   198,    -1,   198,    49,   198,
      -1,   198,    29,   198,    -1,   198,    46,   198,    -1,   198,
      60,   198,    -1,   198,    43,   198,    -1,   198,    83,   198,
      84,   198,    -1,     5,    -1,     6,    -1,   206,    -1,    -1,
     206,   200,   201,    -1,   202,    -1,   203,    -1,   204,    -1,
       7,    -1,    97,   198,    98,    -1,     4,   194,    -1,   100,
     198,   101,    -1,   100,   198,    84,   198,   101,    -1,   105,
     197,   106,    -1,   105,   198,   105,   197,   106,   106,    -1,
      -1,   206,    97,   205,   197,    98,    -1,     3,    -1,    -1,
     206,   103,   207,     3,    -1,   102,     5,    -1,   102,     6,
      -1,   102,   206,    -1,   102,    97,   196,    98,    -1,   107,
      97,   210,    98,    -1,   107,    97,   211,    98,    -1,   107,
      92,    -1,   107,    97,    92,    98,    -1,   198,    -1,    56,
     198,    -1,    50,   198,    -1,    21,   198,    -1,   210,   212,
     210,    -1,   211,   212,   210,    -1,    53,    -1,    42,    -1,
      99,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   334,   334,   337,   345,   394,   393,   413,   425,   432,
     440,   450,   454,   462,   482,   540,   544,   552,   557,   563,
     568,   572,   577,   586,   599,   604,   608,   612,   625,   630,
     634,   646,   645,   662,   661,   679,   683,   690,   695,   709,
     712,   719,   723,   730,   734,   738,   745,   753,   762,   779,
     779,   803,   802,   838,   837,   872,   871,   884,   893,   908,
     913,   921,   926,   932,   938,   944,   950,   956,   962,   968,
    1008,  1007,  1041,  1040,  1067,  1067,  1080,  1080,  1088,  1095,
    1104,  1111,  1119,  1125,  1133,  1143,  1278,  1282,  1290,  1297,
    1310,  1315,  1325,  1359,  1365,  1370,  1375,  1380,  1386,  1391,
    1396,  1401,  1406,  1478,  1484,  1492,  1497,  1506,  1514,  1521,
    1530,  1540,  1549,  1554,  1565,  1568,  1580,  1587,  1592,  1597,
    1602,  1610,  1615,  1626,  1631,  1631,  1639,  1644,  1652,  1657,
    1665,  1670,  1679,  1683,  1691,  1691,  1700,  1704,  1721,  1737,
    1741,  1750,  1754,  1763,  1768,  1774,  1781,  1789,  1797,  1802,
    1819,  1832,  1840,  1849,  1866,  1875,  1892,  1907,  1918,  1926,
    1936,  1942,  1950,  1957,  1963,  1971,  1978,  1997,  2006,  2009,
    2017,  2021,  2046,  2045,  2054,  2053,  2226,  2232,  2232,  2238,
    2244,  2252,  2253,  2258,  2263,  2271,  2283,  2289,  2298,  2303,
    2311,  2318,  2325,  2333,  2340,  2347,  2354,  2361,  2368,  2375,
    2384,  2393,  2415,  2423,  2431,  2439,  2447,  2456,  2464,  2472,
    2480,  2488,  2496,  2504,  2512,  2519,  2527,  2535,  2543,  2551,
    2563,  2569,  2575,  2580,  2580,  2587,  2592,  2598,  2603,  2609,
    2614,  2627,  2632,  2650,  2660,  2671,  2671,  2681,  2687,  2687,
    2698,  2702,  2706,  2710,  2722,  2729,  2735,  2739,  2753,  2758,
    2765,  2772,  2780,  2788,  2797,  2798,  2799
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "YYID", "YYDEF_ID", "YYINUMBER",
  "YYRNUMBER", "YYBIT_BASE_STRING", "YYALWAYS", "YYAND", "YYASSIGN",
  "YYBEGIN", "YYBUF", "YYBUFIF0", "YYBUFIF1", "YYCASE", "YYCASEX",
  "YYCASEZ", "YYDEFAULT", "YYDEFPARAM", "YYELSE", "YYEDGE", "YYEND",
  "YYENDCASE", "YYENDMODULE", "YYENDFUNCTION", "YYENDTASK", "YYFOR",
  "YYFUNCTION", "YYGEQ", "YYHIGHZ0", "YYHIGHZ1", "YYIF", "YYINOUT",
  "YYINPUT", "YYINTEGER", "YYLEQ", "YYLOGAND", "YYCASEEQUALITY",
  "YYCASEINEQUALITY", "YYLOGNAND", "YYLOGNOR", "YYLOGOR", "YYLOGXNOR",
  "YYLOGEQUALITY", "YYLOGINEQUALITY", "YYLSHIFT", "YYMODULE", "YYNAND",
  "YYNBASSIGN", "YYNEGEDGE", "YYNOR", "YYNOT", "YYOR", "YYOUTPUT",
  "YYPARAMETER", "YYPOSEDGE", "YYPULL0", "YYPULL1", "YYREG", "YYRSHIFT",
  "YYSTRONG0", "YYSTRONG1", "YYSUPPLY0", "YYSUPPLY1", "YYSWIRE", "YYTASK",
  "YYTRI", "YYTRI0", "YYTRI1", "YYTRIAND", "YYTRIOR", "YYWAND", "YYWEAK0",
  "YYWEAK1", "YYWIRE", "YYWOR", "YYXNOR", "YYXOR", "YYDEFINE",
  "YYDEF_NULL", "PARALLEL_CASE", "FULL_CASE", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'~'", "'!'",
  "YYUNARYOPERATOR", "';'", "'('", "')'", "','", "'['", "']'", "'#'",
  "'.'", "'='", "'{'", "'}'", "'@'", "$accept", "source_text",
  "description", "module", "$@1", "port_list_opt", "port_list", "port",
  "port_expression_opt", "port_expression", "port_reference",
  "module_item_clr", "module_item", "task", "$@2", "function", "$@3",
  "range_or_type_opt", "range_or_type", "tf_declaration_clr",
  "tf_declaration_eclr", "tf_declaration", "parameter_declaration", "$@4",
  "input_declaration", "$@5", "output_declaration", "$@6",
  "inout_declaration", "$@7", "net_declaration", "nettype",
  "reg_declaration", "$@8", "integer_declaration", "$@9",
  "continuous_assign", "$@10", "parameter_override", "$@11",
  "variable_list", "register_variable_list", "register_variable",
  "name_of_register", "range_opt", "range", "assignment_list",
  "gate_instantiation", "gatetype", "gate_instance_list", "gate_instance",
  "name_of_gate_instance", "terminal_list", "terminal",
  "module_or_primitive_instantiation", "name_of_module_or_primitive",
  "module_or_primitive_option_clr", "module_or_primitive_option",
  "delay_or_parameter_value_assignment",
  "module_or_primitive_instance_list", "module_or_primitive_instance",
  "$@12", "module_connection_list", "module_port_connection_list",
  "named_port_connection_list", "module_port_connection",
  "named_port_connection", "$@13", "connect_port", "always_statement",
  "statement_opt", "statement_clr", "statement", "synopsys_directive",
  "assignment", "case_item_eclr", "case_item", "seq_block",
  "name_of_block", "block_declaration_clr", "block_declaration",
  "task_enable", "$@14", "$@15", "lvalue", "$@16", "bit_exp",
  "mintypmax_expression_list", "mintypmax_expression", "expression_list",
  "expression", "primary", "$@17", "bitExpression", "concatenation",
  "multiple_concatenation", "function_call", "$@18", "identifier", "$@19",
  "delay_control", "event_control", "event_expression",
  "ored_event_expression", "or_expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,    63,    58,   124,    94,    38,    60,    62,
      43,    45,    42,   126,    33,   338,    59,    40,    41,    44,
      91,    93,    35,    46,    61,   123,   125,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   110,   112,   111,   113,   114,   114,
     115,   116,   116,   117,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   122,   121,   124,   123,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   131,
     130,   133,   132,   135,   134,   137,   136,   138,   138,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     141,   140,   143,   142,   145,   144,   147,   146,   148,   148,
     149,   149,   150,   150,   150,   151,   152,   152,   153,   153,
     154,   154,   155,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   157,   157,   158,   158,   159,   160,   160,
     161,   162,   163,   163,   164,   164,   165,   166,   166,   166,
     166,   167,   167,   168,   169,   168,   170,   170,   171,   171,
     172,   172,   173,   173,   175,   174,   176,   176,   177,   178,
     178,   179,   179,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   181,   182,   182,
     183,   183,   184,   184,   184,   185,   185,   186,   187,   187,
     188,   188,   190,   189,   191,   189,   192,   193,   192,   192,
     192,   194,   194,   195,   195,   196,   197,   197,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     199,   199,   199,   200,   199,   199,   199,   199,   199,   199,
     199,   201,   201,   202,   203,   205,   204,   206,   207,   206,
     208,   208,   208,   208,   209,   209,   209,   209,   210,   210,
     210,   210,   211,   211,   212,   212,   212
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     7,     3,     1,     3,
       1,     0,     1,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     7,     0,     8,     0,     1,     1,     1,     0,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     0,
       5,     0,     5,     0,     5,     0,     5,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     4,     0,     4,     0,     4,     1,     3,
       1,     3,     1,     6,     4,     1,     0,     1,     5,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     1,     1,     3,
       1,     4,     1,     1,     0,     2,     1,     2,     2,     2,
       4,     1,     3,     3,     0,     5,     1,     1,     1,     3,
       1,     3,     0,     1,     0,     6,     0,     1,     2,     0,
       1,     0,     2,     1,     2,     5,     7,     7,     7,     7,
       9,     2,     5,     5,     1,     1,     3,     0,     3,     3,
       1,     2,     3,     3,     2,     3,     6,     1,     0,     2,
       1,     1,     0,     3,     0,     6,     1,     0,     3,     1,
       2,     0,     1,     1,     3,     1,     1,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       1,     1,     1,     0,     3,     1,     1,     1,     1,     3,
       2,     3,     5,     3,     6,     0,     5,     1,     0,     4,
       2,     2,     2,     4,     4,     4,     2,     4,     1,     2,
       2,     2,     3,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     3,     4,     5,     0,    11,     0,
      14,     0,     8,    10,    12,    13,    15,     7,    11,     0,
       9,   112,   113,     0,    93,    74,    99,   100,   101,    76,
       6,    35,    86,    86,    72,    94,    96,   102,    95,    86,
      86,    86,    63,    67,    59,     0,    61,    66,    62,    65,
      69,    64,    60,    68,    98,    97,    16,    29,    30,    17,
      18,    19,    20,    21,     0,    22,    23,    27,    26,    24,
       0,    25,   114,    28,   237,   181,     0,   141,     0,     0,
       0,     0,     0,   143,     0,     0,   138,     0,   154,   155,
       0,   179,   176,     0,     0,     0,    38,     0,     0,    36,
      37,    55,    87,    51,     0,    53,    49,    70,    31,   237,
       0,     0,    90,     0,    78,   107,     0,     0,   103,     0,
       0,     0,     0,     0,   180,   182,     0,     0,     0,     0,
       0,     0,     0,     0,   181,   220,   221,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,   188,   225,   226,   227,   222,   246,     0,   144,
       0,     0,   238,     0,   151,     0,     0,   181,     0,    33,
       0,     0,    85,     0,    80,    82,     0,     0,     0,     0,
      58,     0,    57,     0,     0,     0,     0,   108,   110,    92,
       0,     0,   132,     0,   115,   116,     0,   121,   124,   173,
       0,     0,   156,   167,   168,   165,   142,     0,     0,     0,
       0,     0,   230,   196,   197,   198,   194,   195,   193,   189,
     190,   192,   191,     0,   186,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,     0,
       0,     0,     0,     0,   248,     0,     0,     0,   159,     0,
     158,     0,     0,   178,    75,    77,    89,     0,     0,     0,
      78,     0,    73,     0,     0,     0,     0,     0,    39,    79,
      91,   105,     0,   104,     0,     0,     0,   126,   127,   128,
     130,   133,   117,   118,     0,   119,   111,     0,     0,     0,
       0,   231,   141,   157,   157,   157,     0,     0,   229,     0,
     187,   215,   213,   206,   204,   205,   207,   218,   202,   203,
     216,   214,   217,     0,   211,   212,   210,   208,   209,   199,
     200,   201,     0,   224,   251,   250,   249,   247,   255,   254,
     244,   256,     0,   245,     0,   240,   241,     0,   242,     0,
       0,   239,     0,     0,    56,    52,    81,   181,     0,    54,
      50,    71,   139,   109,   106,   134,   123,   132,     0,     0,
     183,   185,   122,   132,     0,     0,   170,   171,     0,   169,
       0,     0,     0,     0,   145,     0,     0,     0,   252,   253,
       0,   153,   152,    88,   139,    41,    43,    44,    45,    46,
      47,    48,    84,     0,    40,     0,   140,     0,   129,   131,
     120,     0,     0,   175,   232,   166,     0,     0,   160,     0,
       0,     0,     0,     0,     0,   219,   236,   243,    42,     0,
       0,    32,   136,   184,   125,     0,   164,   147,   161,     0,
     149,   148,     0,   146,   234,    34,    83,     0,   137,   163,
     162,     0,   135,   150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,     5,     7,     9,    11,    12,    13,    14,
      15,    19,    56,    57,   179,    58,   268,    98,    99,   362,
     394,   395,   396,   177,   397,   171,   398,   176,   399,   170,
      63,    64,   400,   178,   401,   104,    67,    94,    68,    95,
     110,   173,   174,   175,   101,   102,   111,    69,    70,   117,
     118,   119,   186,   187,    71,    72,   120,   194,   195,   196,
     197,   298,   286,   287,   288,   289,   290,   407,   447,    73,
     405,   128,   206,   380,    87,   417,   418,    88,   204,   302,
     379,    89,   121,   122,    90,   163,   212,   369,   370,   419,
     151,   152,   249,   125,   153,   154,   155,   332,   156,   262,
     259,    93,   255,   256,   342
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -341
static const yytype_int16 yypact[] =
{
    -341,    15,  -341,    33,  -341,  -341,  -341,   -42,    88,   -28,
    -341,    36,  -341,  -341,  -341,  -341,  -341,  -341,    88,  1135,
    -341,  -341,  -341,   228,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,   -21,   -41,   -41,  -341,  -341,  -341,  -341,  -341,   -41,
     -41,   -41,  -341,  -341,  -341,   108,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,    14,  -341,  -341,  -341,  -341,  -341,
       7,  -341,  -341,  -341,     6,    25,    14,    67,    70,    75,
      81,   132,   138,  -341,   949,   -34,  -341,   152,  -341,  -341,
     -37,  -341,   -77,   228,    14,    14,  -341,   975,   251,  -341,
    -341,  -341,  -341,  -341,   255,  -341,  -341,  -341,  -341,  -341,
      -4,    27,  -341,   -16,   -43,  -341,   949,    37,  -341,   168,
       4,   170,   171,   949,  -341,  -341,   173,   264,   165,   949,
     949,   949,    14,   949,    25,  -341,  -341,  -341,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,   949,   949,
     -54,  1721,  -341,  -341,  -341,  -341,    43,  -341,   581,  -341,
     813,   813,  -341,    25,  -341,    56,    60,   -18,  1619,  -341,
     268,   268,  -341,    65,  -341,   175,   268,    14,   255,   177,
    -341,   268,  -341,    14,   949,   949,    46,  -341,  1721,  -341,
       7,   949,   854,    24,  -341,  -341,    78,  -341,   174,  -341,
     949,  1136,  -341,  -341,  -341,  -341,  -341,   435,  1306,  1370,
     180,  1389,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,  1453,  1045,   949,  -341,   949,   949,   949,
     949,   949,   949,   949,   949,   949,   949,   949,   949,   949,
     949,   949,   949,   949,   949,   949,   949,   949,  -341,    25,
     949,   949,   949,   181,  1721,    97,   120,    32,  1721,   949,
    1721,   949,   275,  -341,  -341,  -341,  -341,   949,   184,    87,
     174,   112,  -341,   255,  1016,   134,   150,   151,  -341,   174,
    -341,  -341,   949,  -341,    86,   268,   183,   191,   192,  -341,
    -341,  1721,  -341,  -341,   949,   174,  -341,    16,   185,   100,
     949,  -341,   -13,  -341,  -341,  -341,   949,   228,  -341,   949,
    1721,   -26,   -26,  1797,   358,   358,  1785,   274,   358,   358,
     161,   -26,   161,  1638,   416,   274,   292,   -26,   -26,   197,
     197,  -341,   949,  -341,  1721,  1721,  1721,  -341,  -341,  -341,
    -341,  -341,   640,  -341,   640,  -341,  -341,   949,   174,  1472,
    1536,  -341,  1202,   169,  -341,  -341,  -341,   109,  1702,  -341,
    -341,  -341,    83,  -341,  -341,   174,  -341,   949,   193,   117,
    -341,  1721,  -341,   854,   187,  1221,  -341,  -341,   190,  -341,
     920,   920,   920,  1555,   273,   -10,   949,   142,  -341,  -341,
     200,  -341,  -341,  -341,    83,  -341,  -341,  -341,  -341,  -341,
    -341,  -341,  -341,   949,  -341,   276,  -341,   202,  -341,  -341,
    -341,   949,   203,  -341,  -341,  -341,   210,   695,  -341,   -56,
     750,   791,    14,   228,   194,  1721,  -341,  -341,  -341,   279,
    1287,  -341,   949,  -341,  -341,   228,  -341,  -341,  -341,   228,
    -341,  -341,   207,  -341,  -341,  -341,  -341,   209,  1721,  -341,
    -341,   228,  -341,  -341
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -341,  -341,  -341,  -341,  -341,  -341,  -341,   290,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
    -341,  -340,   -17,  -341,   295,  -341,   297,  -341,   303,  -341,
    -341,  -341,   -14,  -341,   306,  -341,  -341,  -341,  -341,  -341,
      -5,   131,    38,  -341,    91,   296,   -70,  -341,  -341,  -341,
     136,  -341,   141,    47,  -341,  -341,  -341,  -341,  -341,  -341,
      48,  -341,   -33,  -341,  -341,   -24,   -22,  -341,  -341,  -341,
     -50,    49,   -15,   -48,   -63,  -118,  -336,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,   -55,  -341,   278,  -341,  -331,   -73,
     309,   454,  -341,  -159,   -20,  -341,  -341,  -341,   -23,  -341,
     188,  -341,  -153,  -341,    92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -224
static const yytype_int16 yytable[] =
{
      92,   112,    59,    91,   263,    65,  -176,   109,    86,   113,
     115,   150,   160,   126,    96,     2,   390,   109,    75,   109,
     236,   113,   404,  -177,   165,   166,   162,   109,   439,   292,
     293,   112,   112,   184,   238,   109,     6,   345,   346,   113,
     113,   114,    40,   225,    91,   225,    41,   109,   134,   135,
     136,   137,   226,    92,   428,     8,    91,  -177,   157,    97,
     162,  -176,     3,   158,   245,   246,   247,   161,    16,   210,
      92,    92,    92,    91,    91,    91,   150,   113,   164,    97,
     433,   438,   123,   266,   438,   438,    74,    75,   185,   225,
     333,    10,   180,    76,    77,   181,   424,   198,    78,    79,
      80,   192,  -172,  -174,   116,    92,   193,   276,    91,    92,
      81,   108,    91,   192,   112,    82,    32,    33,    34,    84,
     280,   294,   113,   182,   103,   123,   183,   299,   113,   347,
     105,   106,   107,   189,    17,    18,   190,    39,    40,   338,
     248,   148,    41,  -223,   281,   282,   162,   270,   270,   149,
     339,   127,   264,   270,    92,   183,   265,    91,   279,   183,
      92,   272,   338,    91,   273,   269,   271,   129,    74,    75,
     295,   275,   130,   339,   296,    76,    77,   297,   131,    83,
      78,    79,    80,   354,   364,   282,   181,   205,    84,   388,
      85,   389,    81,    74,    75,   340,   341,    82,   374,   225,
      76,    77,    32,    33,    34,    78,    79,    80,   355,   123,
     402,   181,   415,    74,    75,   410,   411,    81,   343,   341,
      76,    77,    82,    39,    40,    78,    79,    80,    41,   132,
     359,    74,    75,   181,   348,   133,   385,    81,    76,    77,
     426,   225,    82,    78,    79,    80,   360,   361,   159,   183,
     273,   245,   246,   247,   169,    81,   381,   382,   172,   387,
      82,    83,   365,   420,   421,   191,   199,   203,   200,   202,
      84,   109,    85,   278,   198,   274,   306,   162,   351,   337,
     353,   366,   373,   413,    92,   376,    83,    91,   377,   247,
     367,   368,   384,   423,   435,    84,   285,    85,   427,   432,
     444,   434,   431,   227,   445,   451,    83,   452,    20,   277,
     228,   356,   230,   231,    60,    84,    61,    85,   234,   235,
     236,   227,    62,   237,    83,    66,   283,   100,   228,   363,
     230,   231,   284,    84,   238,    85,   234,   235,   236,    92,
     412,   237,    91,   408,   429,   372,   409,   406,   344,   261,
       0,   378,   238,   124,     0,    92,     0,     0,    91,   442,
       0,   242,   243,   244,   245,   246,   247,   113,     0,     0,
       0,    92,     0,     0,    91,     0,     0,     0,     0,   406,
     243,   244,   245,   246,   247,     0,     0,   227,     0,     0,
       0,     0,     0,    92,   228,     0,    91,     0,     0,    92,
      92,   436,    91,    91,   236,     0,   168,   237,   443,     0,
       0,     0,    92,     0,     0,    91,    92,     0,   238,    91,
     449,     0,     0,     0,   450,   188,     0,     0,    92,     0,
       0,    91,   201,     0,     0,     0,   453,     0,   207,   208,
     209,     0,   211,     0,     0,   227,   243,   244,   245,   246,
     247,     0,   228,     0,   230,   231,     0,   223,   224,   233,
     234,   235,   236,     0,   227,   237,     0,   254,     0,   258,
     260,   228,   229,   230,   231,     0,   238,   232,   233,   234,
     235,   236,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   260,   238,     0,     0,     0,     0,
     188,   291,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,   303,   310,     0,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,   334,
     335,   336,     0,     0,     0,     0,     0,     0,   349,     0,
     350,     0,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,   358,   109,   134,   135,   136,   137,     0,
       0,   188,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   250,   371,     0,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,   383,     0,     0,     0,     0,
       0,   138,   139,     0,   140,     0,     0,     0,     0,     0,
       0,   251,     0,     0,     0,     0,     0,   252,     0,     0,
       0,     0,     0,   109,   134,   135,   136,   137,     0,     0,
       0,   254,     0,   254,     0,     0,   371,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   141,   142,   143,     0,
       0,   144,   145,   253,   146,   147,   291,     0,   148,     0,
     138,   139,   291,   140,     0,     0,   149,     0,     0,     0,
     251,     0,     0,     0,     0,   425,   252,     0,   109,   134,
     135,   136,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,   416,     0,     0,     0,     0,   437,     0,
     371,     0,     0,     0,     0,   141,   142,   143,     0,     0,
     144,   145,     0,   146,   147,   138,   139,   148,   140,     0,
       0,   448,     0,     0,     0,   149,     0,     0,     0,     0,
       0,     0,     0,   109,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   416,     0,
       0,     0,     0,   440,     0,     0,     0,     0,     0,     0,
     141,   142,   143,     0,     0,   144,   145,     0,   146,   147,
     138,   139,   148,   140,   109,   134,   135,   136,   137,     0,
     149,     0,     0,     0,     0,     0,     0,     0,     0,   416,
       0,     0,     0,     0,   441,     0,   109,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,     0,   140,   141,   142,   143,     0,     0,
     144,   145,     0,   146,   147,     0,     0,   148,     0,     0,
       0,     0,     0,   138,   139,   149,   140,   109,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,     0,
       0,   144,   145,     0,   146,   147,     0,     0,   148,     0,
       0,     0,     0,     0,   138,   139,   149,   140,   141,   142,
     143,     0,     0,   144,   145,     0,   146,   147,     0,     0,
     148,     0,     0,     0,     0,   257,     0,     0,   149,     0,
       0,     0,     0,   109,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   416,   141,
     142,   143,     0,     0,   144,   145,     0,   146,   147,     0,
       0,   148,   109,   134,   135,   136,   137,   285,     0,   149,
     138,   139,     0,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   167,
     135,   136,   137,     0,     0,     0,     0,     0,     0,   138,
     139,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,   143,     0,     0,
     144,   145,     0,   146,   147,   138,   139,   148,   140,   109,
     357,   135,   136,   137,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,     0,     0,   144,
     145,     0,   146,   147,     0,     0,   148,     0,     0,     0,
       0,     0,     0,     0,   149,     0,   138,   139,     0,   140,
     141,   142,   143,     0,     0,   144,   145,     0,   146,   147,
       0,     0,   148,     0,   227,     0,     0,     0,     0,     0,
     149,   228,   229,   230,   231,     0,     0,   232,   233,   234,
     235,   236,     0,     0,   237,     0,     0,     0,     0,     0,
       0,   141,   142,   143,     0,   238,   144,   145,     0,   146,
     147,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,     0,     0,     0,   239,     0,
     240,   241,   242,   243,   244,   245,   246,   247,    21,    22,
       0,     0,     0,    23,    24,    25,     0,    26,    27,    28,
     309,     0,     0,     0,    29,     0,     0,     0,     0,    30,
       0,     0,     0,    31,     0,   227,     0,     0,    32,    33,
      34,     0,   228,   229,   230,   231,     0,     0,   232,   233,
     234,   235,   236,    35,     0,   237,    36,    37,    38,    39,
      40,     0,     0,     0,    41,     0,   238,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     0,     0,
      52,    53,    54,    55,     0,     0,     0,     0,     0,   239,
     300,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,   227,     0,     0,     0,     0,     0,   301,   228,   229,
     230,   231,     0,     0,   232,   233,   234,   235,   236,     0,
     227,   237,     0,     0,     0,     0,     0,   228,   229,   230,
     231,     0,   238,   232,   233,   234,   235,   236,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,   239,     0,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   393,   239,     0,   240,   241,   242,   243,
     244,   245,   246,   247,     0,     0,   227,     0,     0,     0,
       0,     0,   414,   228,   229,   230,   231,     0,     0,   232,
     233,   234,   235,   236,     0,   227,   237,     0,     0,     0,
       0,     0,   228,   229,   230,   231,     0,   238,   232,   233,
     234,   235,   236,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,     0,
     239,     0,   240,   241,   242,   243,   244,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   446,   239,
       0,   240,   241,   242,   243,   244,   245,   246,   247,   227,
       0,     0,     0,     0,   304,     0,   228,   229,   230,   231,
       0,     0,   232,   233,   234,   235,   236,     0,   227,   237,
       0,     0,     0,     0,     0,   228,   229,   230,   231,     0,
     238,   232,   233,   234,   235,   236,     0,     0,   237,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,   239,     0,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,   305,     0,
       0,     0,   239,     0,   240,   241,   242,   243,   244,   245,
     246,   247,   227,     0,     0,     0,     0,   307,     0,   228,
     229,   230,   231,     0,     0,   232,   233,   234,   235,   236,
       0,   227,   237,     0,     0,     0,     0,     0,   228,   229,
     230,   231,     0,   238,   232,   233,   234,   235,   236,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,     0,     0,   239,     0,   240,   241,
     242,   243,   244,   245,   246,   247,     0,     0,     0,     0,
       0,   308,     0,     0,     0,   239,     0,   240,   241,   242,
     243,   244,   245,   246,   247,   227,     0,     0,   391,     0,
       0,     0,   228,   229,   230,   231,     0,     0,   232,   233,
     234,   235,   236,     0,   227,   237,     0,     0,     0,     0,
       0,   228,   229,   230,   231,     0,   238,   232,   233,   234,
     235,   236,     0,     0,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,     0,   239,
       0,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,   392,     0,     0,     0,     0,     0,   239,     0,
     240,   241,   242,   243,   244,   245,   246,   247,   227,     0,
       0,   422,     0,     0,     0,   228,   229,   230,   231,     0,
       0,   232,   233,   234,   235,   236,     0,   227,   237,     0,
       0,     0,     0,     0,   228,   229,   230,   231,     0,   238,
     232,   233,   234,   235,   236,     0,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
       0,     0,   239,   267,   240,   241,   242,   243,   244,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   386,   240,   241,   242,   243,   244,   245,   246,
     247,   227,     0,     0,     0,     0,     0,     0,   228,   229,
     230,   231,     0,     0,   232,   233,   234,   235,   236,     0,
     227,   237,     0,     0,     0,     0,     0,   228,   229,   230,
     231,     0,   238,   232,   233,   234,   235,   236,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,   239,   403,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,   240,   241,   242,   243,
     244,   245,   246,   247,   227,     0,     0,     0,     0,     0,
       0,   228,   229,   230,   231,     0,   227,     0,   233,   234,
     235,   236,     0,   228,   237,   230,   231,     0,     0,     0,
     233,   234,   235,   236,     0,   238,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,   240,   241,   242,   243,   244,   245,   246,   247
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-341))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      23,    64,    19,    23,   163,    19,    49,     3,    23,    64,
       3,    84,    49,    76,    35,     0,   347,     3,     4,     3,
      46,    76,   362,   100,    94,    95,   103,     3,    84,     5,
       6,    94,    95,    49,    60,     3,     3,     5,     6,    94,
      95,    64,    55,    99,    64,    99,    59,     3,     4,     5,
       6,     7,   106,    76,   394,    97,    76,   100,    92,   100,
     103,   104,    47,    97,    90,    91,    92,   104,    96,   132,
      93,    94,    95,    93,    94,    95,   149,   132,    93,   100,
     411,   417,   100,   101,   420,   421,     3,     4,   104,    99,
     249,     3,    96,    10,    11,    99,   106,   120,    15,    16,
      17,    97,    96,    97,    97,   128,   102,   177,   128,   132,
      27,     3,   132,    97,   177,    32,    33,    34,    35,   105,
     183,    97,   177,    96,    33,   100,    99,   200,   183,    97,
      39,    40,    41,    96,    98,    99,    99,    54,    55,    42,
      97,    97,    59,   100,    98,    99,   103,   170,   171,   105,
      53,    84,    96,   176,   177,    99,    96,   177,   181,    99,
     183,    96,    42,   183,    99,   170,   171,    97,     3,     4,
     193,   176,    97,    53,    96,    10,    11,    99,    97,    96,
      15,    16,    17,    96,    98,    99,    99,    22,   105,   342,
     107,   344,    27,     3,     4,    98,    99,    32,    98,    99,
      10,    11,    33,    34,    35,    15,    16,    17,    96,   100,
     101,    99,    22,     3,     4,    98,    99,    27,    98,    99,
      10,    11,    32,    54,    55,    15,    16,    17,    59,    97,
      96,     3,     4,    99,   257,    97,   309,    27,    10,    11,
      98,    99,    32,    15,    16,    17,    96,    96,    96,    99,
      99,    90,    91,    92,     3,    27,   304,   305,     3,   332,
      32,    96,   285,   381,   382,    97,    96,     3,    97,    96,
     105,     3,   107,    96,   297,   100,    96,   103,     3,    98,
      96,    98,    97,    96,   307,   302,    96,   307,   302,    92,
      99,    99,   307,    20,    84,   105,   103,   107,    98,    97,
     106,    98,    26,    29,    25,    98,    96,    98,    18,   178,
      36,   273,    38,    39,    19,   105,    19,   107,    44,    45,
      46,    29,    19,    49,    96,    19,   190,    31,    36,   282,
      38,    39,   191,   105,    60,   107,    44,    45,    46,   362,
     373,    49,   362,   367,   394,   297,   368,   362,   256,   161,
      -1,   302,    60,    75,    -1,   378,    -1,    -1,   378,   422,
      -1,    87,    88,    89,    90,    91,    92,   422,    -1,    -1,
      -1,   394,    -1,    -1,   394,    -1,    -1,    -1,    -1,   394,
      88,    89,    90,    91,    92,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,   416,    36,    -1,   416,    -1,    -1,   422,
     423,   416,   422,   423,    46,    -1,    97,    49,   423,    -1,
      -1,    -1,   435,    -1,    -1,   435,   439,    -1,    60,   439,
     435,    -1,    -1,    -1,   439,   116,    -1,    -1,   451,    -1,
      -1,   451,   123,    -1,    -1,    -1,   451,    -1,   129,   130,
     131,    -1,   133,    -1,    -1,    29,    88,    89,    90,    91,
      92,    -1,    36,    -1,    38,    39,    -1,   148,   149,    43,
      44,    45,    46,    -1,    29,    49,    -1,   158,    -1,   160,
     161,    36,    37,    38,    39,    -1,    60,    42,    43,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   185,    60,    -1,    -1,    -1,    -1,
     191,   192,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    98,   225,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,   250,
     251,   252,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,
     261,    -1,    -1,    -1,    -1,    -1,   267,    -1,    -1,    -1,
      -1,    -1,    -1,   274,     3,     4,     5,     6,     7,    -1,
      -1,   282,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    21,   294,    -1,    -1,    -1,    -1,    -1,   300,
      -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   342,    -1,   344,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,
      -1,    90,    91,    92,    93,    94,   367,    -1,    97,    -1,
      40,    41,   373,    43,    -1,    -1,   105,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,   386,    56,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   403,    18,    -1,    -1,    -1,    -1,    23,    -1,
     411,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,
      90,    91,    -1,    93,    94,    40,    41,    97,    43,    -1,
      -1,   432,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    -1,    -1,    90,    91,    -1,    93,    94,
      40,    41,    97,    43,     3,     4,     5,     6,     7,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    23,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    43,    85,    86,    87,    -1,    -1,
      90,    91,    -1,    93,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    40,    41,   105,    43,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,
      -1,    90,    91,    -1,    93,    94,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    40,    41,   105,    43,    85,    86,
      87,    -1,    -1,    90,    91,    -1,    93,    94,    -1,    -1,
      97,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    85,
      86,    87,    -1,    -1,    90,    91,    -1,    93,    94,    -1,
      -1,    97,     3,     4,     5,     6,     7,   103,    -1,   105,
      40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,
      90,    91,    -1,    93,    94,    40,    41,    97,    43,     3,
       4,     5,     6,     7,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,    90,
      91,    -1,    93,    94,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    40,    41,    -1,    43,
      85,    86,    87,    -1,    -1,    90,    91,    -1,    93,    94,
      -1,    -1,    97,    -1,    29,    -1,    -1,    -1,    -1,    -1,
     105,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    -1,    60,    90,    91,    -1,    93,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,     3,     4,
      -1,    -1,    -1,     8,     9,    10,    -1,    12,    13,    14,
     105,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    -1,    29,    -1,    -1,    33,    34,
      35,    -1,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    45,    46,    48,    -1,    49,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    59,    -1,    60,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,   101,    36,    37,
      38,    39,    -1,    -1,    42,    43,    44,    45,    46,    -1,
      29,    49,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    -1,    60,    42,    43,    44,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,   101,    36,    37,    38,    39,    -1,    -1,    42,
      43,    44,    45,    46,    -1,    29,    49,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    60,    42,    43,
      44,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    29,
      -1,    -1,    -1,    -1,    98,    -1,    36,    37,    38,    39,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    29,    49,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,
      60,    42,    43,    44,    45,    46,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    29,    -1,    -1,    -1,    -1,    98,    -1,    36,
      37,    38,    39,    -1,    -1,    42,    43,    44,    45,    46,
      -1,    29,    49,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    60,    42,    43,    44,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    29,    -1,    -1,    96,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    29,    49,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    -1,    60,    42,    43,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    29,    -1,
      -1,    96,    -1,    -1,    -1,    36,    37,    38,    39,    -1,
      -1,    42,    43,    44,    45,    46,    -1,    29,    49,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    -1,    60,
      42,    43,    44,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    -1,    42,    43,    44,    45,    46,    -1,
      29,    49,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    -1,    60,    42,    43,    44,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    -1,    29,    -1,    43,    44,
      45,    46,    -1,    36,    49,    38,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    60,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    91,    92
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   109,     0,    47,   110,   111,     3,   112,    97,   113,
       3,   114,   115,   116,   117,   118,    96,    98,    99,   119,
     115,     3,     4,     8,     9,    10,    12,    13,    14,    19,
      24,    28,    33,    34,    35,    48,    51,    52,    53,    54,
      55,    59,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    75,    76,    77,    78,   120,   121,   123,   130,
     132,   134,   136,   138,   139,   140,   142,   144,   146,   155,
     156,   162,   163,   177,     3,     4,    10,    11,    15,    16,
      17,    27,    32,    96,   105,   107,   180,   182,   185,   189,
     192,   202,   206,   209,   145,   147,    35,   100,   125,   126,
     153,   152,   153,   152,   143,   152,   152,   152,     3,     3,
     148,   154,   182,   192,   206,     3,    97,   157,   158,   159,
     164,   190,   191,   100,   194,   201,   182,    84,   179,    97,
      97,    97,    97,    97,     4,     5,     6,     7,    40,    41,
      43,    85,    86,    87,    90,    91,    93,    94,    97,   105,
     197,   198,   199,   202,   203,   204,   206,    92,    97,    96,
      49,   104,   103,   193,   180,   154,   154,     4,   198,     3,
     137,   133,     3,   149,   150,   151,   135,   131,   141,   122,
      96,    99,    96,    99,    49,   104,   160,   161,   198,    96,
      99,    97,    97,   102,   165,   166,   167,   168,   206,    96,
      97,   198,    96,     3,   186,    22,   180,   198,   198,   198,
     182,   198,   194,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   198,   198,    99,   106,    29,    36,    37,
      38,    39,    42,    43,    44,    45,    46,    49,    60,    83,
      85,    86,    87,    88,    89,    90,    91,    92,    97,   200,
      21,    50,    56,    92,   198,   210,   211,   102,   198,   208,
     198,   208,   207,   201,    96,    96,   101,    84,   124,   148,
     206,   148,    96,    99,   100,   148,   154,   149,    96,   206,
     182,    98,    99,   158,   160,   103,   170,   171,   172,   173,
     174,   198,     5,     6,    97,   206,    96,    99,   169,   197,
      84,   101,   187,    98,    98,    98,    96,    98,    98,   105,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   205,   201,   198,   198,   198,    98,    42,    53,
      98,    99,   212,    98,   212,     5,     6,    97,   206,   198,
     198,     3,   198,    96,    96,    96,   150,     4,   198,    96,
      96,    96,   127,   161,    98,   206,    98,    99,    99,   195,
     196,   198,   168,    97,    98,   198,   130,   140,   179,   188,
     181,   181,   181,   198,   180,   197,    84,   197,   210,   210,
     196,    96,    96,   101,   128,   129,   130,   132,   134,   136,
     140,   142,   101,    84,   129,   178,   180,   175,   173,   174,
      98,    99,   170,    96,   101,    22,    18,   183,   184,   197,
     183,   183,    96,    20,   106,   198,    98,    98,   129,   178,
     198,    26,    97,   196,    98,    84,   180,    23,   184,    84,
      23,    23,   182,   180,   106,    25,   101,   176,   198,   180,
     180,    98,    98,   180
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
//@
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
             YYTRACE("sorce_text:");
          }
    break;

  case 3:

    {
             YYTRACE("source_text: source_text description");
           
          }
    break;

  case 4:

    {
             YYTRACE("description: module");
            
          }
    break;

  case 5:

    {
  		VP->currentModulePtr = mFactory->MakeModule(*(yyvsp[(2) - (2)].stringPtr));
	
  	}
    break;

  case 6:

    {
           	YYTRACE("module: YYMODULE YYID port_list_opt ';' module_item_clr YYENDMODULE");
	   	cout<<"Make ModuleNode\n";
	   	(yyval.modulePtr) = VP->currentModulePtr;
		(yyval.modulePtr)-> AddChild((yyvsp[(4) - (7)].basePtr));
		(yyval.modulePtr)-> AddChild((yyvsp[(6) - (7)].basePtr));
         }
    break;

  case 7:

    {
             YYTRACE("port_list_opt: '(' port_list ')'");
		(yyval.basePtr) = (yyvsp[(2) - (3)].basePtr);
          }
    break;

  case 8:

    {
             YYTRACE("port_list: port");
		cout<<"Make Port List\n";
		(yyval.basePtr) = mFactory->MakePortList();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (1)].basePtr));
          }
    break;

  case 9:

    {
             YYTRACE("port_list: port_list ',' port");
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          }
    break;

  case 10:

    {
             YYTRACE("port: port_expression_opt");
		(yyval.basePtr) =(yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 11:

    {
              YYTRACE("port_expression_opt:");
               (yyval.basePtr) = NULL;
           }
    break;

  case 12:

    {
              YYTRACE("port_expression_opt: port_expression");
		(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
           }
    break;

  case 13:

    {
             YYTRACE("port_expression: port_reference");
           	(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 14:

    {
		cout<<"Make Port\n";
            	(yyval.basePtr) = mFactory->MakeIdentifier(*(yyvsp[(1) - (1)].stringPtr));
	  }
    break;

  case 15:

    {
             YYTRACE("module_item_clr:");
		(yyval.basePtr)=mFactory->MakeModuleItem();
          }
    break;

  case 16:

    {
             YYTRACE("module_item_clr: module_item_clr module_item");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
          }
    break;

  case 17:

    {
             YYTRACE("module_item: parameter_declaration");
		(yyval.basePtr) = (yyvsp[(1) - (1)].paramPtr);
          }
    break;

  case 18:

    {
             YYTRACE("module_item: input_declaration");
		
		(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 19:

    {
             YYTRACE("module_item: output_declaration");
		(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 20:

    {
             YYTRACE("module_item: inout_declaration");
          }
    break;

  case 21:

    {
             YYTRACE("module_item: net_declaration");
            	(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 22:

    {
             YYTRACE("module_item: reg_declaration");
		(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 23:

    {
             YYTRACE("module_item: integer_declaration");
          }
    break;

  case 24:

    {
             YYTRACE("module_item: gate_instantiation");
		(yyval.basePtr)=(yyvsp[(1) - (1)].primitivePtr);
          }
    break;

  case 25:

    {
             YYTRACE("module_item: module_or_primitive_instantiation");
          }
    break;

  case 26:

    {
             YYTRACE("module_item: parameter_override");
          }
    break;

  case 27:

    {
             YYTRACE("module_item: continous_assign");
		(yyval.basePtr)=(yyvsp[(1) - (1)].assignPtr);
          }
    break;

  case 28:

    {
             YYTRACE("module_item: always_statement");
             (yyval.basePtr) = (yyvsp[(1) - (1)].alwaysPtr);
          }
    break;

  case 29:

    {
             YYTRACE("module_item: task");
          }
    break;

  case 30:

    {
             YYTRACE("module_item: function");
          }
    break;

  case 31:

    {
             scopeState = TASK;
	          
					}
    break;

  case 32:

    {
             YYTRACE("YYTASK YYID ';' tf_declaration_clr statement_opt YYENDTASK");
             
             scopeState = MODULE;
             
          }
    break;

  case 33:

    {
	          
             scopeState = FUNCTION;
           
	  }
    break;

  case 34:

    {
             YYTRACE("YYFUNCTION range_or_type_opt YYID ';' tf_declaration_eclr statement_opt YYENDFUNCTION");
           
             scopeState = MODULE;
            
          }
    break;

  case 35:

    {
             YYTRACE("range_or_type_opt:");
            
          }
    break;

  case 36:

    {
             YYTRACE("range_or_type_opt: range_or_type");
          }
    break;

  case 37:

    {
             YYTRACE("range_or_type: range");
             isInteger = false;
          }
    break;

  case 38:

    {
             YYTRACE("range_or_type: YYINTEGER");
             
             isInteger = true;
          }
    break;

  case 39:

    {
             YYTRACE("tf_declaration_clr:");
          }
    break;

  case 40:

    {
             YYTRACE("tf_declaration_clr: tf_declaration_clr tf_declaration");
          }
    break;

  case 41:

    {
             YYTRACE("tf_declaration_eclr: tf_declaration");
          }
    break;

  case 42:

    {
             YYTRACE("tf_declaration_eclr: tf_decalration_eclr tf_declaration");
          }
    break;

  case 43:

    {
             YYTRACE("tf_declaration: parameter_decalration");
          }
    break;

  case 44:

    {
             YYTRACE("tf_declaration: input_declaration");
          }
    break;

  case 45:

    {
             YYTRACE("tf_declaration: output_declaration");
             
             if (scopeState == FUNCTION) {
                  }     
          }
    break;

  case 46:

    {
             YYTRACE("tf_declaration: inout_declaration");
            
             if (scopeState == FUNCTION) {
            
             }                
          }
    break;

  case 47:

    {
             YYTRACE("tf_declaration: reg_declaration");
             //local variables
          }
    break;

  case 48:

    {
             YYTRACE("tf_declaration: integer_declaration");
          }
    break;

  case 49:

    { state = PARAM; }
    break;

  case 50:

    {                                                           //ignore the syntax "range_opt"
             YYTRACE("parameter_declaration: YYPARAMETER assignment_list ';'");
            
             state = S_NULL;
		(yyval.paramPtr) = mFactory->MakeVarDeclareList();
		(yyval.paramPtr)->SetName("PARAMETER");
		(yyval.paramPtr)->AddChild((yyvsp[(4) - (5)].basePtr));
		if((yyvsp[(2) - (5)].basePtr)!=NULL)
		{
			(yyval.paramPtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[0]);
			(yyval.paramPtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[1]);
			delete (yyvsp[(2) - (5)].basePtr);
		}
          }
    break;

  case 51:

    {
             state = IO;
          }
    break;

  case 52:

    {
             YYTRACE("input_declaration: YYINPUT range_opt variable_list ';'");
            
             state = S_NULL;
		(yyval.basePtr) = (yyvsp[(4) - (5)].basePtr);
		(yyval.basePtr)->SetName("INPUT");
		if((yyvsp[(2) - (5)].basePtr)!=NULL)
		{
			(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[0]);
			(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[1]);
			delete (yyvsp[(2) - (5)].basePtr);
		}
		
          }
    break;

  case 53:

    {
             state = IO;
            
          }
    break;

  case 54:

    {
             YYTRACE("output_declaration: YYOUTPUT range_opt variable_list ';'");
             state = S_NULL;
		(yyval.basePtr)=(yyvsp[(4) - (5)].basePtr);
		(yyval.basePtr)->SetName("OUTPUT");
		if((yyvsp[(2) - (5)].basePtr)!=NULL)
		{
			(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[0]);
			(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[1]);
			delete (yyvsp[(2) - (5)].basePtr);
		}
          }
    break;

  case 55:

    {
             state = IO;
            
          }
    break;

  case 56:

    {
             YYTRACE("inout_declaration: YYINOUT range_opt variable_list ';'");
             state = S_NULL;
          }
    break;

  case 57:

    {                                                                           //the condition
             YYTRACE("net_declaration: nettype drive_strength_opt expandrange_opt delay_opt assignment_list ';'");
             	(yyval.basePtr) = mFactory->MakeVarDeclareList();
		(yyval.basePtr)->SetName("WIRE");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (3)].basePtr));
             state = S_NULL;
             
          }
    break;

  case 58:

    {
             YYTRACE("net_declaration: nettype drive_strength_opt expandrange_opt delay_opt variable_list ';'");
                state = S_NULL;
             	(yyval.basePtr) = (yyvsp[(2) - (3)].basePtr);
		(yyval.basePtr)->SetName("WIRE");
          }
    break;

  case 59:

    {
             YYTRACE("nettype: YYSWIRE");
              state = NET;
          }
    break;

  case 60:

    {
             YYTRACE("nettype: YYWIRE");
             state = NET;
		//$$ = mFactory->MakeVarDeclareList();
		//$$->SetName("WIRE");
		(yyval.basePtr) = NULL;
          }
    break;

  case 61:

    {
             YYTRACE("nettype: YYTRI");
              state = NET;
          }
    break;

  case 62:

    {
             YYTRACE("nettype: YYTRI1");
             
             state = NET;
          }
    break;

  case 63:

    {
             YYTRACE("nettype: YYSUPPLY0");
            
             state = NET;
          }
    break;

  case 64:

    {
             YYTRACE("nettype: YYWAND");
             
             state = NET;
	  }
    break;

  case 65:

    {
	     YYTRACE("nettype: YYTRIAND");
             
             state = NET;
	  }
    break;

  case 66:

    {
	     YYTRACE("nettype: YYTRI0");
             
             state = NET;
	  }
    break;

  case 67:

    {
	     YYTRACE("nettype: YYSUPPLY1");
           
             state = NET;
	  }
    break;

  case 68:

    {
             YYTRACE("nettype: YYWOR");
             
             state = NET;
          }
    break;

  case 69:

    {
             YYTRACE("nettype: YYTRIOR");
            
             state = NET;
          }
    break;

  case 70:

    {
             state = REG; 
             
          }
    break;

  case 71:

    {
             YYTRACE("reg_declaration: YYREG range_opt register_variable_list ';'");
             
             state = S_NULL;
		(yyval.basePtr) = (yyvsp[(4) - (5)].basePtr);
		(yyval.basePtr)->SetName("REG");
		if((yyvsp[(2) - (5)].basePtr)!=NULL)
		{
			(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[0]);
			(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr)->GetChildrenNode()[1]);
			delete (yyvsp[(2) - (5)].basePtr);
		}
          }
    break;

  case 72:

    {
             state = INT;
          }
    break;

  case 73:

    {
             YYTRACE("integer_declaration: YYINTEGER register_variable_list ';'");
             
             state = S_NULL;
          }
    break;

  case 74:

    { state = ASSIGN; }
    break;

  case 75:

    {
             YYTRACE("continuous_assign: YYASSIGN drive_strength_opt delay_opt assignment_list ';'");
             
             state = S_NULL;
		(yyval.assignPtr)=mFactory->MakeAssign();
		(yyval.assignPtr)->AddChild((yyvsp[(3) - (4)].basePtr));
          }
    break;

  case 76:

    { (state) = PARAM_NOL; }
    break;

  case 77:

    {
             YYTRACE("parameter_override: YYDEFPARAM assign_list ';'");
             (state) = S_NULL;         
          }
    break;

  case 78:

    {
             YYTRACE("variable_list: identifier");
		(yyval.basePtr)=mFactory->MakeVarDeclareList();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (1)].basePtr));
           
          }
    break;

  case 79:

    {
             YYTRACE("variable_list: variable_list ',' identifier");
           	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          
	}
    break;

  case 80:

    {
             YYTRACE("register_variable_list: register_variable");
		//$$ = mFactory->MakeVarDeclareList();
		//$$->AddChild($1);
		(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 81:

    {
             YYTRACE("register_variable_list: register_variable_list ',' register_variable");
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          }
    break;

  case 82:

    {
             YYTRACE("register_variable: name_of_register");
		(yyval.basePtr) = mFactory->MakeVarDeclareList();
     		(yyval.basePtr)->AddChild((yyvsp[(1) - (1)].basePtr));
          }
    break;

  case 83:

    {                                                 //ref. 5-11 in Verilog book
             YYTRACE("register_variable: name_of_register '[' expression ':' expression ']'");
		(yyval.basePtr) = mFactory->MakeVarDeclareList();
		(yyval.basePtr)->AddChild((yyvsp[(3) - (6)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(5) - (6)].basePtr));
          	//$$ = NULL;
          }
    break;

  case 84:

    {
             YYTRACE("register_variable: name_of_register '[' YYDEF_ID ']'");
		//$$ = mFactory->MakeVarDeclareList();
		//$$->AddChild($3);
		(yyval.basePtr) = NULL;
          }
    break;

  case 85:

    {
             YYTRACE("name_of_register: YYID");   
        	(yyval.basePtr) = mFactory->MakeIdentifier(*(yyvsp[(1) - (1)].stringPtr));
          }
    break;

  case 86:

    {
             YYTRACE("range_opt: abacsdafa");
            	(yyval.basePtr)=NULL;
          }
    break;

  case 87:

    {
             YYTRACE("range_opt: range");
	     	(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 88:

    {
             YYTRACE("range: '[' expression ':' expression ']'");
		(yyval.basePtr) = mFactory->MakeRange();
	     	(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr));
	     	(yyval.basePtr)->AddChild((yyvsp[(4) - (5)].basePtr));
          }
    break;

  case 89:

    {
             YYTRACE("range: '[' YYDEF_ID ']'");
		(yyval.basePtr) = NULL;
          }
    break;

  case 90:

    {//linking
             YYTRACE("assignment_list: assignment");
             (yyval.basePtr)=(yyvsp[(1) - (1)].basePtr);             
          }
    break;

  case 91:

    {
             YYTRACE("assignment_list: assignment_list ',' assignment");
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          }
    break;

  case 92:

    {
             YYTRACE("gate_instantiation: gatetype drive_delay_clr gate_instance_list ';'");
		(yyval.primitivePtr)=(yyvsp[(2) - (3)].primitivePtr);
            
          }
    break;

  case 93:

    {
	     YYTRACE("gatetype: YYAND");
             // LY->gateType = 1;
		(yyval.primitivePtr)=NULL;
	  }
    break;

  case 94:

    {
	     YYTRACE("gatetype: YYNAND");
           //  LY->gateType = 2;
	  }
    break;

  case 95:

    {
	     YYTRACE("gatetype: YYOR");
             // LY->gateType = 3;
	  }
    break;

  case 96:

    {
             YYTRACE("gatetype: YYNOR");
          //   LY->gateType = 4;
	  }
    break;

  case 97:

    {
	     YYTRACE("gatetype: YYXOR");
           //  LY->gateType = 5;
		(yyval.primitivePtr)=NULL;
	  }
    break;

  case 98:

    {
	     YYTRACE("gatetype: YYXNOR");
            // LY->gateType = 6;
	  }
    break;

  case 99:

    {
	     YYTRACE("gatetype: YYBUF");
             // LY->gateType = 7;
	  }
    break;

  case 100:

    {
             YYTRACE("gatetype: YYBIFIF0");
          //  LY->gateType = 8;
	  }
    break;

  case 101:

    {
	     YYTRACE("gatetype: YYBIFIF1");
            
	  }
    break;

  case 102:

    {
	     YYTRACE("gatetype: YYNOT");
            // LY->gateType = 10;
	  }
    break;

  case 103:

    {
             YYTRACE("gate_instance_list: gate_instance");
		(yyval.primitivePtr)=mFactory->MakeGate();
		(yyval.primitivePtr)->AddChild((yyvsp[(1) - (1)].primitivePtr));  
          }
    break;

  case 104:

    {
             YYTRACE("gate_instance_list: gate_instance_list ',' gate_instance");
                (yyval.primitivePtr)->AddChild((yyvsp[(3) - (3)].primitivePtr));
          }
    break;

  case 105:

    {
             YYTRACE("gate_instance: '(' terminal_list ')'");
            	(yyval.primitivePtr)=(yyvsp[(2) - (3)].primitivePtr);
          }
    break;

  case 106:

    {
             YYTRACE("gate_instance: name_of_gate_instance '(' terminal_list ')'");
		(yyval.primitivePtr)=(yyvsp[(3) - (4)].primitivePtr);
		(yyval.primitivePtr)->AddChild((yyvsp[(1) - (4)].basePtr));
          }
    break;

  case 107:

    {
             YYTRACE("name_of_gate_instance: YYID");
             (yyval.basePtr)=mFactory->MakeIdentifier(*(yyvsp[(1) - (1)].stringPtr));
          }
    break;

  case 108:

    {
             YYTRACE("terminal_list: terminal");
		(yyval.primitivePtr)=mFactory->MakeGateInstance();
		(yyval.primitivePtr)->AddChild((yyvsp[(1) - (1)].basePtr));
           
          }
    break;

  case 109:

    {
             YYTRACE("terminal_list: terminal_list ',' terminal");
		(yyval.primitivePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
            
          }
    break;

  case 110:

    {
             YYTRACE("terminal: expression");
           	(yyval.basePtr)=(yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 111:

    {
             YYTRACE("module_or_primitive_instantiation: name_of_module_or_primitive module_or_primitive_option_clr module_or_primitive_instance_list ';'");
           
          }
    break;

  case 112:

    {
             YYTRACE("name_of_module_or_primitive: YYID");
             
          }
    break;

  case 113:

    {
             YYTRACE("name_of_module_or_primitive: YYDEF_ID");
		
          }
    break;

  case 114:

    {
             YYTRACE("module_or_primitive_option_clr:");
          }
    break;

  case 115:

    {
             YYTRACE("module_or_primitive_option_clr: module_or_primitive_option_clr module_or_primitive_option");
          }
    break;

  case 116:

    {
             YYTRACE("module_or_primitive_option: delay");
          }
    break;

  case 117:

    {
	     YYTRACE("delay_or_parameter_value_assignment: '#' YYINUMBER");
             //ignore!!
	  }
    break;

  case 118:

    {
	     YYTRACE("delay_or_parameter_value_assignment: '#' YYRNUMBER");
             //ignore!!
	  }
    break;

  case 119:

    {
	     YYTRACE("delay_or_parameter_value_assignment: '#' identifier");
             //ignore!!
	  }
    break;

  case 120:

    {
	     YYTRACE("delay_or_parameter_value_assignment: '#' '(' mintypmax_expression_list ')'");
	  }
    break;

  case 121:

    {
             YYTRACE("module_or_primitive_instance_list: module_or_primitive_instance");
		
          }
    break;

  case 122:

    {
             YYTRACE("module_or_primitive_instance_list: module_or_primitive_instance_list ',' module_or_primitive_instance");
            
          }
    break;

  case 123:

    {
             YYTRACE("module_or_primitive_instance: '(' module_connection_list ')'");
        
          }
    break;

  case 124:

    {  }
    break;

  case 125:

    {
             YYTRACE("module_or_primitive_instance: '(' module_connection_list ')'");
          
          }
    break;

  case 126:

    {
             YYTRACE("module_connection_list: module_port_connection_list");
            
          }
    break;

  case 127:

    {
             YYTRACE("module_connection_list: named_port_connection_list");
             
          }
    break;

  case 128:

    {
             YYTRACE("module_port_connection_list: module_port_connection");
                        
          }
    break;

  case 129:

    {
             YYTRACE("module_port_connection_list: module_port_connection_list ',' module_port_connection");
             
          }
    break;

  case 130:

    {
             YYTRACE("named_port_connection_list: named_port_connection");
	
          }
    break;

  case 131:

    {
             YYTRACE("named_port_connection_list: named_port_connection_list ',' name_port_connection");
          
          }
    break;

  case 132:

    {
             YYTRACE("module_port_connection:");
           
          }
    break;

  case 133:

    {
             YYTRACE("module_port_connection: expression");
            
          }
    break;

  case 134:

    { }
    break;

  case 135:

    {
             YYTRACE("named_port_connection: '.' identifier '(' connect_port ')'");
           
          }
    break;

  case 136:

    {
             YYTRACE("connect_port:");
           
          }
    break;

  case 137:

    {
             YYTRACE("connect_port: expression");
           
          }
    break;

  case 138:

    {
             if ((state) == EVENT)
             {
                YYTRACE("always_statement: YYALWAYS statement");
	
                state = S_NULL;
             }
             else;
		(yyval.alwaysPtr) = (yyvsp[(2) - (2)].basePtr);
                
          }
    break;

  case 139:

    {
             YYTRACE("statement_opt:");
            
          }
    break;

  case 140:

    {
             YYTRACE("statement_opt: statement");
             
          }
    break;

  case 141:

    {
             YYTRACE("statement_clr:");
           	(yyval.basePtr) = NULL;
          }
    break;

  case 142:

    {
             YYTRACE("statement_clr: statement_clr statement");
		(yyval.basePtr) = (yyvsp[(2) - (2)].basePtr);
           
          }
    break;

  case 143:

    {  //and {lvalue '=' expression ';'} won't use this.
             YYTRACE("statement: ';'");
           	(yyval.basePtr) = NULL;
          }
    break;

  case 144:

    {              //                               | lvalue YYNBASSIGN delay_control expression ';'
             YYTRACE("statement: assignment ';'");
		(yyval.basePtr) = (yyvsp[(1) - (2)].basePtr);
          
          }
    break;

  case 145:

    {
             YYTRACE("statement: YYIF '(' expression ')' statement");
		(yyval.basePtr)=mFactory->MakeIf();
		(yyval.basePtr)->AddChild((yyvsp[(3) - (5)].basePtr));
             	(yyval.basePtr)->AddChild((yyvsp[(5) - (5)].basePtr));
          }
    break;

  case 146:

    {
             YYTRACE("statement: YYIF '(' expression ')' statement YYELSE statement");
		(yyval.basePtr)=mFactory->MakeIf();
		(yyval.basePtr)->AddChild((yyvsp[(3) - (7)].basePtr));
             	(yyval.basePtr)->AddChild((yyvsp[(5) - (7)].basePtr));   
           	(yyval.basePtr)->AddChild((yyvsp[(7) - (7)].basePtr));
	  }
    break;

  case 147:

    {
             YYTRACE("statement: YYCASE '(' expression ')' case_item_eclr YYENDCASE");
		(yyval.basePtr) = mFactory->MakeCase();
		(yyval.basePtr)->AddChild((yyvsp[(3) - (7)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(6) - (7)].basePtr));
            
          }
    break;

  case 148:

    {
             YYTRACE("statement: YYCASEZ '(' expression ')' case_item_eclr YYENDCASE"); 
            
          }
    break;

  case 149:

    {
             YYTRACE("statement: YYCASEX '(' expression ')' case_item_eclr YYENDCASE");
          
          }
    break;

  case 150:

    {
             YYTRACE("statement: YYFOR '(' assignment ';' expression ';' assignment ')' statement");
		(yyval.basePtr) = mFactory->MakeFor();
		(yyval.basePtr)->AddChild((yyvsp[(3) - (9)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(5) - (9)].basePtr));
             	(yyval.basePtr)->AddChild((yyvsp[(7) - (9)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(9) - (9)].basePtr));
          }
    break;

  case 151:

    {
             YYTRACE("statement: event_control statement");
             state = EVENT;
		(yyval.basePtr) = mFactory->MakeAlways();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (2)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
          }
    break;

  case 152:

    {                                      //but to ignore delay
             YYTRACE("statement: lvalue '=' delay_control expression ';'");
            
          }
    break;

  case 153:

    {                                             // use the rule, but to ignore delay
             YYTRACE("statement: lvalue YYNBASSIGN delay_control expression ';'");
           
          }
    break;

  case 154:

    {
             YYTRACE("statement: seq_block");
           	(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
          }
    break;

  case 155:

    {            //task can use another task and function
             YYTRACE("statement: task_enable");
             if (scopeState == FUNCTION) {
             }
          }
    break;

  case 156:

    {
             YYTRACE("statement: YYASSIGN assignment ';'");
		(yyval.basePtr) = mFactory->MakeAssign();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (3)].basePtr));
            
          }
    break;

  case 157:

    { 
		/*LY->stack_d.push(false); LY->stack_d.push(false); */
		(yyval.basePtr) = NULL;
	}
    break;

  case 158:

    {
             YYTRACE("assignment: lvalue '=' expression");
		(yyval.basePtr)=mFactory->MakeBlockingStatement();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
             
          }
    break;

  case 159:

    {
             YYTRACE("assignment: lvalue YYNBASSIGN expression");
            	(yyval.basePtr)=mFactory->MakeNonBlockingStatement();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          }
    break;

  case 160:

    {
             YYTRACE("case_item_eclr: case_item");
           	(yyval.basePtr) = mFactory->MakeCaseList();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (1)].basePtr));
          }
    break;

  case 161:

    {
             YYTRACE("case_item_eclr: case_item_eclr case_item");
           	(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
          }
    break;

  case 162:

    {
             YYTRACE("case_item: expression_list ':' statement");
           	(yyval.basePtr) = mFactory->MakeCaseItem();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          }
    break;

  case 163:

    {
             YYTRACE("case_item: YYDEFAULT ':' statement");
		(yyval.basePtr) = mFactory->MakeCaseDefault();
            	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          }
    break;

  case 164:

    {
             YYTRACE("case_item: YYDEFAULT statement");
          	(yyval.basePtr) = NULL;
          }
    break;

  case 165:

    {
             YYTRACE("seq_block: YYBEGIN statement_clr YYEND");
		(yyval.basePtr)= mFactory->MakeBlock();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (3)].basePtr));
         
          }
    break;

  case 166:

    {
             YYTRACE("seq_block: YYBEGIN ':' name_of_block block_declaration_clr statement_clr YYEND");
           
          }
    break;

  case 167:

    {
             YYTRACE("name_of_block: YYID");
		(yyval.basePtr) = mFactory->MakeIdentifier(*(yyvsp[(1) - (1)].stringPtr));
          }
    break;

  case 168:

    {
             YYTRACE("block_declaration_clr:");
          }
    break;

  case 169:

    {
             YYTRACE("block_declaration_clr: block_declaration_clr block_declaration");
            
          }
    break;

  case 170:

    {
             YYTRACE("block_declaration: parameter_declaration");
          }
    break;

  case 171:

    {
             YYTRACE("block_declaration: reg_declaration");
          }
    break;

  case 172:

    { 
          }
    break;

  case 173:

    {
             YYTRACE("task_enable: YYID ';'");
           
          }
    break;

  case 174:

    {
          
					}
    break;

  case 175:

    {
             YYTRACE("task_enable: YYID '(' expression_list ')' ';'");
            
          }
    break;

  case 176:

    {
		YYTRACE("lvalue: YYID");
		(yyval.basePtr)=(yyvsp[(1) - (1)].basePtr);
	}
    break;

  case 177:

    { }
    break;

  case 178:

    {
	     YYTRACE("lvalue: YYID '[' expression ']'");
		(yyval.basePtr) = (yyvsp[(3) - (3)].basePtr);
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
					}
    break;

  case 179:

    {
	     YYTRACE("lvalue: concatenation");
		(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
            
	  }
    break;

  case 180:

    { 
	     YYTRACE("lvalue: YYDEF_ID");
            
  	  }
    break;

  case 181:

    { (yyval.basePtr) = NULL; }
    break;

  case 182:

    { (yyval.basePtr) = (yyvsp[(1) - (1)].basePtr); }
    break;

  case 183:

    {
	     YYTRACE("mintypmax_expression_list: mintypmax_expression");
           
	  }
    break;

  case 184:

    {
             YYTRACE("mintypmax_expression_list: mintypmax_expression_list ',' mintypmax_expression");
            
	  }
    break;

  case 185:

    {
	     YYTRACE("mintypmax_expression: expression");
            
					}
    break;

  case 186:

    {/*expression is used in case, task, and concatenate*/
	     YYTRACE("expression_list: expression");
            	(yyval.basePtr)=mFactory->MakeExpressionList();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (1)].basePtr));
	  }
    break;

  case 187:

    {
	     YYTRACE("expression_list: expression_list ',' expression");
           	//$$=$1;
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 188:

    {
	     YYTRACE("expression: primary");
           	(yyval.basePtr)=(yyvsp[(1) - (1)].basePtr);
	  }
    break;

  case 189:

    {
	     YYTRACE("expression: '+' primary %prec YYUNARYOPERATOR");
		(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("ADD");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
           
	  }
    break;

  case 190:

    {
	     YYTRACE("expression: '-' primary %prec YYUNARYOPERATOR");
		(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("MINUS");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 191:

    {
	     YYTRACE("expression: '!' primary %prec YYUNARYOPERATOR");
           	(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_NOT");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 192:

    {
             YYTRACE("expression: '~' primary %prec YYUNARYOPERATOR");
		(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_NOT");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
            
	  }
    break;

  case 193:

    {
	     YYTRACE("expression: '&' primary %prec YYUNARYOPERATOR");
            	(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_AND");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 194:

    {
	     YYTRACE("expression: '|' primary %prec YYUNARYOPERATOR");
           	(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_OR");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 195:

    {/*The rule is added by Louis.*/
	     YYTRACE("expression: '^' primary %prec YYUNARYOPERATOR");
           	(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_XOR");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 196:

    {
	     YYTRACE("expression: YYLOGNAND primary %prec YYUNARYOPERATOR");
            	(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_NAND");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 197:

    {
             YYTRACE("expression: YYLOGNOR primary %prec YYUNARYOPERATOR");
            	(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_NOR");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 198:

    {
	     YYTRACE("expression: YYLOGXNOR primary %prec YYUNARYOPERATOR");
           	(yyval.basePtr) = mFactory->MakeUnaryOperation();
		(yyval.basePtr)->SetName("BITWISE_XNOR");
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
	  }
    break;

  case 199:

    {
	     YYTRACE("expression: expression '+' expression");
		(yyval.basePtr)=mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("ADD");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
            
	  }
    break;

  case 200:

    {
	     YYTRACE("expression: expressio '-' expression");
		(yyval.basePtr)=mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("MINUS");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
            
	  }
    break;

  case 201:

    {
	     YYTRACE("expression: expression '*' expression");
		(yyval.basePtr)=mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("MULTIPLY");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
            
	  }
    break;

  case 202:

    {
	     YYTRACE("expression: expression YYLOGEQUALITY expression");
		(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("LOGICAL_EQUAL");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 203:

    {
	     YYTRACE("expression: expression YYLOGINEQUALITY expression");
          	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("NOT_EQUAL");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 204:

    {
	     YYTRACE("expression: expression YYCASEEQUALITY expression");
            	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("CASE_EQUAL");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 205:

    {
	     YYTRACE("expression: expression YYCASEINEQUALITY expression");
		(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("CASE_NOT_EQUAL");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 206:

    {
	     YYTRACE("expression: expression YYLOGAND expression");
		(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("LOGICAL_AND");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          
	  }
    break;

  case 207:

    {
	     YYTRACE("expression: expression YYLOGOR expression");
           	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("LOGICAL_OR");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 208:

    {
	     YYTRACE("expression: expression '<' expression");
         	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("LT");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 209:

    {
	     YYTRACE("expression: expression '>' expression");
           	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("GT");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 210:

    {
	     YYTRACE("expression: expression '&' expression");
       		(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("BITWISE_AND");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 211:

    {
	     YYTRACE("expression: expression '|' expression");
		(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("BITWISE_OR");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
          }
    break;

  case 212:

    {
	     YYTRACE("expression: expression '^' expression");
          	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("BITWISE_XOR");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 213:

    {
	     YYTRACE("expression: expression YYLEQ expression");
		(yyval.basePtr)=mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("LEQ");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 214:

    {
	     YYTRACE("expression: expression YYLEQ expression");
		(yyval.basePtr)=mFactory->MakeNonBlockingStatement();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
     		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
	  }
    break;

  case 215:

    {
	     YYTRACE("expression: expression YYGEQ expression");
		(yyval.basePtr)=mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("GEQ");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
           }
    break;

  case 216:

    {
	     YYTRACE("expression: expression YYLSHIFT expression");
          	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("LS");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 217:

    {
	     YYTRACE("expression: expression YYRSHIFT expression");
           	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("RS");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 218:

    {
	     YYTRACE("expression: expression YYLOGXNOR expression");
            	(yyval.basePtr) = mFactory->MakeBinaryOperation();
		(yyval.basePtr)->SetName("LOGICAL_XNOR");
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
        	(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
	  }
    break;

  case 219:

    {
	     YYTRACE("expression: expression '?' expression ':' expression");
           	(yyval.basePtr) = mFactory->MakeIfQuestion();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (5)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (5)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(5) - (5)].basePtr));
	  }
    break;

  case 220:

    {
	     YYTRACE("primary: YYINUMBER");
		//cout<<$1 <<endl;
		(yyval.basePtr) = mFactory->MakeNumber((yyvsp[(1) - (1)].ival));
          }
    break;

  case 221:

    {
             YYTRACE("primary: YYRNUMBER");
		//cout<<*$1<<endl;
         	(yyval.basePtr) = mFactory->MakeRealNumber(*(yyvsp[(1) - (1)].stringPtr));
	}
    break;

  case 222:

    {
	     YYTRACE("primary: identifier");
		(yyval.basePtr)=(yyvsp[(1) - (1)].basePtr);
					}
    break;

  case 223:

    {  }
    break;

  case 224:

    {
	     YYTRACE("primary: identifier bitExpression");
		//$$=mFactory->MakeArrayRef();
		(yyval.basePtr) = (yyvsp[(3) - (3)].basePtr);
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
	  }
    break;

  case 225:

    {
	     YYTRACE("primary: concatenation");
             	(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
	  }
    break;

  case 226:

    {
	     YYTRACE("primary: multiple_concatenatin");
		(yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
            
	  }
    break;

  case 227:

    {
	     YYTRACE("primary: function_call");
             
	  }
    break;

  case 228:

    {                //but put in different BNF to make modify easily in the future
             YYTRACE("primary: BIT_BASE_NUMBER");
		(yyval.basePtr) = mFactory->MakeBitBase(*(yyvsp[(1) - (1)].stringPtr));
             
          }
    break;

  case 229:

    {
	     YYTRACE("expression: ( expression )");
            	(yyval.basePtr) = (yyvsp[(2) - (3)].basePtr);
          }
    break;

  case 230:

    { 
             YYTRACE("primary: YYDEF_ID");
           
          }
    break;

  case 231:

    {
        	(yyval.basePtr)=mFactory->MakeArrayRef();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (3)].basePtr));
          }
    break;

  case 232:

    {
           	(yyval.basePtr) = mFactory->MakeRange();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (5)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(4) - (5)].basePtr)); 
          }
    break;

  case 233:

    {
	     YYTRACE("concatenation: '{' expression_list '}'");
		(yyval.basePtr) = mFactory->MakeConcatenate();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (3)].basePtr));
          }
    break;

  case 234:

    {
	     YYTRACE("multiple_concatenation: '{' expression '{' expression_list '}' '}'");
		(yyval.basePtr) = mFactory->MakeConcatenate();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (6)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(4) - (6)].basePtr));
           
	  }
    break;

  case 235:

    {  }
    break;

  case 236:

    {
	     YYTRACE("function_call: identifier '(' expression_list ')'");
					}
    break;

  case 237:

    {//identifier => stringPtr 
             YYTRACE("identifier: YYID");
		(yyval.basePtr) = mFactory->MakeIdentifier(*(yyvsp[(1) - (1)].stringPtr));
    
          }
    break;

  case 238:

    {  }
    break;

  case 239:

    {
             YYTRACE("identifier: identifier '.' YYID");
						 // $$ = $4;
          }
    break;

  case 240:

    {
	     YYTRACE("delay_control: '#' YYINUMBER");
	  }
    break;

  case 241:

    {
	     YYTRACE("delay_control: '#' YYRNUMBER");
	  }
    break;

  case 242:

    {
	     YYTRACE("delay_control: '#' identifier");
	  }
    break;

  case 243:

    {
	     YYTRACE("delay_control: '#' '(' mintypmax_expression ')'");
	  }
    break;

  case 244:

    {
	     YYTRACE("event_control: '@' '(' event_expression ')'");
		(yyval.basePtr) = mFactory->MakeEventControl();
		(yyval.basePtr)->AddChild((yyvsp[(3) - (4)].basePtr));
           
	  }
    break;

  case 245:

    {
		// 03-05 Make Always
	     YYTRACE("event_control: '@' '(' ored_event_expression ')'");
		(yyval.basePtr) = (yyvsp[(3) - (4)].basePtr);
	  }
    break;

  case 246:

    {
             	(yyval.basePtr) = NULL;
          }
    break;

  case 247:

    {
          	(yyval.basePtr) = NULL;
          }
    break;

  case 248:

    {
	     YYTRACE("event_expression: expression");
             (yyval.basePtr) = (yyvsp[(1) - (1)].basePtr);
	  }
    break;

  case 249:

    {
	     YYTRACE("event_expression: YYPOSEDGE expression");
		(yyval.basePtr) = mFactory->MakePosedge();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
            
	  }
    break;

  case 250:

    {
	     YYTRACE("event_expression: YYNEGEDGE expression");
		(yyval.basePtr) = mFactory->MakeNegedge();
		(yyval.basePtr)->AddChild((yyvsp[(2) - (2)].basePtr));
           
	  }
    break;

  case 251:

    {
	     YYTRACE("event_expression: YYEDGE expression");
            (yyval.basePtr)=NULL;
          }
    break;

  case 252:

    {
	     YYTRACE("ored_event_expression: event_expression YYOR event_expression");
		(yyval.basePtr) = mFactory->MakeEventControl();
		(yyval.basePtr)->AddChild((yyvsp[(1) - (3)].basePtr));
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
           
	  }
    break;

  case 253:

    {
	     YYTRACE("ored_event_expression: ored_event_expression YYOR event_expression");
		(yyval.basePtr)->AddChild((yyvsp[(3) - (3)].basePtr));
             
	  }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}










