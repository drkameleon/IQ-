/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 43 "iq_parser.y"
{
	char* str;
	struct pTree* node;
}
/* Line 1529 of yacc.c.  */
#line 150 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

