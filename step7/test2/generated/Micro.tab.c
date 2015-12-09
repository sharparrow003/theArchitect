
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 1 "src/Micro.y"

#include <list>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "src/ast.h"
#include "src/cfg.h"
#include "src/stat.h"

using namespace std;
struct node{
	string *value;
	struct node *left;
	struct node *right;
};
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
/*Function declarations */

//Michael's Declarations
ast myast;
deque<ast> astlist;
list<string> varlist;
vector<cfg> cfglist;
//exprhead is being used as a temporary place holder for the root expression in nested parentheticals. i.e. (((x)+x)+x)
static node * exprhead = 0;
static list<stack<list<string>*> *> empire;
static stack<list<string>*> currkingdom;
static list<string>currfief;
static vector<string>myIRlist;
//ducttape list for storing exprlists in call expressions
static list<node *>ducttape;
static int val = 0;
static int scope = 0;

//Lalit's Declarations
static int registerValue = 1;
string datatype="i";
int regVal = 0;		//Values of temp variables T
int localVal = 0;	//Values of local variables L
int parVal = 0;		//Values of parameter variables P
map< string, map<string, string> > symbolTable;
map< string, map<string, string> > datatypeTableIR;
map< string, map<string, string> > datatypeTableTiny;
string currentScope = "GLOBAL";
string currentScopeType = "";

int labelCount = 1;

list <string> labelStack;
list <string> activityStack;

int getRegister(string IRReg);					//Calculates the register number from IR Node ***IMPORTANT***

list<string> IRList;
list<string> IRNodeList;
list<string> astPostOrder;
list<string> generateTinyCode();				//Generates tiny code from the list of IR Nodes  ***IMPORTANT***
void printList(list<string> strList);				//Prints out list ***NOT IMPORTANT***

void yyerror(const char *s) { cout << "Not Accepted" << endl; exit(0); }


/* Line 189 of yacc.c  */
#line 146 "Micro.tab.c"

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
     PROGRAM = 258,
     BEGIN_TOKEN = 259,
     END = 260,
     FUNCTION = 261,
     READ = 262,
     WRITE = 263,
     IF = 264,
     ELSE = 265,
     FI = 266,
     FOR = 267,
     ROF = 268,
     CONTINUE = 269,
     BREAK = 270,
     RETURN = 271,
     INT = 272,
     VOID = 273,
     STRING = 274,
     FLOAT = 275,
     ADDOP = 276,
     SUBOP = 277,
     MULOP = 278,
     DIVOP = 279,
     GREATER = 280,
     LESSER = 281,
     EQUALS = 282,
     NEQUALS = 283,
     LEQUALS = 284,
     GEQUALS = 285,
     ASSMTOP = 286,
     OPENPAROP = 287,
     CLOSEPAROP = 288,
     SCOLONOP = 289,
     COMMAOP = 290,
     INTLIT = 291,
     FLTLIT = 292,
     STRLIT = 293,
     IDENTIFIER = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 72 "src/Micro.y"

	int ival;
	float fval;
	char *sval;
	char *iden;
	void *fief;
	struct node *nval;



/* Line 214 of yacc.c  */
#line 232 "Micro.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 244 "Micro.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    11,    14,    17,    20,    22,    28,
      30,    34,    36,    38,    40,    42,    45,    49,    51,    54,
      56,    59,    63,    65,    68,    70,    80,    83,    86,    88,
      90,    92,    94,    96,    98,   100,   102,   105,   109,   115,
     121,   125,   128,   132,   134,   137,   141,   143,   145,   147,
     152,   155,   157,   161,   163,   167,   169,   171,   173,   175,
     177,   179,   181,   190,   194,   196,   200,   202,   204,   206,
     208,   210,   212,   214,   216,   218,   220,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,     3,    42,     4,    43,     5,    -1,    39,
      -1,    44,    55,    -1,    45,    44,    -1,    47,    44,    -1,
      84,    -1,    19,    42,    31,    46,    34,    -1,    38,    -1,
      48,    50,    34,    -1,    20,    -1,    17,    -1,    48,    -1,
      18,    -1,    42,    51,    -1,    35,    42,    51,    -1,    84,
      -1,    53,    54,    -1,    84,    -1,    48,    42,    -1,    35,
      53,    54,    -1,    84,    -1,    56,    55,    -1,    84,    -1,
       6,    49,    42,    32,    52,    33,     4,    57,     5,    -1,
      44,    58,    -1,    59,    58,    -1,    84,    -1,    60,    -1,
      77,    -1,    83,    -1,    61,    -1,    63,    -1,    64,    -1,
      65,    -1,    62,    34,    -1,    42,    31,    66,    -1,     7,
      32,    50,    33,    34,    -1,     8,    32,    50,    33,    34,
      -1,    16,    66,    34,    -1,    67,    68,    -1,    67,    68,
      75,    -1,    84,    -1,    69,    70,    -1,    69,    70,    76,
      -1,    84,    -1,    74,    -1,    71,    -1,    42,    32,    72,
      33,    -1,    66,    73,    -1,    84,    -1,    35,    66,    73,
      -1,    84,    -1,    32,    66,    33,    -1,    42,    -1,    36,
      -1,    37,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,     9,    32,    79,    33,    44,    58,    78,    11,    -1,
      10,    44,    58,    -1,    84,    -1,    66,    80,    66,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    62,    -1,    84,    -1,    62,    -1,    84,    -1,
      12,    32,    81,    34,    79,    34,    82,    33,    44,    58,
      13,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   155,   157,   159,   191,   241,   248,   258,
     260,   275,   276,   278,   279,   282,   298,   313,   319,   326,
     330,   339,   339,   341,   341,   343,   401,   416,   420,   425,
     427,   429,   433,   435,   437,   439,   443,   467,   485,   506,
     527,   544,   559,   577,   581,   595,   612,   616,   618,   622,
     658,   662,   664,   668,   671,   681,   686,   693,   707,   709,
     712,   714,   717,   756,   784,   787,   797,   799,   801,   803,
     805,   807,   811,   816,   823,   828,   835,   884
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BEGIN_TOKEN", "END",
  "FUNCTION", "READ", "WRITE", "IF", "ELSE", "FI", "FOR", "ROF",
  "CONTINUE", "BREAK", "RETURN", "INT", "VOID", "STRING", "FLOAT", "ADDOP",
  "SUBOP", "MULOP", "DIVOP", "GREATER", "LESSER", "EQUALS", "NEQUALS",
  "LEQUALS", "GEQUALS", "ASSMTOP", "OPENPAROP", "CLOSEPAROP", "SCOLONOP",
  "COMMAOP", "INTLIT", "FLTLIT", "STRLIT", "IDENTIFIER", "$accept",
  "program", "id", "pgm_body", "decl", "string_decl", "str", "var_decl",
  "var_type", "any_type", "id_list", "id_tail", "param_decl_list",
  "param_decl", "param_decl_tail", "func_declarations", "func_decl",
  "func_body", "stmt_list", "stmt", "base_stmt", "assign_stmt",
  "assign_expr", "read_stmt", "write_stmt", "return_stmt", "expr",
  "expr_prefix", "factor", "factor_prefix", "postfix_expr", "call_expr",
  "expr_list", "expr_list_tail", "primary", "addop", "mulop", "if_stmt",
  "else_part", "cond", "compop", "init_stmt", "incr_stmt", "for_stmt",
  "empty", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    44,    44,    44,    45,    46,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    54,    54,    55,    55,    56,    57,    58,    58,    59,
      59,    59,    60,    60,    60,    60,    61,    62,    63,    64,
      65,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     2,     2,     2,     1,     5,     1,
       3,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       2,     3,     1,     2,     1,     9,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     5,
       3,     2,     3,     1,     2,     3,     1,     1,     1,     4,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     8,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,    11,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,    77,    12,     0,    11,
       0,    77,    77,    77,     0,     7,     0,     2,     0,     4,
      77,    24,     5,     6,    77,     0,     0,    14,    13,     0,
      23,     0,    15,    17,    10,     9,     0,     0,    77,     8,
      77,    16,     0,     0,    77,    19,    20,     0,     0,    18,
      22,    77,    77,    77,     0,    21,     0,     0,     0,     0,
      77,     0,    26,    77,    29,    32,     0,    33,    34,    35,
      30,    31,    28,    25,     0,     0,    77,    77,     0,    77,
      43,    77,    27,    36,     0,     0,     0,     0,    72,     0,
      73,    40,    41,     0,    46,    37,     0,     0,    66,    67,
      68,    69,    70,    71,    77,    77,    77,    58,    59,    42,
      77,    56,    57,    55,    44,    48,    47,    38,    39,    65,
      77,     0,     0,    77,    60,    61,    45,    77,    77,    54,
      77,     0,    43,    77,     0,    64,    74,     0,    75,    77,
      50,    53,    49,    77,    62,    77,    77,    63,    77,    52,
       0,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    61,    10,    11,    12,    36,    13,    14,    29,
      25,    32,    43,    44,    49,    19,    20,    54,    62,    63,
      64,    65,    66,    67,    68,    69,    86,    79,    92,    93,
     114,   115,   131,   140,   116,   109,   126,    70,   134,    87,
     104,    89,   137,    71,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int8 yypact[] =
{
       0,   -32,    12,   -76,    18,   -76,     1,   -76,   -32,   -76,
      30,    31,     1,     1,   -32,   -76,     9,   -76,     8,   -76,
      31,   -76,   -76,   -76,    16,    23,   -14,   -76,   -76,   -32,
     -76,   -32,   -76,   -76,   -76,   -76,    25,    32,    16,   -76,
      19,   -76,   -32,    36,    28,   -76,   -76,    63,    19,   -76,
     -76,     1,    28,     7,    69,   -76,    43,    44,    47,    48,
     -76,    51,   -76,     7,   -76,   -76,    49,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -32,   -32,   -76,   -32,    50,   -76,
     -76,   -76,   -76,   -76,    52,    54,    75,    55,   -76,    56,
     -76,   -76,    34,    11,   -76,   -76,    57,    58,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,     1,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,    62,    38,   -76,   -76,   -76,   -76,   -76,
       7,    72,    64,   -76,   -76,   -76,   -76,    97,   -32,   -76,
      73,    77,    78,     1,   102,   -76,   -76,    81,   -76,   -76,
     -76,   -76,   -76,     7,   -76,     1,    73,   -76,     7,   -76,
     105,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,     3,   -76,    -7,   -76,   -76,   -76,   -10,   -76,
      -3,    82,   -76,    67,    70,   101,   -76,   -76,   -62,   -76,
     -76,   -76,   -75,   -76,   -76,   -76,   -50,   -76,   -76,   -76,
     -76,   -76,   -76,   -23,   -76,   -76,   -76,   -76,   -76,    21,
     -76,   -76,   -76,   -76,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      21,    82,    88,     1,     4,    22,    23,     3,    28,    21,
      78,    16,     5,    33,    56,    57,    58,    24,     7,    59,
       8,     9,     6,    60,    35,     7,    27,    33,     9,    45,
      42,    95,    37,    50,    38,    17,     7,    18,    42,     9,
      26,    50,    72,   110,    53,    46,     3,   111,   112,    80,
       3,    31,    72,   136,   119,   107,   108,    34,   127,    39,
     122,   124,   125,    48,    40,    80,    90,    51,    94,    47,
      80,    84,    85,   130,    73,    74,    75,    24,    24,    76,
      77,   147,    81,    83,    91,    96,   150,    97,   105,   146,
     106,   117,   118,    80,   123,    80,   113,   129,   120,    80,
      98,    99,   100,   101,   102,   103,   128,   133,   139,    72,
     142,   -51,   132,   144,   145,    52,   135,   138,   151,   141,
      41,    30,    55,   149,     0,     0,   143,   121,    80,     0,
       0,     0,    72,     0,     0,   141,     0,    72,   148
};

static const yytype_int16 yycheck[] =
{
      11,    63,    77,     3,     1,    12,    13,    39,    18,    20,
      60,     8,     0,    24,     7,     8,     9,    14,    17,    12,
      19,    20,     4,    16,    38,    17,    18,    38,    20,    40,
      40,    81,    29,    44,    31,     5,    17,     6,    48,    20,
      31,    52,    53,    32,    51,    42,    39,    36,    37,    60,
      39,    35,    63,   128,   104,    21,    22,    34,   120,    34,
     110,    23,    24,    35,    32,    76,    77,     4,    79,    33,
      81,    74,    75,   123,     5,    32,    32,    74,    75,    32,
      32,   143,    31,    34,    34,    33,   148,    33,    33,   139,
      34,    34,    34,   104,    32,   106,    93,    33,   105,   110,
      25,    26,    27,    28,    29,    30,    34,    10,    35,   120,
      33,    33,   123,    11,    33,    48,   127,   128,    13,   130,
      38,    20,    52,   146,    -1,    -1,   133,   106,   139,    -1,
      -1,    -1,   143,    -1,    -1,   146,    -1,   148,   145
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    41,    39,    42,     0,     4,    17,    19,    20,
      43,    44,    45,    47,    48,    84,    42,     5,     6,    55,
      56,    84,    44,    44,    42,    50,    31,    18,    48,    49,
      55,    35,    51,    84,    34,    38,    46,    42,    42,    34,
      32,    51,    48,    52,    53,    84,    42,    33,    35,    54,
      84,     4,    53,    44,    57,    54,     7,     8,     9,    12,
      16,    42,    58,    59,    60,    61,    62,    63,    64,    65,
      77,    83,    84,     5,    32,    32,    32,    32,    66,    67,
      84,    31,    58,    34,    50,    50,    66,    79,    62,    81,
      84,    34,    68,    69,    84,    66,    33,    33,    25,    26,
      27,    28,    29,    30,    80,    33,    34,    21,    22,    75,
      32,    36,    37,    42,    70,    71,    74,    34,    34,    66,
      44,    79,    66,    32,    23,    24,    76,    58,    34,    33,
      66,    72,    84,    10,    78,    84,    62,    82,    84,    35,
      73,    84,    33,    44,    11,    33,    66,    58,    44,    73,
      58,    13
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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
int yyparse (void);
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 119 "src/Micro.y"
    {
	varlist.push_back("Symbol table GLOBAL");
	while(!empire.empty()){
		stack<list<string>*> *kingdomptr = empire.front();
		empire.pop_front();
		while(!(*kingdomptr).empty()){
			//cout << "Pre Ack Level 2" << endl;
			list<string>*fiefptr = (*kingdomptr).top();
			(*kingdomptr).pop();
			//cout << "Fief Pointer: " << fiefptr << endl;
		 	//cout << "Ack Level 2" << endl;
			if(!(*fiefptr).empty()){	
				//cout << "Above Fief Pointer is not empty" << endl;
				for (list<string>::iterator it = (*fiefptr).begin(); it != (*fiefptr).end(); it++){
					//cout << "Pre Ack Level 3" << endl;
					if (*it == "Symbol table IF" || *it == "Symbol table FOR" || *it == "Symbol table ELSE"){
						val = val + 1;
						//cout << endl << *it << " " << val << endl;
						stringstream ss;
						ss << *it << " " << val;
						varlist.push_back(ss.str());
					}
					else{
						//cout << *it << endl;
						varlist.push_back(*it);
					}
					//cout << "Ack Level 3" << endl;
				}
				(*fiefptr).clear();
			}
			delete fiefptr;
		}
		delete kingdomptr;
	}
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 155 "src/Micro.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].iden);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 160 "src/Micro.y"
    {
	if (scope == 0){
		if(!currfief.empty()){
			list<string>*newfief = new list<string>;
			*newfief = currfief;
			currkingdom.push(newfief); 			
			currfief.clear();
			stack<list<string>*> *newkingdom = new stack<list<string>*>;
			*newkingdom = currkingdom;
			empire.push_back(newkingdom);
			currkingdom.pop();
		}
		(yyval.fief) = 0;
		scope = 1;
	}
	else{
		if(!currfief.empty()){
			list<string>*newfief = new list<string>;
			*newfief = currfief;	
			(yyval.fief) = newfief;
			//cout << $<fief>$ << endl;
			currfief.clear();
		}
		else if((yyvsp[(2) - (2)].fief) != 0){
			(yyval.fief) = (yyvsp[(2) - (2)].fief);
		}		
	}
	//if ((*$<fief>$).size() > 1000){
	//	cout << "this mothafucka" << endl;
	//}
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 192 "src/Micro.y"
    {
	if (scope == 0){
		//cout << "Enter here? " << endl;
		if(!currfief.empty()){
			/*
			while(currfief.size() > 9){
				list<string>*newfief = new list<string>;
				while((*newfief).size() < 10 && !currfief.empty()){
					(*newfief).push_back(currfief.front());
					currfief.pop_front();
				}
				currkingdom.push(newfief);
				newfief = 0;
			}
			*/
			list<string>*newfief = new list<string>;
			*newfief = currfief;
			currkingdom.push(newfief);
						
			//cout << "First element: " << currfief.front() << endl;		
			
			currfief.clear();
			stack<list<string>*> *newkingdom = new stack<list<string>*>;
			*newkingdom = currkingdom;
			empire.push_back(newkingdom);
			while(!currkingdom.empty()){
				currkingdom.pop();	
			}
		}
		(yyval.fief) = 0;
		scope = 1;
	}
	else{
		if(!currfief.empty()){
			//cout << "Allocate new decl" << endl;
			list<string> *newfief = new list<string>;
			//cout << currfief.size();
			*newfief = currfief;	
			
			(yyval.fief) = newfief;
			currfief.clear();
		}
		else if ((yyvsp[(2) - (2)].fief) != 0){
			(yyval.fief) = (yyvsp[(2) - (2)].fief);
		}
	}
 	//cout << "Fief 1: " << $<fief>1 << endl;
	//cout << "Fief 2: " << $<fief>2 << endl;
;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 242 "src/Micro.y"
    {
	if (currfief.empty() && scope == 0){scope = 1;}
	(yyval.fief) = 0;
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 249 "src/Micro.y"
    {
	string s1((yyvsp[(2) - (5)].sval));
	string s2((yyvsp[(4) - (5)].sval));
	string s3("STRING " + s1 + " " + s2);
	//cout<<s3<<endl;
	//varlist.push_back(s3);
	currfief.push_back(s3);
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 258 "src/Micro.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 261 "src/Micro.y"
    {
	string s1((yyvsp[(2) - (3)].sval));
	stringstream ss(s1);
	string s2((yyvsp[(1) - (3)].sval));
	string s3;
	while(ss >> s3){
		if(s3 != ""){
			//varlist.push_back(s2 + " " + s3);			 
			//cout << "Testing: " << s2 << " " << s3 << endl;
			currfief.push_back(s2 + " " + s3);	
		}
	}
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 275 "src/Micro.y"
    {(yyval.sval) = "FLOAT";;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 276 "src/Micro.y"
    {(yyval.sval) = "INT";;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 278 "src/Micro.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 279 "src/Micro.y"
    {(yyval.sval) = "VOID";;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 282 "src/Micro.y"
    {
	if((yyvsp[(2) - (2)].sval) != 0){
		string s1;
		string s2((yyvsp[(2) - (2)].sval));
		stringstream ss;
		ss << (yyvsp[(1) - (2)].sval) << " " << (yyvsp[(2) - (2)].sval);
		s1 = ss.str();
		const char *temp = s1.c_str();
		(yyval.sval) = (char*)temp;
	}
	else{
		(yyval.sval) = (yyvsp[(1) - (2)].sval);
	}
;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 298 "src/Micro.y"
    {
	string s1;
	stringstream ss;
	if (!(yyvsp[(3) - (3)].sval)){
		s1 = string((yyvsp[(2) - (3)].sval));
		const char *temp = s1.c_str();
		(yyval.sval) = (char*)temp;
	}
	else{
		ss << (yyvsp[(2) - (3)].sval) << " " << (yyvsp[(3) - (3)].sval);
		s1 =ss.str();
		const char *temp = s1.c_str();
		(yyval.sval) = (char*)temp;
	}
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 314 "src/Micro.y"
    {
	(yyval.sval) = 0;
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 320 "src/Micro.y"
    {
	list<string> *fiefptr = new list<string>;
	*fiefptr = currfief;
	currfief.clear();
	(yyval.fief) = fiefptr;
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 327 "src/Micro.y"
    {(yyval.fief) = 0;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 331 "src/Micro.y"
    {
	string s1((yyvsp[(1) - (2)].sval));
	string s2((yyvsp[(2) - (2)].sval));
	string s3(s1 + " " + s2);
	currfief.push_back(s3);
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 344 "src/Micro.y"
    {
	//Push the function name on to a new list to be added to the function stack as a whole
	//cout << "Step 1 Func Decl" << endl;
	ostringstream oss;

	oss << endl << "Symbol table " << (yyvsp[(3) - (9)].sval);	
	list<string>*fnname = new list<string>;
	(*fnname).push_back(oss.str());
	
	//cout << "Step 2 Func Decl" << endl;
	//dynamically allocate new stack to copy current scope (kingdom) into;
	stack<list<string>*> *newkingdom = new stack<list<string>*>;
	if (!currkingdom.empty()){
		*newkingdom = currkingdom;
	}
	//cout << "Step 3 Func Decl" << endl;
	//push param declarations and function name
	if ((yyvsp[(5) - (9)].fief) != 0){	
		(*newkingdom).push((list<string>*)(yyvsp[(5) - (9)].fief));
	}
	//cout << $<sval>3 << " " << $<fief>5 << endl;
	(*newkingdom).push(fnname);
	
	//After pushing function name, add the function stack to list of functions
	empire.push_back(newkingdom);
	while(!currkingdom.empty()){
		
		list<string>tempfief;
		tempfief = *(currkingdom.top());	
		currkingdom.pop();
	}
	
	if (!astlist.empty()){
		if ((astlist.size() + 1) >= (yyvsp[(8) - (9)].ival)){			
			stringstream ss;
			if ((yyvsp[(5) - (9)].fief) != 0){	
				list<string> paramstorage = *((list<string>*)(yyvsp[(5) - (9)].fief));
				ss << "Function " << (yyvsp[(2) - (9)].sval) << " " << (yyvsp[(3) - (9)].sval);
				for (list<string>::iterator ls = paramstorage.begin(); ls != paramstorage.end(); ls++){
					string s1(*ls);
					string s2 = s1.substr(s1.find(" ",0),string::npos);
					ss << " " << s2;	
				}	
			}
			else{ss << "Function " << (yyvsp[(2) - (9)].sval) << " " << (yyvsp[(3) - (9)].sval);}
			ast function = ast();
			ast functionend = ast();
			node *fnname = function.newval(ss.str());
			node *fnend = functionend.newval("FEND");			
			deque<ast>::iterator it = astlist.begin() + (yyvsp[(8) - (9)].ival);
			astlist.insert(it,function);
			astlist.push_back(functionend);
		}
	}
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 402 "src/Micro.y"
    {
	//cout << $<fief>1 << endl;
	if((yyvsp[(1) - (2)].fief) != 0){	
		if(!(*((list<string>*)(yyvsp[(1) - (2)].fief))).empty()){
			currkingdom.push((list<string>*)(yyvsp[(1) - (2)].fief));
		}
	}
	//test the $<ival>$ from stmtlist with this code
	//check if astlist.size < $<ival>$
	//hopefully it is the first statement in whatever function it is and i can put the function in front of its constituents
	(yyval.ival) = (yyvsp[(2) - (2)].ival);
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 417 "src/Micro.y"
    {
	(yyval.ival) = (yyvsp[(1) - (2)].ival);
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 421 "src/Micro.y"
    {
	(yyval.ival) = 0;
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 426 "src/Micro.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 428 "src/Micro.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 430 "src/Micro.y"
    {(yyval.ival) = 0;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 434 "src/Micro.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 436 "src/Micro.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 438 "src/Micro.y"
    {(yyval.ival) = (yyvsp[(1) - (1)].ival);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 440 "src/Micro.y"
    {(yyval.ival) = 0;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 444 "src/Micro.y"
    {
	int presize = astlist.size();
	//cout << "Started post order!" << endl;
	//myast.postorder($<nval>1);	
	ast tempast;
	astlist.push_back(myast);
	//return pointer to statement's place in the list.
	if (!ducttape.empty()){
		for(list<node*>::iterator it = ducttape.begin(); it != ducttape.end(); it++){
			tempast = ast(*it);
			astlist.push_back(tempast);
		}
		tempast = ast();
		tempast.newval("CALLEND");
		astlist.push_back(tempast);
		ducttape.clear();
	}	
	myast = ast();
	//cout << (astlist.size()-1) << endl;
	(yyval.ival) = presize;	
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 468 "src/Micro.y"
    {
	node *temp1;
	node *temp2;
	temp1 = myast.newval((yyvsp[(1) - (3)].sval));
	temp2 = myast.newmath(temp1, ":=");	
	//cout << "Begin Post Order" << endl;
	//myast.postorder(temp2);
	//cout << "End Post Order" << endl;
	myast.addright(temp2, (yyvsp[(3) - (3)].nval));
	ast tempast((yyvsp[(3) - (3)].nval));
	//cout << "Begin post order!" << endl;
	//tempast.postorder(myast.root);	
	(yyval.nval) = temp2;
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 486 "src/Micro.y"
    {	
	int presize;
	presize = astlist.size();
	string s1((yyvsp[(3) - (5)].sval));
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"READ");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);
			myast = ast();			 
		}
	}
	(yyval.ival) = presize;
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 507 "src/Micro.y"
    {
	int presize;
	presize = astlist.size();
	string s1((yyvsp[(3) - (5)].sval));
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"WRITE");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);		 
			myast = ast();
		}
	}
	(yyval.ival) = presize;
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 528 "src/Micro.y"
    {
	int presize;
	presize = astlist.size();
	ast startast = ast();
	ast midast = ast((yyvsp[(2) - (3)].nval));
	ast endast = ast();
	node *temp1 = startast.newval("RETURN");
	node *temp2 = endast.newval("RETURNEND");
	astlist.push_back(startast);
	astlist.push_back(midast);
	astlist.push_back(endast);
	(yyval.ival) = presize;
	myast = ast();
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 545 "src/Micro.y"
    {
	if((yyvsp[(1) - (2)].nval) == 0){
		(yyval.nval) = (yyvsp[(2) - (2)].nval);
		exprhead = 0;
	}
	else{
		myast.addright((yyvsp[(1) - (2)].nval), (yyvsp[(2) - (2)].nval));
		(yyval.nval) = (yyvsp[(1) - (2)].nval);
	}
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 560 "src/Micro.y"
    {
	if ((yyvsp[(1) - (3)].nval) != 0 && (yyvsp[(2) - (3)].nval) != 0){
		node *temp = myast.newmath((yyvsp[(2) - (3)].nval), (yyvsp[(3) - (3)].sval));
		myast.addright((yyvsp[(1) - (3)].nval),temp);
		(yyval.nval) = temp;
	}
	else if ((yyvsp[(1) - (3)].nval) == 0 && (yyvsp[(2) - (3)].nval) != 0){
		node *temp = myast.newmath((yyvsp[(2) - (3)].nval), (yyvsp[(3) - (3)].sval));
		exprhead = temp;
		(yyval.nval) = temp;
	}
	else{
		(yyval.nval) = 0;
	}						
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 578 "src/Micro.y"
    {(yyval.nval) = 0;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 582 "src/Micro.y"
    {
	if((yyvsp[(1) - (2)].nval) == 0){
		(yyval.nval) = (yyvsp[(2) - (2)].nval);
	}
	else{
		myast.addright((yyvsp[(1) - (2)].nval), (yyvsp[(2) - (2)].nval));
		(yyval.nval) = (yyvsp[(1) - (2)].nval);
	}	
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 596 "src/Micro.y"
    {
	if ((yyvsp[(1) - (3)].nval) != 0 && (yyvsp[(2) - (3)].nval) != 0){
		node *temp = myast.newmath((yyvsp[(2) - (3)].nval), (yyvsp[(3) - (3)].sval));
		myast.addright((yyvsp[(1) - (3)].nval),temp);
		(yyval.nval) = temp;
	}
	else if ((yyvsp[(1) - (3)].nval) == 0 && (yyvsp[(2) - (3)].nval) != 0){
		node *temp = myast.newmath((yyvsp[(2) - (3)].nval), (yyvsp[(3) - (3)].sval));
		(yyval.nval) = temp;
	}
	else{
		(yyval.nval) = 0;
	}
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 613 "src/Micro.y"
    {(yyval.nval) = 0;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 617 "src/Micro.y"
    {(yyval.nval) = (yyvsp[(1) - (1)].nval);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 619 "src/Micro.y"
    {(yyval.nval) = (yyvsp[(1) - (1)].nval);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 623 "src/Micro.y"
    {
	/*
	int presize;
	presize = astlist.size();

	string s1($<sval>3);
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"READ");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);
			myast = ast();			 
		}
	}
	$<ival>$ = presize;
	*/
	/*
	for (list<node*>::iterator it = ducttape.begin(); it != ducttape.end(); it++){
		cout << *((*it)->value) << endl;
	}
	*/
	myast = ast();
	//cout << "Call Expression Before" << endl;
	//myast.postorder(myast.root);
	node *temp1 = myast.newval((yyvsp[(1) - (4)].sval));
	(yyval.nval) = myast.newop(temp1, "CALL");
	//cout << "After" << endl;
	//myast.postorder(myast.root);
	
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 659 "src/Micro.y"
    {
	ducttape.push_front((yyvsp[(1) - (2)].nval));
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 665 "src/Micro.y"
    {
	ducttape.push_back((yyvsp[(2) - (3)].nval));
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 672 "src/Micro.y"
    {
	if (exprhead != 0){
		(yyval.nval) = exprhead;
		exprhead = 0;
	}
	else{
		(yyval.nval) = (yyvsp[(2) - (3)].nval);
	}
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 682 "src/Micro.y"
    {
	node *temp = myast.newval((yyvsp[(1) - (1)].sval));
	(yyval.nval) = temp;
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 687 "src/Micro.y"
    {
	ostringstream buffer;
	buffer << (yyvsp[(1) - (1)].ival);
	node *temp = myast.newval(buffer.str());
	(yyval.nval) = temp;
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 694 "src/Micro.y"
    {
	ostringstream buffer;
	buffer << (yyvsp[(1) - (1)].fval);
	string s1(buffer.str());
	int findings = int(s1.find("."));
	if(findings == -1) {
		s1 = s1 + ".0";
	}

	node *temp = myast.newval(s1);
	(yyval.nval) = temp;
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 708 "src/Micro.y"
    {(yyval.sval) = "+";;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 710 "src/Micro.y"
    {(yyval.sval) = "-";;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 713 "src/Micro.y"
    {(yyval.sval) = "*";;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 715 "src/Micro.y"
    {(yyval.sval) = "/";;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 718 "src/Micro.y"
    {
	//AST and Control Structure code	
	node *ifptr = myast.newval("IF");
	node *fiptr = myast.newval("FI");
	myast.root = 0;
	node *condptr = (yyvsp[(3) - (8)].nval);
	//insert a new if node right before the statement list we saved	
	deque<ast>::iterator it = astlist.begin() + (yyvsp[(6) - (8)].ival);
	
	ast ifast = ast(ifptr);
	ast fiast = ast(fiptr);
	ast condast = ast(condptr);
	
	astlist.insert(it,condast);
	it = astlist.begin() + (yyvsp[(6) - (8)].ival);
	astlist.insert(it,ifast);
	astlist.push_back(fiast);
	(yyval.ival) = (yyvsp[(6) - (8)].ival);

	//Symbol Table Generation code
	if((yyvsp[(5) - (8)].fief) != 0){	
		string s1("Symbol table IF");
		//fief has to be void in order to be transferrable in C union
		list<string>*vectorptr = (list<string>*)(yyvsp[(5) - (8)].fief);	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table IF");
		list<string>*newfief = new list<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}		
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 757 "src/Micro.y"
    {	
	//AST and Control Structure code	
	ast elseast;
	elseast = ast();
	node *elseptr = elseast.newval("ELSE");
	//cout << "Size of list after ELSE: " << $<ival>3 << endl;
	deque<ast>::iterator it = astlist.begin() + (yyvsp[(3) - (3)].ival);
	//cout << *((*it).root->value) << endl;
	astlist.insert(it,elseast);

	//Symbol Table Generation code
	if((yyvsp[(2) - (3)].fief) != 0){	
		string s1("Symbol table ELSE");
		//fief has to be void in order to be transferrable in C union
		list<string>*vectorptr = (list<string>*)(yyvsp[(2) - (3)].fief);	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table ELSE");
		list<string>*newfief = new list<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 788 "src/Micro.y"
    {
	//make new head of the conditional statement
	node *conhead = myast.newmath((yyvsp[(1) - (3)].nval),(yyvsp[(2) - (3)].sval));
	myast.addright(conhead,(yyvsp[(3) - (3)].nval));
	(yyval.nval) = conhead;
	myast.root = 0;
;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 798 "src/Micro.y"
    {(yyval.sval) = ">";;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 800 "src/Micro.y"
    {(yyval.sval) = "<";;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 802 "src/Micro.y"
    {(yyval.sval) = "=";;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 804 "src/Micro.y"
    {(yyval.sval) = "!=";;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 806 "src/Micro.y"
    {(yyval.sval) = "<=";;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 808 "src/Micro.y"
    {(yyval.sval) = ">=";;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 812 "src/Micro.y"
    {
	(yyval.nval) = (yyvsp[(1) - (1)].nval);
	myast.root = 0;
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 817 "src/Micro.y"
    {
	(yyval.nval) = (yyvsp[(1) - (1)].nval);
	myast.root = 0
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 824 "src/Micro.y"
    {
	(yyval.nval) = (yyvsp[(1) - (1)].nval);
	myast.root = 0;
;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 829 "src/Micro.y"
    {
	(yyval.nval) = (yyvsp[(1) - (1)].nval);
	myast.root = 0;
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 836 "src/Micro.y"
    {
	//AST and Control Structure code	
	//insert conditional ast
	ast tempast = ast((yyvsp[(5) - (11)].nval));
	deque<ast>::iterator it = astlist.begin() + (yyvsp[(10) - (11)].ival);
	astlist.insert(it, tempast);

	//insert FOR ast marker
	tempast = ast();
	node *ptr = tempast.newval("FOR");
	it = astlist.begin() + (yyvsp[(10) - (11)].ival);
	astlist.insert(it, tempast);	
	
	//insert optional init ast
	if ((yyvsp[(3) - (11)].nval) != 0){
		tempast = ast((yyvsp[(3) - (11)].nval));
		it = astlist.begin() + (yyvsp[(10) - (11)].ival);
		astlist.insert(it,tempast);
	}
	
	//insert ROF and increment at the end
	tempast = ast((yyvsp[(7) - (11)].nval));
	astlist.push_back(tempast);
	tempast = ast();
	ptr = tempast.newval("ROF");
	astlist.push_back(tempast);


	//Symbol Table Generation code
	if((yyvsp[(9) - (11)].fief) != 0){		
		string s1("Symbol table FOR");	
		//fief has to be void in order to be transferrable in C union
		list<string>*vectorptr = (list<string>*)(yyvsp[(9) - (11)].fief);	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table FOR");
		list<string>*newfief = new list<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}
		
;}
    break;



/* Line 1455 of yacc.c  */
#line 2594 "Micro.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 886 "src/Micro.y"


void printList(ast myast) {
	while (!astlist.empty()) {
 		myast.postorder((astlist.front()).root);
 		astlist.pop_front();
	}
}

void generateIRPostOrderList(node *head) {
	if(head != 0){
		generateIRPostOrderList(head->left);
		generateIRPostOrderList(head->right);
		astPostOrder.push_back(*(head->value));
		cout<<*(head->value)<<endl;
	}
}

void checkDatatype(string var) {
	list <string> varlistTemp = varlist;
	string type;
	string varTemp;
	int flag = 0;
	while(!varlistTemp.empty()) {
	istringstream iss(varlistTemp.front());
	iss >> type;
	iss >> varTemp;
	//cout<<type<<endl;
	if(varTemp == var) {
		flag = 1;
		if(type == "INT") {
			datatype = "i";
		}
		else if(type == "FLOAT") {
			datatype = "f";
		}
		else {
			datatype = "s";
		}
	}
	varlistTemp.pop_front();
	}

	if(flag == 0) {
		if(var.find('.') != string::npos) {
			datatype = "f";
		}
		else {
			datatype = "i";
		}

	}
}

map <string,string> populateSymbolTable(string functionName, map <string, string> tempMap, map <string, string> paramMap) {
	list <string> varlistTemp = varlist;
	string variableTemp1 = "";
	string variableTemp2 = "";
	string variableTemp3 = "";
	localVal = 1;
	

	int functionFoundFlag = 0;

	ostringstream convert;

	while(!varlistTemp.empty()) {
		variableTemp1 = "";
		variableTemp2 = "";
		variableTemp3 = "";

		istringstream iss2(varlistTemp.front());
		iss2 >> variableTemp1;
		iss2 >> variableTemp2;
		iss2 >> variableTemp3;

		/*cout<<"VariableTemp1 -->"<<variableTemp1<<endl;
		cout<<"VariableTemp2 -->"<<variableTemp2<<endl;
		cout<<"VariableTemp3 -->"<<variableTemp3<<endl;*/
	
		if(variableTemp1 == "Symbol") {
			if(functionFoundFlag == 1) {
				break;
			}
			else {
				if(variableTemp3 == functionName) {
					functionFoundFlag = 1;
				}
			}
		}
		else {
			if(functionFoundFlag == 1) {
  				if(paramMap.find(variableTemp2) == paramMap.end()){
					if(functionName == "GLOBAL") {
						tempMap[variableTemp2] = variableTemp2;
					}
					else {
						convert.str("");
						convert << localVal;
						tempMap[variableTemp2] = "$L"+convert.str();
						localVal++;
					}
				}
				else{
					//It is a parameter!
				}
			}
		}	

		varlistTemp.pop_front();		
	}

	return tempMap;
}

map <string,string> populateDatatypeTableIR(string functionName) {
	list <string> varlistTemp = varlist;
	string variableTemp1 = "";
	string variableTemp2 = "";
	string variableTemp3 = "";
	localVal = 1;
	
	map<string, string> tempMap;
	tempMap.clear();
	int functionFoundFlag = 0;

	ostringstream convert;

	while(!varlistTemp.empty()) {
		variableTemp1 = "";
		variableTemp2 = "";
		variableTemp3 = "";

		istringstream iss2(varlistTemp.front());
		iss2 >> variableTemp1;
		iss2 >> variableTemp2;
		iss2 >> variableTemp3;

		/*cout<<"VariableTemp1 -->"<<variableTemp1<<endl;
		cout<<"VariableTemp2 -->"<<variableTemp2<<endl;
		cout<<"VariableTemp3 -->"<<variableTemp3<<endl;*/
	
		if(variableTemp1 == "Symbol") {
			if(functionFoundFlag == 1) {
				break;
			}
			else {
				if(variableTemp3 == functionName) {
					functionFoundFlag = 1;
				}
			}
		}
		else {
			if(functionFoundFlag == 1) {
  				tempMap[variableTemp2] = variableTemp1;
				//cout<<"VARIABLE-->"<<variableTemp2<<" TYPE-->"<<variableTemp1<<endl;
			}
		}	

		varlistTemp.pop_front();		
	}

	return tempMap;
}

map <string,string> populateDatatypeTableTiny(string functionName, map<string, string> referenceTable) {
	list <string> varlistTemp = varlist;
	string variableTemp1 = "";
	string variableTemp2 = "";
	string variableTemp3 = "";
	localVal = 1;
	
	map<string, string> tempMap;
	tempMap.clear();
	int functionFoundFlag = 0;

	ostringstream convert;

	while(!varlistTemp.empty()) {
		variableTemp1 = "";
		variableTemp2 = "";
		variableTemp3 = "";

		istringstream iss2(varlistTemp.front());
		iss2 >> variableTemp1;
		iss2 >> variableTemp2;
		iss2 >> variableTemp3;

		/*cout<<"VariableTemp1 -->"<<variableTemp1<<endl;
		cout<<"VariableTemp2 -->"<<variableTemp2<<endl;
		cout<<"VariableTemp3 -->"<<variableTemp3<<endl;*/
	
		if(variableTemp1 == "Symbol") {
			if(functionFoundFlag == 1) {
				break;
			}
			else {
				if(variableTemp3 == functionName) {
					functionFoundFlag = 1;
				}
			}
		}
		else {
			if(functionFoundFlag == 1) {
  				tempMap[referenceTable[variableTemp2]] = variableTemp1;
				//cout<<"VARIABLE-->"<<referenceTable[variableTemp2]<<" TYPE-->"<<variableTemp1<<endl;
			}
		}	

		varlistTemp.pop_front();		
	}

	return tempMap;
}

int isInTable(string n) {
	int retVal = 1;

	if(datatypeTableIR.find(n) == datatypeTableIR.end()){
		retVal = 0;
	}

	return retVal;
}

string intOrFloat(string input) {
	int i=0;
	string retVal = "INT";
	for (i = 0; i<input.length(); i++) {
		if(input[i] == '.') {
			retVal = "FLOAT";
			break;
		}
	}
	return retVal;
}

void generateIRList() {
	ast astNode = ast();
	list<string> temp;
	string op1;
	string op2;
	string result;

	string regStore,regStore1,regStore2;
	string IRDisplay;
	string label, templabel1, templabel2;
	string tempActivity;
	string funcDeclaration;
	string firstWord;
	ostringstream convert;

	string returnType;
	string functionName;
	string variableName;

	map <string, string> tempMap1;  //For Symbol Table
	map <string, string> tempMap2;  //For Datatype Table IR
	map <string, string> tempMap3;  //For Datatype Table Tiny

	while (!astlist.empty()) {
		astNode = astlist.front();
		generateIRPostOrderList(astNode.root);
		astlist.pop_front();
	}

	tempMap1.clear();
	tempMap2.clear();
	tempMap3.clear();
	tempMap1 = populateSymbolTable("GLOBAL", tempMap1, tempMap1);
	tempMap2 = populateDatatypeTableIR("GLOBAL");
	tempMap3 = populateDatatypeTableTiny("GLOBAL", tempMap1);
	symbolTable["GLOBAL"] = tempMap1;
	datatypeTableIR["GLOBAL"] = tempMap2;
	datatypeTableTiny["GLOBAL"] = tempMap3;

	while(!astPostOrder.empty()) {
		/*
		if (IRNodeList.front()[0] != '=' || IRNodeList.front()[0] != '+' || IRNodeList.front()[0] != '-' || IRNodeList.front()[0] != '*' || IRNodeList.front()[0] != '/' || IRNodeList.front() != "READ" || IRNodeList.front() != "WRITE") {
			temp.push_back (IRNodeList.front());
			//temp.push_back ("OP");
		}
		else {
			temp.push_back ("OP");
			
		}
		*/
		
		istringstream  iss(astPostOrder.front());
		iss >> firstWord;
		//cout<<"First Word-->"<<firstWord<<endl;
		if(astPostOrder.front() == ":=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			if(datatypeTableIR[currentScope][op1] == "INT") {
				IRDisplay = "STOREI "+op2+" "+symbolTable[currentScope][op1];
				IRNodeList.push_back(IRDisplay);
			}
			else if (datatypeTableIR[currentScope][op1] == "FLOAT") {
				IRDisplay = "STOREF "+op2+" "+symbolTable[currentScope][op1];
				IRNodeList.push_back(IRDisplay);
			}
		}
		else if (astPostOrder.front()[0] == '+') {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			string dataOperation = "INT";
			
			if(isInTable(op1)){
				dataOperation = datatypeTableIR[currentScope][op1];
			}
			else if(isInTable(op2)){
				dataOperation = datatypeTableIR[currentScope][op2];
			}
			if(!isInTable(op1)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op1) == "INT") {
					IRDisplay = "STOREI "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op1 = regStore;
			}
			else if(!isInTable(op2)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op2) == "INT") {
					IRDisplay = "STOREI "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op2 = regStore;
			}
			
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();
			registerValue = registerValue + 1;
			convert.str("");

			if(dataOperation == "INT"){
				IRDisplay = "ADDI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "ADDF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			convert.str("");
			
		}

		else if (astPostOrder.front()[0] == '-') {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			string dataOperation = "INT";
			
			if(isInTable(op1)){
				dataOperation = datatypeTableIR[currentScope][op1];
			}
			else if(isInTable(op2)){
				dataOperation = datatypeTableIR[currentScope][op2];
			}
			if(!isInTable(op1)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op1) == "INT") {
					IRDisplay = "STOREI "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op1 = regStore;
			}
			else if(!isInTable(op2)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op2) == "INT") {
					IRDisplay = "STOREI "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op2 = regStore;
			}
			
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();
			registerValue = registerValue + 1;
			convert.str("");

			if(dataOperation == "INT"){
				IRDisplay = "SUBI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "SUBF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			convert.str("");
		}
		
		else if (astPostOrder.front()[0] == '*') {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			string dataOperation = "INT";
			
			if(isInTable(op1)){
				dataOperation = datatypeTableIR[currentScope][op1];
			}
			else if(isInTable(op2)){
				dataOperation = datatypeTableIR[currentScope][op2];
			}
			if(!isInTable(op1)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op1) == "INT") {
					IRDisplay = "STOREI "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op1 = regStore;
			}
			else if(!isInTable(op2)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op2) == "INT") {
					IRDisplay = "STOREI "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op2 = regStore;
			}
			
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();
			registerValue = registerValue + 1;
			convert.str("");

			if(dataOperation == "INT"){
				IRDisplay = "MULTI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "MULTF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			convert.str("");
		}
	
		else if (astPostOrder.front()[0] == '/') {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			string dataOperation = "INT";
			
			if(isInTable(op1)){
				dataOperation = datatypeTableIR[currentScope][op1];
			}
			else if(isInTable(op2)){
				dataOperation = datatypeTableIR[currentScope][op2];
			}
			if(!isInTable(op1)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op1) == "INT") {
					IRDisplay = "STOREI "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op1+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op1 = regStore;
			}
			else if(!isInTable(op2)) {
				convert.str("");
				convert << registerValue;
				regStore = "$T"+convert.str();
				registerValue = registerValue + 1;
				convert.str("");

				if(intOrFloat(op2) == "INT") {
					IRDisplay = "STOREI "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "INT";
					datatypeTableIR[currentScope][regStore] = "INT";
					dataOperation = "INT";
				}
				else {
					IRDisplay = "STOREF "+op2+" "+ regStore;
					IRNodeList.push_back(IRDisplay);
					datatypeTableTiny[currentScope][regStore] = "FLOAT";
					datatypeTableIR[currentScope][regStore] = "FLOAT";
					dataOperation = "FLOAT";
				}
				op2 = regStore;
			}
			
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();
			registerValue = registerValue + 1;
			convert.str("");

			if(dataOperation == "INT"){
				IRDisplay = "DIVI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "DIVF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			convert.str("");
		}
		
		else if(firstWord == "Function") {
			//Reset regVal (Temp), localVal (Local) and parVal (parameter) to 0
			//Label and Link
			//Generate map of local and parameter values
			regVal = 1;
			localVal = 1;
			parVal = 1;
			registerValue = 1;
			returnType = "";
			functionName = "";

			iss>>returnType;
			iss>>functionName;
			
			IRDisplay = "LABEL "+functionName;
			IRNodeList.push_back(IRDisplay);
			IRDisplay = "LINK";
			IRNodeList.push_back(IRDisplay);
			currentScope = functionName;

			tempMap1.clear();
			tempMap2.clear();
			tempMap3.clear();
			//cout<<endl<<"Function name-->"<<functionName<<endl;
			while(iss >> variableName) {
				convert.str("");
				convert << parVal;
				tempMap1[variableName] = "$P"+convert.str();
				parVal++;
			}					
			tempMap1 = populateSymbolTable(functionName, tempMap1, tempMap1);
			tempMap2 = populateDatatypeTableIR(functionName);
			tempMap3 = populateDatatypeTableTiny(functionName, tempMap1);

			symbolTable[functionName] = tempMap1;
			datatypeTableIR[functionName] = tempMap2;
			datatypeTableTiny[functionName] = tempMap3;
		
		}

		else if(astPostOrder.front() == "CALL") {
			//Generate activation record
		}

		else if(astPostOrder.front() == "RETURN") {
			//RET
			IRDisplay = "RET";
			IRNodeList.push_back(IRDisplay);
		}

		else if(astPostOrder.front() == "IF") {
			activityStack.push_front("IF");

			//Else label
			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();

			labelStack.push_front(label);
			labelCount++;
			//Exit label

			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();

			labelStack.push_front(label);
			labelCount++;
		}
		else if(astPostOrder.front() == "ELSE") {
			activityStack.push_front("ELSE");
		
			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.pop_front();
			IRDisplay = "JUMP "+templabel1;
			IRNodeList.push_back(IRDisplay);
			IRDisplay = "LABEL "+templabel2;
			IRNodeList.push_back(IRDisplay);
			
			labelStack.push_front(templabel1);
		}
		else if(astPostOrder.front() == "FI") {
			tempActivity = activityStack.front();
			activityStack.pop_front();
		
			if(tempActivity == "IF") {
				//IF -- FI
				
				templabel1 = labelStack.front();
				labelStack.pop_front();
				IRDisplay = "JUMP "+templabel1;
				IRNodeList.push_back(IRDisplay);

				templabel2 = labelStack.front();
				labelStack.pop_front();				
				IRDisplay = "LABEL "+templabel2;
				IRNodeList.push_back(IRDisplay);

				IRDisplay = "LABEL "+templabel1;
				IRNodeList.push_back(IRDisplay);
			
				//labelStack.push_front(templabel1);
			}
			else {
				//IF -- ELSE -- FI
				activityStack.pop_front();
				templabel1 = labelStack.front();
				labelStack.pop_front();
				//templabel1 = labelStack.front();
				//labelStack.pop_front();
				IRDisplay = "JUMP "+templabel1;
				IRNodeList.push_back(IRDisplay);
				IRDisplay = "LABEL "+templabel1;
				IRNodeList.push_back(IRDisplay);
			
				//labelStack.push_front(templabel1);
			}
		}

		else if (astPostOrder.front() == "FOR") {
			//Out label
			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();

			labelStack.push_front(label);
			labelCount++;
			//For label

			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();
			
			IRDisplay = "LABEL "+label;
			IRNodeList.push_back(IRDisplay);

			labelStack.push_front(label);
			labelCount++;
		}

		else if (astPostOrder.front() == "ROF") {
			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.pop_front();
			IRDisplay = "JUMP "+templabel1;
			IRNodeList.push_back(IRDisplay);
			IRDisplay = "LABEL "+templabel2;
			IRNodeList.push_back(IRDisplay);
			
			//labelStack.push_front(templabel1);
		}
		

		
		else if (astPostOrder.front() == "<") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "GE "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == "<=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "GT "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == ">") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "LE "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == ">=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "LT "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == "=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "NE "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == "!=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "EQ "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}
		
		else if(astPostOrder.front() == "READ") {

			op1 = temp.back();
			
			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			
			if(datatype == "i") {
				IRDisplay = "READI "+op1;		
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "READF "+op1;		
				IRNodeList.push_back(IRDisplay);
			}
			temp.pop_back();
		}

		else if(astPostOrder.front() == "WRITE") {

			op1 = temp.back();
			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			
			if(datatype == "i") {
				IRDisplay = "WRITEI "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			else if(datatype == "f") {
				IRDisplay = "WRITEF "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "WRITES "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			temp.pop_back();
		}
		else {
			temp.push_back(astPostOrder.front());
		}
		astPostOrder.pop_front();
	}

	list <string> IRNodeListDisplay = IRNodeList;
	IRList = IRNodeList;	
	list<string>::iterator it = IRNodeListDisplay.begin(); 
	for (it; it != IRNodeListDisplay.end();it++){
		//cout << *it << endl;
		myIRlist.push_back(*it);
	}
	
       	/*cout<<";IR code"<<endl;
	while (!IRNodeListDisplay.empty()) {
		cout<<";"<<IRNodeListDisplay.front()<<endl;
		IRNodeListDisplay.pop_front();
	}*/
	
}	

int getRegister(string IRReg){
	int strLen = IRReg.length();
	string IRRegVal =  IRReg.substr(2, strLen-2);
	int regReturn = atoi(IRRegVal.c_str()) - 1;
	
	return regReturn;
}
	

list<string> generateTinyCode() {
	list<string> tinyCode;
	
	

	while(!IRList.empty()){
		string stmtIR = IRList.front();
		string temp;
		string op;
		string op1;
		string op2;
		string result;
		string label;
		int regVal1;
		int regVal2;
		int regVal3;
	
		string tinyStmt;

		temp = stmtIR;

		istringstream iss(temp);

		iss>>op;
		
		//tinyCode.push_back(op);

		//ADDI op1 op2 Result
		if (op == "ADDI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addi "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addi r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//ADDF op1 op2 Result
		else if (op == "ADDF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//SUBI op1 op2 Result
		else if (op == "SUBI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subi "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subi r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//SUBF op1 op2 Result
		else if (op == "ADDF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}

		//MULTI op1 op2 Result
		else if (op == "MULTI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "muli "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "muli r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}

		//MULTF op1 op2 Result
		else if (op == "MULTF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "mulr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "mulr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//DIVI op1 op2 Result
		else if (op == "DIVI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divi "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divi r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}		

		//DIVF op1 op2 Result
		else if (op == "DIVF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}	

		//STOREI op1 Result
		else if (op == "STOREI") {
			iss >> op1;
			iss >> result;
			tinyStmt = "move ";
			ostringstream convert;

			if(op1[0] == '$'){
				convert.str("");
				regVal1 = getRegister(op1);
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
				
			}
			else {
				tinyStmt = tinyStmt+op1+" ";
			}

			if(result[0] == '$'){
				convert.str("");
				regVal2 = getRegister(result);
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
				
			}
			else {
				tinyStmt = tinyStmt+result+" ";
				
			}
			//regVal = regVal + 1;
			tinyCode.push_back(tinyStmt);	
				
			
		}
		//STOREF op1 Result
		else if (op == "STOREF") {
			iss >> op1;
			iss >> result;
			tinyStmt = "move ";
			ostringstream convert;

			if(op1[0] == '$'){
				convert.str("");
				regVal1 = getRegister(op1);
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
				
			}
			else {
				tinyStmt = tinyStmt+op1+" ";
			}

			if(result[0] == '$'){
				convert.str("");
				regVal2 = getRegister(result);
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
				
			}
			else {
				tinyStmt = tinyStmt+result+" ";
				
			}

			//regVal = regVal + 1;
			tinyCode.push_back(tinyStmt);	
				
			
		}
		//GT op1 op2 label
		else if (op == "GT") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jgt "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//GE op1 op2 label
		else if (op == "GE") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jge "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//LT op1 op2 label
		else if (op == "LT") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jlt "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//LE op1 op2 label
		else if (op == "LE") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jle "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//NE op1 op2 label
		else if (op == "NE") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jne "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//EQ op1 op2 label
		else if (op == "EQ") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jeq "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//JUMP label
		else if (op == "JUMP") {
			iss >> result;

			tinyStmt = "jmp "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//LABEL label
		else if (op == "LABEL") {
			iss >> result;

			tinyStmt = "label "+result;
			tinyCode.push_back(tinyStmt);
		}		

		//READI
		else if (op == "READI") {
			iss >> result;
	
			tinyStmt = "sys readi "+result;
			tinyCode.push_back(tinyStmt);
		}
		//READF
		else if (op == "READF") {
			iss >> result;
	
			tinyStmt = "sys readr "+result;
			tinyCode.push_back(tinyStmt);
		}
		//WRITEI
		else if (op == "WRITEI") {
			iss >> result;
	
			tinyStmt = "sys writei "+result;
			tinyCode.push_back(tinyStmt);
		}
		//WRITEF
		else if (op == "WRITEF") {
			iss >> result;
	
			tinyStmt = "sys writer "+result;
			tinyCode.push_back(tinyStmt);
		}

		//WRITES
		else if (op == "WRITES") {
			iss >> result;

			tinyStmt = "sys writes "+result;
			tinyCode.push_back(tinyStmt);
		}

		IRList.pop_front();
	}
	
	tinyCode.push_back("sys halt");
	return tinyCode;
}

int main(int argc, char *argv[]) {
	if (argc != 2){
		printf("Error! Usage: Micro <filename>");
	}
	else{
		FILE *myfile = fopen(argv[1], "r");	
		if (!myfile) {
			cout << "File could not be opened" << endl;
			return -1;
		}
		yyin = myfile;
		myast = ast();
		do {
			yyparse();
		} while (!feof(yyin));

		//Access astlist here like any linked list 
		/*while (!astlist.empty()){
			ast tempast = astlist.front();
			//cout << "New tree marker" << endl;
			myast.postorder(tempast.root);	
			astlist.pop_front();
		}*/

		//Backup IRlist from step6, dont delete this commented block
		/*	
		myIRlist.clear();
		ifstream infile("testfile");
		if(!infile){
			cerr << "File not found." << endl;
			return -1;
		}
		string line;
		while (getline(infile, line)){
			myIRlist.push_back(line);
		}
		vector<string>::iterator it1 = myIRlist.begin();
		for (it1; it1 != myIRlist.end(); it1++){
			cout << (*it1) << endl;
		}
		*/

		generateIRList();	
		
		//Michael's code
		map<string,vector<int> > leaders;
		//Vector to store GEN and KILL for each IR node
		vector<set<string> > GEN(myIRlist.size());
		vector<set<string> > KILL(myIRlist.size());
		set<string> globalGEN;
		set<string> tempGEN;
		set<string> tempKILL;
		
		list<string>::iterator it5 = varlist.begin();
		it5++;
		while((*it5).find("Symbol table") == string::npos){
			string id;
			stringstream extract(*it5);
			extract >> id;
			extract >> id;
			globalGEN.insert(id);
			it5++;
		}
		leaders = cfg::findleaders(myIRlist);
		cfglist = cfg::generateCFG(myIRlist, leaders);
		//cfg::printcfg(cfglist);	
		
		int i = 0;
		for(vector<string>::iterator it6 = myIRlist.begin(); it6 != myIRlist.end(); it6++){
			string opcode;
			stringstream irnode(*it6);
			irnode >> opcode;
			if (opcode == "STOREI"){
				int test;
				if((irnode >> test).fail()){
					irnode.str("");
					irnode.clear();
					irnode.str(*it6);
				//	cout << "Variable usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					tempGEN.insert(opcode);
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
				else{
				//	cout << "constant usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
			}
			else if (opcode == "STOREF"){
				float test;
				if((irnode >> test).fail()){
					irnode.str("");
					irnode.clear();
					irnode.str(*it6);
				//	cout << "Variable usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					tempGEN.insert(opcode);
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
				else{
				//	cout << "constant usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
			}
			else if (opcode == "ADDI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "ADDF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();			
			}
			else if (opcode == "SUBI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();	
			}
			else if (opcode == "SUBF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();

			}
			else if (opcode == "MULTI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "MULTF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "DIVI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "DIVF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "READI"){
				string arg1;
				irnode >> arg1;
				tempKILL.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "READF"){
				string arg1;
				irnode >> arg1;
				tempKILL.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "WRITES"){
				string arg1;
				irnode >> arg1;
				tempGEN.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "WRITEI"){
				string arg1;
				irnode >> arg1;
				tempGEN.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "WRITEF"){
				string arg1;
				irnode >> arg1;
				tempGEN.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "PUSH"){
				string arg1;
				irnode >> arg1;
				if (arg1 == ""){;}
				else{tempGEN.insert(arg1);}
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "POP"){
				string arg1;
				irnode >> arg1;
				if (arg1 == ""){;}
				else{tempKILL.insert(arg1);}
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();	
			}
			else if (opcode == "JSR"){
				GEN[i] = globalGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else{
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			i++;
		}
		
		/*i=0;
		cout << "BEGIN DISPLAYING GEN FOR EACH IR NODE" << endl;
		vector<set<string> >::iterator it7 = GEN.begin();
		for (it7; it7 != GEN.end(); it7++){
			cout << myIRlist[i] << endl;
			set<string>::iterator it8 = (*it7).begin();
			for (it8; it8 != (*it7).end(); it8++){
				cout << *it8 << endl;
			}
			i++; 
		}
		i=0;
		cout << "BEGIN DISPLAYING KILL FOR EACH IR NODE" << endl;
		vector<set<string> >::iterator it9 = KILL.begin();
		for (it9; it9 != KILL.end(); it9++){
			cout << myIRlist[i] << endl;
			set<string>::iterator it10 = (*it9).begin();
			for (it10; it10 != (*it9).end(); it10++){
				cout << *it10 << endl;
			}
			i++; 
		}*/
	
		//Michael's code end
		
		//View Symbol Table
		/*
		cout<<"SYMBOL TABLE"<<endl<<endl;
		for (map < string, map <string, string> >::iterator it1=symbolTable.begin(); it1!=symbolTable.end(); ++it1) {
				cout<<"SCOPE-->"<<it1->first<<endl;
				for (map < string, string>::iterator it2=symbolTable[it1->first].begin(); it2!=symbolTable[it1->first].end(); ++it2) {
					cout<<it2->first<<"-->"<<it2->second<<endl;
				}
				cout<<endl;
		}
		

		//View Datatype Table IR
		cout<<"IR DATATYPE TABLE"<<endl<<endl;
		for (map < string, map <string, string> >::iterator it1=datatypeTableIR.begin(); it1!=datatypeTableIR.end(); ++it1) {
				cout<<"SCOPE-->"<<it1->first<<endl;
				for (map < string, string>::iterator it2=datatypeTableIR[it1->first].begin(); it2!=datatypeTableIR[it1->first].end(); ++it2) {
					cout<<it2->first<<"-->"<<it2->second<<endl;
				}
				cout<<endl;
		}

		//View Datatype Table Tiny
		cout<<"TINY DATATYPE TABLE"<<endl<<endl;
		for (map < string, map <string, string> >::iterator it1=datatypeTableTiny.begin(); it1!=datatypeTableTiny.end(); ++it1) {
				cout<<"SCOPE-->"<<it1->first<<endl;
				for (map < string, string>::iterator it2=datatypeTableTiny[it1->first].begin(); it2!=datatypeTableTiny[it1->first].end(); ++it2) {
					cout<<it2->first<<"-->"<<it2->second<<endl;
				}
				cout<<endl;
		}
		*/
		list<string> tinyCode = generateTinyCode();
		list<string> varlistTemp = varlist;
		list<string> varlistLoad;
		string var;
		string varTemp;
		string strName;
		string strVal;

		while(!varlistTemp.empty()) {
			//NOTE: strings in this list are actual strings not pointers
			//This is example code for iterating through the list
			//cout <<*iterator << endl;
			//i = i + 1;
			istringstream iss(varlistTemp.front());
			var = "";
			iss>>var;
			if(var == "STRING") {
				//var = "";
				iss>>strName;
				varTemp  = "str "+strName;
				//iss>>strVal;
				strVal = varlistTemp.front().erase(0,var.length()+strName.length()+2);
				varTemp = varTemp+" "+strVal;
				varlistLoad.push_front(varTemp);
				varlistTemp.pop_front();
			}
			else {
				var = "";
				iss>>var;
				varTemp = "var "+var;
				varlistLoad.push_front(varTemp);
				varlistTemp.pop_front();
			}
		}

		while(!varlistLoad.empty()) {
			tinyCode.push_front(varlistLoad.front());
			varlistLoad.pop_front();
		}
		/*cout<<";tiny code"<<endl;
		while (!tinyCode.empty()) {
			cout<<tinyCode.front()<<endl;
			tinyCode.pop_front();
		}*/
	}//END OF ELSE STATEMENT
	
}


