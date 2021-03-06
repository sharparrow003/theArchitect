
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
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
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
class ast {
	public:
		ast();
		~ast();
		node *root;
		node *newval(string);
		node *newop(node *, string);
		node *newmath(node *, string);	
		void destroy_tree();
		void addright(node *, node *);
		void inorder(node *);
		void preorder(node *);
		void postorder(node *);
	private:
		void destroy_tree(node *);
};
//int scope;
ast myast;
list<ast> astlist;
list<string> varlist;
list<string> astPostOrder;
list<string> IRNodeList;
static int registerValue = 1;
list <string> IRList;
string datatype="i";
static node * exprhead = 0;
void printList(list<string> strList);				//Prints out list ***NOT IMPORTANT***
list<string> generateTinyCode();		//Generates tiny code from the list of IR Nodes  ***IMPORTANT***
int getRegister(string IRReg);					//Calculates the register number from IR Node ***IMPORTANT***

int regVal = 0;

void yyerror(const char *s) { cout << "Not Accepted" << endl; exit(0); }


/* Line 189 of yacc.c  */
#line 126 "Micro.tab.c"

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
     COMPOP = 280,
     ASSMTOP = 281,
     OPENPAROP = 282,
     CLOSEPAROP = 283,
     SCOLONOP = 284,
     COMMAOP = 285,
     INTLIT = 286,
     FLTLIT = 287,
     STRLIT = 288,
     IDENTIFIER = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 52 "src/Micro.y"

	int ival;
	float fval;
	char *sval;
	char *iden;
	struct node *nval;



/* Line 214 of yacc.c  */
#line 206 "Micro.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 218 "Micro.tab.c"

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
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
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
     208,   210,   222
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,     3,    37,     4,    38,     5,    -1,    34,
      -1,    39,    50,    -1,    40,    39,    -1,    42,    39,    -1,
      79,    -1,    19,    37,    26,    41,    29,    -1,    33,    -1,
      43,    45,    29,    -1,    20,    -1,    17,    -1,    43,    -1,
      18,    -1,    37,    46,    -1,    30,    37,    46,    -1,    79,
      -1,    48,    49,    -1,    79,    -1,    43,    37,    -1,    30,
      48,    49,    -1,    79,    -1,    51,    50,    -1,    79,    -1,
       6,    44,    37,    27,    47,    28,     4,    52,     5,    -1,
      39,    53,    -1,    54,    53,    -1,    79,    -1,    55,    -1,
      72,    -1,    78,    -1,    56,    -1,    58,    -1,    59,    -1,
      60,    -1,    57,    29,    -1,    37,    26,    61,    -1,     7,
      27,    45,    28,    29,    -1,     8,    27,    45,    28,    29,
      -1,    16,    61,    29,    -1,    62,    63,    -1,    62,    63,
      70,    -1,    79,    -1,    64,    65,    -1,    64,    65,    71,
      -1,    79,    -1,    69,    -1,    66,    -1,    37,    27,    67,
      28,    -1,    61,    68,    -1,    79,    -1,    30,    61,    68,
      -1,    79,    -1,    27,    61,    28,    -1,    37,    -1,    31,
      -1,    32,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,     9,    27,    74,    28,    39,    53,    73,    11,    -1,
      10,    39,    53,    -1,    79,    -1,    61,    75,    61,    -1,
      25,    -1,    57,    -1,    79,    -1,    57,    -1,    79,    -1,
      12,    27,    76,    29,    74,    29,    77,    28,    39,    53,
      13,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    96,    98,   100,   101,   102,   104,   108,
     110,   123,   124,   127,   128,   130,   145,   160,   165,   168,
     170,   174,   174,   176,   176,   178,   180,   182,   182,   184,
     184,   184,   186,   186,   186,   186,   188,   201,   212,   229,
     246,   248,   262,   280,   283,   296,   313,   316,   320,   322,
     324,   324,   326,   326,   328,   338,   343,   350,   358,   360,
     363,   365,   368,   372,   379,   381,   383,   385,   385,   387,
     387,   389,   393
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
  "SUBOP", "MULOP", "DIVOP", "COMPOP", "ASSMTOP", "OPENPAROP",
  "CLOSEPAROP", "SCOLONOP", "COMMAOP", "INTLIT", "FLTLIT", "STRLIT",
  "IDENTIFIER", "$accept", "program", "id", "pgm_body", "decl",
  "string_decl", "str", "var_decl", "var_type", "any_type", "id_list",
  "id_tail", "param_decl_list", "param_decl", "param_decl_tail",
  "func_declarations", "func_decl", "func_body", "stmt_list", "stmt",
  "base_stmt", "assign_stmt", "assign_expr", "read_stmt", "write_stmt",
  "return_stmt", "expr", "expr_prefix", "factor", "factor_prefix",
  "postfix_expr", "call_expr", "expr_list", "expr_list_tail", "primary",
  "addop", "mulop", "if_stmt", "else_part", "cond", "compop", "init_stmt",
  "incr_stmt", "for_stmt", "empty", 0
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
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    38,    39,    39,    39,    40,    41,
      42,    43,    43,    44,    44,    45,    46,    46,    47,    47,
      48,    49,    49,    50,    50,    51,    52,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    56,    57,    58,    59,
      60,    61,    62,    62,    63,    64,    64,    65,    65,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    74,    75,    76,    76,    77,
      77,    78,    79
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
       1,    11,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,    72,    12,     0,    11,
       0,    72,    72,    72,     0,     7,     0,     2,     0,     4,
      72,    24,     5,     6,    72,     0,     0,    14,    13,     0,
      23,     0,    15,    17,    10,     9,     0,     0,    72,     8,
      72,    16,     0,     0,    72,    19,    20,     0,     0,    18,
      22,    72,    72,    72,     0,    21,     0,     0,     0,     0,
      72,     0,    26,    72,    29,    32,     0,    33,    34,    35,
      30,    31,    28,    25,     0,     0,    72,    72,     0,    72,
      43,    72,    27,    36,     0,     0,     0,     0,    67,     0,
      68,    40,    41,     0,    46,    37,     0,     0,    66,    72,
      72,    72,    58,    59,    42,    72,    56,    57,    55,    44,
      48,    47,    38,    39,    65,    72,     0,     0,    72,    60,
      61,    45,    72,    72,    54,    72,     0,    43,    72,     0,
      64,    69,     0,    70,    72,    50,    53,    49,    72,    62,
      72,    72,    63,    72,    52,     0,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    61,    10,    11,    12,    36,    13,    14,    29,
      25,    32,    43,    44,    49,    19,    20,    54,    62,    63,
      64,    65,    66,    67,    68,    69,    86,    79,    92,    93,
     109,   110,   126,   135,   111,   104,   121,    70,   129,    87,
      99,    89,   132,    71,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int8 yypact[] =
{
       4,   -31,    10,   -76,     8,   -76,    20,   -76,   -31,   -76,
       9,    25,    20,    20,   -31,   -76,    17,   -76,    38,   -76,
      25,   -76,   -76,   -76,   -14,    -3,     2,   -76,   -76,   -31,
     -76,   -31,   -76,   -76,   -76,   -76,    22,    32,   -14,   -76,
      30,   -76,   -31,    29,    33,   -76,   -76,    60,    30,   -76,
     -76,    20,    33,    12,    62,   -76,    42,    52,    53,    55,
     -76,    57,   -76,    12,   -76,   -76,    56,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -31,   -31,   -76,   -31,    58,   -76,
     -76,   -76,   -76,   -76,    63,    64,    59,    67,   -76,    68,
     -76,   -76,    40,    -9,   -76,   -76,    69,    70,   -76,   -76,
      20,   -76,   -76,   -76,   -76,   -76,   -76,   -76,    73,    48,
     -76,   -76,   -76,   -76,   -76,    12,    72,    74,   -76,   -76,
     -76,   -76,    76,   -31,   -76,    75,    78,    80,    20,    92,
     -76,   -76,    81,   -76,   -76,   -76,   -76,   -76,    12,   -76,
      20,    75,   -76,    12,   -76,    97,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,     3,   -76,    -7,   -76,   -76,   -76,   -10,   -76,
       0,    77,   -76,    65,    66,    96,   -76,   -76,   -62,   -76,
     -76,   -76,   -75,   -76,   -76,   -76,   -45,   -76,   -76,   -76,
     -76,   -76,   -76,   -24,   -76,   -76,   -76,   -76,   -76,    18,
     -76,   -76,   -76,   -76,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      21,    82,    88,     3,     4,    22,    23,     1,    28,    21,
       5,    16,     6,    33,    17,    78,    31,    24,   105,    56,
      57,    58,   106,   107,    59,     3,    34,    33,    60,    45,
      42,    18,    37,    50,    38,    35,    95,     7,    42,     8,
       9,    50,    72,    26,    53,    46,     3,     7,   131,    80,
       9,    39,    72,   122,   114,     7,    27,    47,     9,    40,
     117,   102,   103,    48,    51,    80,    90,    73,    94,    74,
      80,   119,   120,   125,    84,    85,   142,    24,    24,    75,
      76,   145,    77,    81,    98,    83,   128,    91,    80,   141,
      80,    96,    97,   115,    80,   100,   108,   101,   112,   113,
     118,   123,   124,   139,    72,   134,   137,   127,   -51,   140,
     146,   130,   133,    52,   136,    41,    30,   144,    55,   116,
       0,   138,     0,    80,     0,     0,     0,    72,     0,     0,
     136,     0,    72,   143
};

static const yytype_int16 yycheck[] =
{
      11,    63,    77,    34,     1,    12,    13,     3,    18,    20,
       0,     8,     4,    24,     5,    60,    30,    14,    27,     7,
       8,     9,    31,    32,    12,    34,    29,    38,    16,    40,
      40,     6,    29,    44,    31,    33,    81,    17,    48,    19,
      20,    52,    53,    26,    51,    42,    34,    17,   123,    60,
      20,    29,    63,   115,    99,    17,    18,    28,    20,    27,
     105,    21,    22,    30,     4,    76,    77,     5,    79,    27,
      81,    23,    24,   118,    74,    75,   138,    74,    75,    27,
      27,   143,    27,    26,    25,    29,    10,    29,    99,   134,
     101,    28,    28,   100,   105,    28,    93,    29,    29,    29,
      27,    29,    28,    11,   115,    30,    28,   118,    28,    28,
      13,   122,   123,    48,   125,    38,    20,   141,    52,   101,
      -1,   128,    -1,   134,    -1,    -1,    -1,   138,    -1,    -1,
     141,    -1,   143,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    36,    34,    37,     0,     4,    17,    19,    20,
      38,    39,    40,    42,    43,    79,    37,     5,     6,    50,
      51,    79,    39,    39,    37,    45,    26,    18,    43,    44,
      50,    30,    46,    79,    29,    33,    41,    37,    37,    29,
      27,    46,    43,    47,    48,    79,    37,    28,    30,    49,
      79,     4,    48,    39,    52,    49,     7,     8,     9,    12,
      16,    37,    53,    54,    55,    56,    57,    58,    59,    60,
      72,    78,    79,     5,    27,    27,    27,    27,    61,    62,
      79,    26,    53,    29,    45,    45,    61,    74,    57,    76,
      79,    29,    63,    64,    79,    61,    28,    28,    25,    75,
      28,    29,    21,    22,    70,    27,    31,    32,    37,    65,
      66,    69,    29,    29,    61,    39,    74,    61,    27,    23,
      24,    71,    53,    29,    28,    61,    67,    79,    10,    73,
      79,    57,    77,    79,    30,    68,    79,    28,    39,    11,
      28,    61,    53,    39,    68,    53,    13
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
#line 93 "src/Micro.y"
    {
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 96 "src/Micro.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].iden);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 105 "src/Micro.y"
    {
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 108 "src/Micro.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 111 "src/Micro.y"
    {
	string s1((yyvsp[(2) - (3)].sval));
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		string s3 = (yyvsp[(1) - (3)].sval);
		if(s2 != ""){
			varlist.push_back(s3 + " " + s2);			 
		}
	}
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 123 "src/Micro.y"
    {(yyval.sval) = "FLOAT";;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 124 "src/Micro.y"
    {(yyval.sval) = "INT";
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 127 "src/Micro.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 128 "src/Micro.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 130 "src/Micro.y"
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
#line 145 "src/Micro.y"
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
#line 161 "src/Micro.y"
    {
	(yyval.sval) = 0;
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 166 "src/Micro.y"
    {
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 171 "src/Micro.y"
    {
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 189 "src/Micro.y"
    {
        //cout << "Started in order!" << endl;
	//myast.inorder($<nval>1); 
	//cout << "Started pre order!" << endl;
	//myast.preorder($<nval>1);
	//cout << "Started post order!" << endl;
	//myast.postorder($<nval>1);
	//cout << "HEAD-> " << *(myast.root->value) << endl;
	astlist.push_back(myast);
	myast = ast(); 	
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 202 "src/Micro.y"
    {
	node *temp1;
	node *temp2;
	temp1 = myast.newval((yyvsp[(1) - (3)].sval));
	temp2 = myast.newmath(temp1, "=");
	myast.addright(temp2,myast.root);	
	(yyval.nval) = temp2;
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 213 "src/Micro.y"
    {	
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
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 230 "src/Micro.y"
    {
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
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 249 "src/Micro.y"
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
#line 263 "src/Micro.y"
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
#line 281 "src/Micro.y"
    {(yyval.nval) = 0;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 284 "src/Micro.y"
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
#line 297 "src/Micro.y"
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
#line 314 "src/Micro.y"
    {(yyval.nval) = 0;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 317 "src/Micro.y"
    {
	(yyval.nval) = (yyvsp[(1) - (1)].nval);
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 329 "src/Micro.y"
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
#line 339 "src/Micro.y"
    {
	node *temp = myast.newval((yyvsp[(1) - (1)].sval));
	(yyval.nval) = temp;
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 344 "src/Micro.y"
    {
	ostringstream buffer;
	buffer << (yyvsp[(1) - (1)].ival);
	node *temp = myast.newval(buffer.str());
	(yyval.nval) = temp;
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 351 "src/Micro.y"
    {
	ostringstream buffer;
	buffer << (yyvsp[(1) - (1)].fval);
	node *temp = myast.newval(buffer.str());
	(yyval.nval) = temp;
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 359 "src/Micro.y"
    {(yyval.sval) = "+";;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 361 "src/Micro.y"
    {(yyval.sval) = "-";;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 364 "src/Micro.y"
    {(yyval.sval) = "*";;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 366 "src/Micro.y"
    {(yyval.sval) = "/";;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 369 "src/Micro.y"
    {		
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 377 "src/Micro.y"
    {	
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 390 "src/Micro.y"
    {
;}
    break;



/* Line 1455 of yacc.c  */
#line 1950 "Micro.tab.c"
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
#line 395 "src/Micro.y"

ast::ast() {
	root = 0;
}
ast::~ast() {
	if (root != 0){
		//delete root;
	}
}
void ast::destroy_tree(node *leaf){
	if(leaf != 0){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		if (leaf->value != 0){
			delete leaf->value;
			//cout << "Deleted leaf value!" << endl;
		}
		delete leaf;
		//cout << "Deleted whole leaf!" << endl;	
	}
	root = 0;
}
void ast::destroy_tree(){
	destroy_tree(root);
}
void ast::addright(node *head, node *leaf){
	if(leaf != 0 && head != 0){
		if(root == leaf){
			//If adding root node as left, make new root the head
			root = head;
		}	
		head->right = leaf;
	}
}
void ast::inorder(node *head){
	if(head != 0){
		inorder(head->left);
		cout << *(head->value) << endl;
		inorder(head->right);
	}
}
void ast::preorder(node *head){
	if(head != 0){
		cout << *(head->value) << endl;
		preorder(head->left);
		preorder(head->right);
	}
}
void ast::postorder(node *head){
	if(head != 0){
		postorder(head->left);
		postorder(head->right);
		cout << *(head->value) << endl;
	}
}
//node *ast::new(node *value, string operation)
node *ast::newval(string key){
	node *head = new node();
	if (root == 0){root = head;}
	head->value = new string(key);
	head->left = 0;
	head->right = 0;
	return head;
}
node *ast::newop(node *value, string operation){
	node *head = new node();
	if (root == value){root = head;}
	head->value = new string(operation);
	head->left = 0;
	head->right = value;
	return head;	
}
node *ast::newmath(node *value, string operation){
	node *head = new node();
	if (root == value){root = head;}
	head->value = new string(operation);
	head->left = value;
	//cout << "HEAD: " << *(head->value) << "Left " << *(head->left->value) << endl;
	head->right = 0;
	return head;
}

	
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
	}
}

void checkDatatype(string var) {
	list <string> varlistTemp = varlist;
	string type;
	string varTemp;
	
	while(!varlistTemp.empty()) {
		istringstream iss(varlistTemp.front());
		iss >> type;
		iss >> varTemp;

		if(varTemp == var) {
			if(type == "INT") {
				datatype = "i";
			}
			else {
				datatype = "f";
			}
		}
		varlistTemp.pop_front();
	}
}

void generateIRList() {
	ast astNode = ast();
	list<string> temp;
	string op1;
	string op2;
	string result;

	string regStore;
	string IRDisplay;
	ostringstream convert;
	while (!astlist.empty()) {
		astNode = astlist.front();
		generateIRPostOrderList(astNode.root);
		astlist.pop_front();
	}

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
		
		if(astPostOrder.front()[0] == '=') {
			convert << registerValue;
			regStore = "$T"+convert.str();

			op1 = temp.back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			if(datatype == "i") {
				IRDisplay = "STOREI "+op1+" "+regStore;
				IRNodeList.push_back(IRDisplay);
				temp.pop_back();

				op1 = temp.back();
				temp.pop_back();
				IRDisplay = "STOREI "+regStore+" "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "STOREF "+op1+" "+regStore;
				IRNodeList.push_back(IRDisplay);
				temp.pop_back();

				op1 = temp.back();
				temp.pop_back();
				IRDisplay = "STOREF "+regStore+" "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}
		else if (astPostOrder.front()[0] == '+') {
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				//checkDatatype(op2);
			}
			if(datatype == "i") {
				IRDisplay = "ADDI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "ADDF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}

		else if (astPostOrder.front()[0] == '-') {
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();
			
			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				checkDatatype(op2);
			}
			if(datatype == "i") {
				IRDisplay = "SUBI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "SUBF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}
		
		else if (astPostOrder.front()[0] == '*') {
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				checkDatatype(op2);
			}
			if(datatype == "i") {		
				IRDisplay = "MULTI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "MULTF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}
	
		else if (astPostOrder.front()[0] == '/') {
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				checkDatatype(op2);
			}
			if(datatype == "i") {
				IRDisplay = "DIVI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "DIVF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
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
			else {
				IRDisplay = "WRITEF "+op1;
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
	
       	cout<<";IR code"<<endl;
	while (!IRNodeListDisplay.empty()) {
		cout<<";"<<IRNodeListDisplay.front()<<endl;
		IRNodeListDisplay.pop_front();
	}
	
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
		//GT op1 op2 Label
		/*
		else if (op == "GT") {
			iss >> op1;
			iss >> op2;
			iss >> label;

			
		}
		*/
		//GE

		//LT

		//LE

		//NE

		//EQ

		//JUMP

		//LABEL

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
    
    	//Access example below
    	//cout << "Front of the list!" << endl;
    	//myast.inorder((astlist.front()).root);
    	//cout << "Back of the list!" << endl;
    	//myast.inorder((astlist.back()).root);
    
    	/*
    	for (list<string>::const_iterator iterator = varlist.begin(); iterator != varlist.end(); iterator++){
		//NOTE: strings in this list are actual strings not pointers
        	//This is example code for iterating through the list
		cout << i<<" "<<*iterator << endl;
		i = i + 1;
    	}*/
		generateIRList();
  		list<string> tinyCode = generateTinyCode();

  		list<string> varlistTemp = varlist;
		list<string> varlistLoad;
		string var;
		string varTemp;

		while(!varlistTemp.empty()) {
			//NOTE: strings in this list are actual strings not pointers
			//This is example code for iterating through the list
			//cout <<*iterator << endl;
			//i = i + 1;
			istringstream iss(varlistTemp.front());
			var = "";
			iss>>var;
			var = "";
			iss>>var;
			varTemp = "var "+var;
			varlistLoad.push_front(varTemp);
			varlistTemp.pop_front();
    		}

		while(!varlistLoad.empty()) {
			tinyCode.push_front(varlistLoad.front());
			varlistLoad.pop_front();
		}
		cout<<";tiny code"<<endl;
        	while (!tinyCode.empty()) {
			cout<<tinyCode.front()<<endl;
			tinyCode.pop_front();
		}
	}//END OF ELSE STATEMENT
	
}

