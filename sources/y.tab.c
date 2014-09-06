/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     LIBRARY = 259,
     PROC = 260,
     STR = 261,
     INT = 262,
     FLOAT = 263,
     CHR = 264,
     BOOL = 265,
     RULE = 266,
     PROC_ARR = 267,
     STR_ARR = 268,
     INT_ARR = 269,
     FLOAT_ARR = 270,
     CHR_ARR = 271,
     BOOL_ARR = 272,
     RULE_ARR = 273,
     IF = 274,
     ELSEIF = 275,
     ELSE = 276,
     LOOPIF = 277,
     ENTRY = 278,
     IMPORT = 279,
     EXPORT = 280,
     RETURN = 281,
     ID = 282,
     DECIMAL = 283,
     HEXADECIMAL = 284,
     BINARY = 285,
     REAL = 286,
     STRING = 287,
     EQ_OP = 288,
     LT_OP = 289,
     GT_OP = 290,
     LE_OP = 291,
     GE_OP = 292,
     NE_OP = 293,
     AND_OP = 294,
     OR_OP = 295,
     NOT_OP = 296,
     RANGE = 297,
     FUNC_STR = 298,
     FUNC_INT = 299,
     FUNC_FLOAT = 300,
     FUNC_CHR = 301,
     FUNC_BOOL = 302,
     UMINUS = 303
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define LIBRARY 259
#define PROC 260
#define STR 261
#define INT 262
#define FLOAT 263
#define CHR 264
#define BOOL 265
#define RULE 266
#define PROC_ARR 267
#define STR_ARR 268
#define INT_ARR 269
#define FLOAT_ARR 270
#define CHR_ARR 271
#define BOOL_ARR 272
#define RULE_ARR 273
#define IF 274
#define ELSEIF 275
#define ELSE 276
#define LOOPIF 277
#define ENTRY 278
#define IMPORT 279
#define EXPORT 280
#define RETURN 281
#define ID 282
#define DECIMAL 283
#define HEXADECIMAL 284
#define BINARY 285
#define REAL 286
#define STRING 287
#define EQ_OP 288
#define LT_OP 289
#define GT_OP 290
#define LE_OP 291
#define GE_OP 292
#define NE_OP 293
#define AND_OP 294
#define OR_OP 295
#define NOT_OP 296
#define RANGE 297
#define FUNC_STR 298
#define FUNC_INT 299
#define FUNC_FLOAT 300
#define FUNC_CHR 301
#define FUNC_BOOL 302
#define UMINUS 303




/* Copy the first part of user declarations.  */
#line 1 "iq_parser.y"

/*
IQ+ Compiler
Copyright (C) 2009 Dr.Kameleon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*//*

IQ_PARSER.Y

*/

#include <stdio.h>
#include <string.h>
#include "iq_header.h"

pTree* last_node;

void yyerror(const char *str)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", yycolumn, "^", yycolumn, str);
}
 
int yywrap()
{
	return 1;
} 


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 43 "iq_parser.y"
{
	char* str;
	struct pTree* node;
}
/* Line 193 of yacc.c.  */
#line 238 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 251 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,    50,    48,    53,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    63,
       2,    62,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    58,    57,     2,     2,     2,     2,
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
      45,    46,    47,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    49,    51,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    75,    77,    79,
      81,    83,    85,    87,    89,    91,    93,    97,   101,   106,
     110,   113,   115,   119,   123,   127,   131,   135,   139,   143,
     146,   148,   152,   154,   158,   166,   174,   186,   196,   210,
     215,   220,   225,   230,   235,   239,   244,   249,   253,   261,
     269,   276,   284,   291,   302,   312,   319,   329,   332,   336,
     338,   341,   343,   345,   347,   349,   351,   353,   355,   358
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      89,     0,    -1,     3,    -1,     4,    -1,     6,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    43,    -1,    44,    -1,    45,    -1,    46,
      -1,    47,    -1,    65,    -1,    67,    53,    65,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    39,    -1,    40,    -1,    41,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,
      -1,    38,    -1,    69,    -1,    27,    -1,    32,    -1,    74,
      -1,    76,    -1,    73,    53,    72,    -1,    27,    54,    55,
      -1,    27,    54,    73,    55,    -1,    56,    88,    57,    -1,
      56,    57,    -1,    72,    -1,    54,    76,    55,    -1,    54,
      72,    55,    -1,    76,    48,    76,    -1,    76,    49,    76,
      -1,    76,    50,    76,    -1,    76,    51,    76,    -1,    76,
      70,    76,    -1,    49,    72,    -1,    76,    -1,    77,    58,
      76,    -1,    76,    -1,    76,    71,    76,    -1,    22,    59,
      59,    78,    59,    59,    75,    -1,    19,    59,    59,    78,
      59,    59,    75,    -1,    19,    59,    59,    78,    59,    59,
      75,    21,    59,    59,    75,    -1,    19,    59,    59,    54,
      78,    55,    59,    59,    75,    -1,    19,    59,    59,    54,
      78,    55,    59,    59,    75,    21,    59,    59,    75,    -1,
      60,    65,    61,    27,    -1,    68,    62,    76,    63,    -1,
      68,    62,    77,    63,    -1,    27,    62,    76,    63,    -1,
      27,    62,    77,    63,    -1,    27,    62,    75,    -1,    81,
      62,    76,    63,    -1,    81,    62,    77,    63,    -1,    81,
      62,    75,    -1,    81,    54,    67,    55,    62,    76,    63,
      -1,    81,    54,    67,    55,    62,    77,    63,    -1,    81,
      54,    67,    55,    62,    75,    -1,    60,    66,    61,    27,
      62,    76,    63,    -1,    60,    66,    61,    27,    62,    75,
      -1,    60,    66,    61,    27,    54,    67,    55,    62,    76,
      63,    -1,    60,    66,    61,    27,    54,    67,    55,    62,
      75,    -1,    60,     5,    61,    27,    62,    75,    -1,    60,
       5,    61,    27,    54,    67,    55,    62,    75,    -1,    27,
      63,    -1,    27,    73,    63,    -1,    86,    -1,    81,    63,
      -1,    82,    -1,    83,    -1,    80,    -1,    79,    -1,    84,
      -1,    85,    -1,    87,    -1,    88,    87,    -1,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    94,    95,    96,
      97,    98,   102,   103,   107,   108,   109,   110,   114,   115,
     116,   117,   121,   122,   123,   127,   128,   129,   130,   131,
     132,   136,   137,   138,   139,   143,   144,   148,   149,   153,
     154,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     170,   171,   175,   176,   180,   184,   185,   186,   187,   191,
     195,   196,   197,   198,   199,   203,   204,   205,   206,   207,
     208,   212,   213,   214,   215,   219,   220,   224,   225,   229,
     230,   231,   232,   233,   234,   235,   236,   240,   241,   245
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "LIBRARY", "PROC", "STR",
  "INT", "FLOAT", "CHR", "BOOL", "RULE", "PROC_ARR", "STR_ARR", "INT_ARR",
  "FLOAT_ARR", "CHR_ARR", "BOOL_ARR", "RULE_ARR", "IF", "ELSEIF", "ELSE",
  "LOOPIF", "ENTRY", "IMPORT", "EXPORT", "RETURN", "ID", "DECIMAL",
  "HEXADECIMAL", "BINARY", "REAL", "STRING", "EQ_OP", "LT_OP", "GT_OP",
  "LE_OP", "GE_OP", "NE_OP", "AND_OP", "OR_OP", "NOT_OP", "RANGE",
  "FUNC_STR", "FUNC_INT", "FUNC_FLOAT", "FUNC_CHR", "FUNC_BOOL", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "','", "'('", "')'", "'{'", "'}'", "'|'",
  "':'", "'['", "']'", "'='", "';'", "$accept", "type", "func_type",
  "type_list", "system_constant", "number", "logical_operator",
  "comparison_operator", "argument", "expression_list", "function_call",
  "code_block", "expression", "array", "condition", "loop_statement",
  "if_statement", "variable_declaration", "assignment_statement",
  "vardeclassign_statement", "function_declaration",
  "procedure_declaration", "procedure_call", "statement", "statement_list",
  "block", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,    43,    45,
      42,    47,   303,    44,    40,    41,   123,   125,   124,    58,
      91,    93,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      69,    69,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    80,    80,    80,    80,    81,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     3,     1,     3,     7,     7,    11,     9,    13,     4,
       4,     4,     4,     4,     3,     4,     4,     3,     7,     7,
       6,     7,     6,    10,     9,     6,     9,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    24,    25,    26,    27,     0,     0,     0,
      94,    93,     0,    91,    92,    95,    96,    89,    97,    99,
       0,     0,     0,    42,    28,    29,    30,    31,    43,     0,
       0,     0,    87,    41,    51,     0,    44,    45,     2,     3,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,    90,    98,     1,     0,     0,     0,
      59,    51,     0,     0,    74,    60,     0,     0,    88,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
      60,     0,    22,     0,    77,    60,     0,     0,    62,     0,
       0,    47,     0,    53,    52,    50,     0,    72,     0,    73,
      46,    54,    55,    56,    57,    58,     0,    69,     0,    70,
      71,     0,     0,    75,    76,     0,     0,    35,    36,    37,
      38,    39,    40,     0,     0,     0,    48,    49,    61,     0,
       0,     0,     0,    23,     0,     0,    63,     0,     0,     0,
      85,     0,    82,     0,    80,    60,     0,     0,    65,    64,
       0,     0,    81,    78,    79,     0,     0,     0,     0,    67,
       0,    86,    84,     0,     0,     0,    83,     0,    66,     0,
      68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    60,    93,     9,    33,    86,   133,    34,    35,
      36,    74,    37,    76,    99,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -64
static const yytype_int16 yypact[] =
{
      17,   -38,   -31,   -64,   -64,   -64,   -64,   116,   117,   -27,
     -64,   -64,    31,   -64,   -64,   -64,   -64,   -64,   -64,    17,
      29,    -1,     2,   -22,   -64,   -64,   -64,   -64,   -64,   269,
     153,    42,   -64,   -64,   -64,   -33,   -64,   283,   -64,   -64,
     -15,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,     1,
      22,   153,   303,    42,   -64,   -64,   -64,   159,   153,   122,
     -64,    40,   118,    -9,   -64,   155,   -13,   269,   -64,   -64,
     -64,   -64,   153,   153,   153,   153,   153,    72,    83,   109,
     171,     5,   -64,   -47,   -64,   175,    23,   153,   254,    78,
      96,   -64,    -6,   -64,   -64,   -64,     0,   -64,   153,   -64,
     -64,    25,    25,   100,   100,   283,    38,   -64,    47,   -64,
     -64,   303,    80,   -64,   -64,   231,   101,   -64,   -64,   -64,
     -64,   -64,   -64,   153,   113,   115,   -64,   -64,   283,   303,
     119,   303,    42,   -64,    42,   133,   283,   119,   119,    51,
     -64,    58,   -64,   191,   -64,   196,    39,   134,   176,   -64,
     136,   137,   -64,   -64,   -64,   119,   141,   119,    42,   180,
     150,   -64,   -64,   212,   158,   119,   -64,   168,   -64,   119,
     -64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,    -4,   -64,   -23,   -64,   -64,   -64,   -64,   -18,   160,
     -64,   -60,   -30,   -54,   -63,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -17,   170,   -64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      72,    75,    65,    94,    59,   100,   121,    91,   122,    96,
       1,    70,    71,     2,     3,     4,     5,     6,     7,     1,
      77,    21,     2,     3,     4,     5,     6,     7,    22,    66,
      78,    90,    69,    95,   126,    61,     1,    98,    98,     2,
       3,     4,     5,     6,     7,   108,    87,    77,   105,   136,
     109,     8,   111,   112,   113,   114,   115,   137,    67,   110,
       8,    68,    88,   108,    79,    80,    81,   125,   120,    23,
      24,    25,    26,    27,    28,    84,    85,     8,   138,    71,
     150,   108,   152,    89,   154,    62,   124,   158,   159,    65,
     156,    29,   139,    63,    64,   103,    30,   108,    73,   116,
     140,   141,   164,   146,   121,   169,   160,   171,   172,   142,
     117,   121,   153,   161,   155,   178,   149,   143,   151,   180,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   118,   134,   173,    79,
      80,    81,   144,    23,    24,    25,    26,    27,    28,    23,
      24,    25,    26,    27,    28,   135,   145,    79,    80,    81,
      54,    55,    56,    57,    58,    29,    82,    83,    84,    85,
      30,    29,   147,   104,   148,    73,    30,   101,    31,    32,
      23,    24,    25,    26,    27,    28,    23,    24,    25,    26,
      27,    28,   157,   165,    79,    80,    81,   166,   167,   168,
     170,   174,    29,    82,    83,    84,    85,    30,    29,   175,
      79,    80,    81,    97,    79,    80,    81,   177,   107,    82,
      83,    84,    85,    82,    83,    84,    85,   179,     0,   102,
      79,    80,    81,     0,   119,    79,    80,    81,   123,    82,
      83,    84,    85,   106,    82,    83,    84,    85,     0,     0,
       0,    79,    80,    81,   162,     0,     0,     0,     0,   163,
      82,    83,    84,    85,   127,   128,   129,   130,   131,   132,
      79,    80,    81,     0,     0,   176,     0,     0,     0,    82,
      83,    84,    85,     0,     0,     0,   104,   127,   128,   129,
     130,   131,   132,    79,    80,    81,    23,    24,    25,    26,
      27,    28,    82,    83,    84,    85,    38,    39,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    79,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      30,    31,    19,    63,     8,    68,    53,    61,    55,    63,
      19,    29,    30,    22,    23,    24,    25,    26,    27,    19,
      53,    59,    22,    23,    24,    25,    26,    27,    59,     0,
      63,    61,    54,    63,    97,    62,    19,    67,    68,    22,
      23,    24,    25,    26,    27,    58,    61,    53,    57,    55,
      63,    60,    82,    83,    84,    85,    86,    57,    59,    77,
      60,    59,    61,    58,    39,    40,    41,    97,    63,    27,
      28,    29,    30,    31,    32,    50,    51,    60,   108,    97,
     140,    58,   142,    61,   144,    54,    63,   147,   148,   106,
     144,    49,    54,    62,    63,    55,    54,    58,    56,    27,
      62,    54,    63,   133,    53,   165,    55,   167,   168,    62,
      27,    53,   142,    55,   144,   175,   139,   121,   141,   179,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    27,    59,   168,    39,
      40,    41,    62,    27,    28,    29,    30,    31,    32,    27,
      28,    29,    30,    31,    32,    59,    55,    39,    40,    41,
      43,    44,    45,    46,    47,    49,    48,    49,    50,    51,
      54,    49,    59,    55,    59,    56,    54,    55,    62,    63,
      27,    28,    29,    30,    31,    32,    27,    28,    29,    30,
      31,    32,    59,    59,    39,    40,    41,    21,    62,    62,
      59,    21,    49,    48,    49,    50,    51,    54,    49,    59,
      39,    40,    41,    54,    39,    40,    41,    59,    63,    48,
      49,    50,    51,    48,    49,    50,    51,    59,    -1,    69,
      39,    40,    41,    -1,    63,    39,    40,    41,    63,    48,
      49,    50,    51,    73,    48,    49,    50,    51,    -1,    -1,
      -1,    39,    40,    41,    63,    -1,    -1,    -1,    -1,    63,
      48,    49,    50,    51,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    63,    -1,    -1,    -1,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    27,    28,    29,    30,
      31,    32,    48,    49,    50,    51,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    22,    23,    24,    25,    26,    27,    60,    68,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    59,    59,    27,    28,    29,    30,    31,    32,    49,
      54,    62,    63,    69,    72,    73,    74,    76,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    43,    44,    45,    46,    47,    65,
      66,    62,    54,    62,    63,    87,     0,    59,    59,    54,
      72,    72,    76,    56,    75,    76,    77,    53,    63,    39,
      40,    41,    48,    49,    50,    51,    70,    61,    61,    61,
      76,    77,    65,    67,    75,    76,    77,    54,    76,    78,
      78,    55,    73,    55,    55,    57,    88,    63,    58,    63,
      72,    76,    76,    76,    76,    76,    27,    27,    27,    63,
      63,    53,    55,    63,    63,    76,    78,    33,    34,    35,
      36,    37,    38,    71,    59,    59,    55,    57,    76,    54,
      62,    54,    62,    65,    62,    55,    76,    59,    59,    67,
      75,    67,    75,    76,    75,    76,    77,    59,    75,    75,
      55,    55,    63,    63,    63,    59,    21,    62,    62,    75,
      59,    75,    75,    76,    21,    59,    63,    59,    75,    59,
      75
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 76 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 3:
#line 77 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 4:
#line 78 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 5:
#line 79 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 6:
#line 80 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 7:
#line 81 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 8:
#line 82 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 9:
#line 83 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 10:
#line 84 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 11:
#line 85 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 12:
#line 86 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 13:
#line 87 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 14:
#line 88 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 15:
#line 89 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 16:
#line 90 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 17:
#line 94 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 18:
#line 95 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 19:
#line 96 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 20:
#line 97 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 21:
#line 98 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 22:
#line 102 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 23:
#line 103 "iq_parser.y"
    { (yyval.str) = join(2,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 24:
#line 107 "iq_parser.y"
    {	(yyval.str) = (yyvsp[(1) - (1)].str);	}
    break;

  case 25:
#line 108 "iq_parser.y"
    {	(yyval.str) = (yyvsp[(1) - (1)].str);	}
    break;

  case 26:
#line 109 "iq_parser.y"
    {	(yyval.str) = (yyvsp[(1) - (1)].str);	}
    break;

  case 27:
#line 110 "iq_parser.y"
    {	(yyval.str) = (yyvsp[(1) - (1)].str);	}
    break;

  case 28:
#line 114 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 29:
#line 115 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 30:
#line 116 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 31:
#line 117 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 32:
#line 121 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 33:
#line 122 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 34:
#line 123 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 35:
#line 127 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 36:
#line 128 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 37:
#line 129 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 38:
#line 130 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 39:
#line 131 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 40:
#line 132 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 41:
#line 136 "iq_parser.y"
    { (yyval.node) = parsetree->addLeaf((yyvsp[(1) - (1)].str)); }
    break;

  case 42:
#line 137 "iq_parser.y"
    { (yyval.node) = parsetree->addLeaf((yyvsp[(1) - (1)].str)); }
    break;

  case 43:
#line 138 "iq_parser.y"
    { (yyval.node) = parsetree->addLeaf((yyvsp[(1) - (1)].str)); }
    break;

  case 44:
#line 139 "iq_parser.y"
    { (yyval.node) = parsetree->addLeaf((yyvsp[(1) - (1)].str)); }
    break;

  case 45:
#line 143 "iq_parser.y"
    { (yyval.node) = parsetree->addParamBlock((yyvsp[(1) - (1)].node)); }
    break;

  case 46:
#line 144 "iq_parser.y"
    { (yyval.node) = parsetree->addParamToParamBlock((yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node)); }
    break;

  case 47:
#line 148 "iq_parser.y"
    { (yyval.str) = (yyvsp[(1) - (3)].str); }
    break;

  case 48:
#line 149 "iq_parser.y"
    { (yyval.str) = join(2,(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].node)); }
    break;

  case 49:
#line 153 "iq_parser.y"
    {	(yyval.node) = (yyvsp[(2) - (3)].node);	}
    break;

  case 50:
#line 154 "iq_parser.y"
    {	(yyval.node) = NULL;	}
    break;

  case 51:
#line 158 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 52:
#line 159 "iq_parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 53:
#line 160 "iq_parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 54:
#line 161 "iq_parser.y"
    { (yyval.node) = parsetree->addExpr((yyvsp[(1) - (3)].node), "+", (yyvsp[(3) - (3)].node)); }
    break;

  case 55:
#line 162 "iq_parser.y"
    { (yyval.node) = parsetree->addExpr((yyvsp[(1) - (3)].node), "-", (yyvsp[(3) - (3)].node)); }
    break;

  case 56:
#line 163 "iq_parser.y"
    { (yyval.node) = parsetree->addExpr((yyvsp[(1) - (3)].node), "*", (yyvsp[(3) - (3)].node)); }
    break;

  case 57:
#line 164 "iq_parser.y"
    { (yyval.node) = parsetree->addExpr((yyvsp[(1) - (3)].node), "/", (yyvsp[(3) - (3)].node)); }
    break;

  case 58:
#line 165 "iq_parser.y"
    { (yyval.node) = parsetree->addLeaf(join(3,(yyvsp[(1) - (3)].node)->body.value,(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].node)->body.value)); }
    break;

  case 59:
#line 166 "iq_parser.y"
    { (yyval.node) = parsetree->addLeaf(join(2,"-",(yyvsp[(2) - (2)].node)->body.param_value)); }
    break;

  case 60:
#line 170 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 61:
#line 171 "iq_parser.y"
    { /*$$ = join(3,$1,"|",$3);*//*FIXME*/ }
    break;

  case 62:
#line 175 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 63:
#line 176 "iq_parser.y"
    { (yyval.node) = parsetree->addCond((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].node)); }
    break;

  case 64:
#line 180 "iq_parser.y"
    { (yyval.node) = parsetree->addLoop((yyvsp[(4) - (7)].node),(yyvsp[(7) - (7)].node)); }
    break;

  case 65:
#line 184 "iq_parser.y"
    { (yyval.node) = parsetree->addIf((yyvsp[(4) - (7)].node),(yyvsp[(7) - (7)].node)); }
    break;

  case 66:
#line 185 "iq_parser.y"
    { (yyval.node) = parsetree->addIf((yyvsp[(4) - (11)].node),(yyvsp[(7) - (11)].node)); /*FIXME*/}
    break;

  case 67:
#line 186 "iq_parser.y"
    { (yyval.node) = parsetree->addIf((yyvsp[(5) - (9)].node),(yyvsp[(9) - (9)].node)); }
    break;

  case 68:
#line 187 "iq_parser.y"
    { (yyval.node) = parsetree->addIf((yyvsp[(5) - (13)].node),(yyvsp[(9) - (13)].node)); /*FIXME*/}
    break;

  case 69:
#line 191 "iq_parser.y"
    { (yyval.node) = parsetree->addVariableDecl((yyvsp[(4) - (4)].str),(yyvsp[(2) - (4)].str)); }
    break;

  case 70:
#line 195 "iq_parser.y"
    { (yyval.node) = parsetree->addAssign2Expr((yyvsp[(1) - (4)].str),(char*)"system",(char*)"none",(yyvsp[(3) - (4)].node)); }
    break;

  case 71:
#line 196 "iq_parser.y"
    { (yyval.node) = parsetree->addAssign2Expr((yyvsp[(1) - (4)].str),(char*)"system",(char*)"none",(yyvsp[(3) - (4)].node)); }
    break;

  case 72:
#line 197 "iq_parser.y"
    { (yyval.node) = parsetree->addAssign2Expr((yyvsp[(1) - (4)].str),(char*)"?",(char*)"none",(yyvsp[(3) - (4)].node)); }
    break;

  case 73:
#line 198 "iq_parser.y"
    { (yyval.node) = parsetree->addAssign2Expr((yyvsp[(1) - (4)].str),(char*)"?",(char*)"none",(yyvsp[(3) - (4)].node)); }
    break;

  case 74:
#line 199 "iq_parser.y"
    { (yyval.node) = parsetree->addAssign2Block((yyvsp[(1) - (3)].str),(char*)"?",(char*)"none",(yyvsp[(3) - (3)].node)); }
    break;

  case 75:
#line 203 "iq_parser.y"
    { (yyval.node) = parsetree->addVardeclAssign2Expr((yyvsp[(1) - (4)].node),(char*)"none",(yyvsp[(3) - (4)].node)); }
    break;

  case 76:
#line 204 "iq_parser.y"
    { (yyval.node) = parsetree->addVardeclAssign2Expr((yyvsp[(1) - (4)].node),(char*)"none",(yyvsp[(3) - (4)].node)); }
    break;

  case 77:
#line 205 "iq_parser.y"
    { (yyval.node) = parsetree->addVardeclAssign2Block((yyvsp[(1) - (3)].node),(char*)"none",(yyvsp[(3) - (3)].node)); }
    break;

  case 78:
#line 206 "iq_parser.y"
    { (yyval.node) = parsetree->addVardeclAssign2Expr((yyvsp[(1) - (7)].node),(yyvsp[(3) - (7)].str),(yyvsp[(6) - (7)].node)); }
    break;

  case 79:
#line 207 "iq_parser.y"
    { (yyval.node) = parsetree->addVardeclAssign2Expr((yyvsp[(1) - (7)].node),(yyvsp[(3) - (7)].str),(yyvsp[(6) - (7)].node)); }
    break;

  case 80:
#line 208 "iq_parser.y"
    { (yyval.node) = parsetree->addVardeclAssign2Block((yyvsp[(1) - (6)].node),(yyvsp[(3) - (6)].str),(yyvsp[(6) - (6)].node)); }
    break;

  case 81:
#line 212 "iq_parser.y"
    { (yyval.node) = parsetree->addFunction2Expr((yyvsp[(4) - (7)].str),(yyvsp[(2) - (7)].str),(char*)"none",(yyvsp[(6) - (7)].node)); }
    break;

  case 82:
#line 213 "iq_parser.y"
    { (yyval.node) = parsetree->addFunction2Block((yyvsp[(4) - (6)].str),(yyvsp[(2) - (6)].str),(char*)"none",(yyvsp[(6) - (6)].node)); }
    break;

  case 83:
#line 214 "iq_parser.y"
    { (yyval.node) = parsetree->addFunction2Expr((yyvsp[(4) - (10)].str),(yyvsp[(2) - (10)].str),(yyvsp[(6) - (10)].str),(yyvsp[(9) - (10)].node)); }
    break;

  case 84:
#line 215 "iq_parser.y"
    { (yyval.node) = parsetree->addFunction2Block((yyvsp[(4) - (9)].str),(yyvsp[(2) - (9)].str),(yyvsp[(6) - (9)].str),(yyvsp[(9) - (9)].node)); }
    break;

  case 85:
#line 219 "iq_parser.y"
    { (yyval.node) = parsetree->addProcedure2Block((yyvsp[(4) - (6)].str),(char*)"none",(yyvsp[(6) - (6)].node)); }
    break;

  case 86:
#line 220 "iq_parser.y"
    { (yyval.node) = parsetree->addProcedure2Block((yyvsp[(4) - (9)].str),(yyvsp[(6) - (9)].str),(yyvsp[(9) - (9)].node)); }
    break;

  case 87:
#line 224 "iq_parser.y"
    { (yyval.node) = parsetree->addProc((yyvsp[(1) - (2)].str),NULL); }
    break;

  case 88:
#line 225 "iq_parser.y"
    { (yyval.node) = parsetree->addProc((yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].node)); }
    break;

  case 89:
#line 229 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 90:
#line 230 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 91:
#line 231 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 92:
#line 232 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 93:
#line 233 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 94:
#line 234 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:
#line 235 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 96:
#line 236 "iq_parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 97:
#line 240 "iq_parser.y"
    { (yyval.node) = parsetree->addBlock((yyvsp[(1) - (1)].node)); }
    break;

  case 98:
#line 241 "iq_parser.y"
    { (yyval.node) = parsetree->addStatementToBlock((yyvsp[(2) - (2)].node),(yyvsp[(1) - (2)].node));  }
    break;

  case 99:
#line 245 "iq_parser.y"
    { parsetree->setRoot((yyvsp[(1) - (1)].node)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2140 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 248 "iq_parser.y"



