%{
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
%}

%union 
{
	char* str;
	struct pTree* node;
}

%token <str> PROGRAM LIBRARY
%token <str> PROC STR INT FLOAT CHR BOOL RULE
%token <str> PROC_ARR STR_ARR INT_ARR FLOAT_ARR CHR_ARR BOOL_ARR RULE_ARR
%token <str> IF ELSEIF ELSE LOOPIF
%token <str> ENTRY IMPORT EXPORT RETURN
%token <str> ID DECIMAL HEXADECIMAL BINARY REAL STRING
%token <str> EQ_OP LT_OP GT_OP LE_OP GE_OP NE_OP
%token <str> AND_OP OR_OP NOT_OP
%token <str> RANGE
%token <str> FUNC_STR FUNC_INT FUNC_FLOAT FUNC_CHR FUNC_BOOL	

%type <str> number logical_operator comparison_operator
%type <str> type func_type type_list system_constant function_call

%type <node> statement statement_list procedure_call assignment_statement if_statement loop_statement
%type <node> code_block condition expression array block argument expression_list 
%type <node> variable_declaration function_declaration procedure_declaration vardeclassign_statement


%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%start block

%%

type
	:	PROGRAM		{ $$ = $1; }										
	|	LIBRARY		{ $$ = $1; }				
	|	STR		{ $$ = $1; }			
	|	INT		{ $$ = $1; }			
	|	FLOAT		{ $$ = $1; }			
	|	CHR		{ $$ = $1; }			
	|	BOOL		{ $$ = $1; }			
	|	RULE		{ $$ = $1; }			
	|	PROC_ARR 	{ $$ = $1; }			
	|	STR_ARR		{ $$ = $1; }			
	|	INT_ARR		{ $$ = $1; }			
	|	FLOAT_ARR	{ $$ = $1; }			
	|	CHR_ARR		{ $$ = $1; }			
	|	BOOL_ARR	{ $$ = $1; }			
	|	RULE_ARR	{ $$ = $1; }			
	;

func_type
	:	FUNC_STR	{ $$ = $1; }			
	|	FUNC_INT	{ $$ = $1; }			
	|	FUNC_FLOAT	{ $$ = $1; }			
	|	FUNC_CHR	{ $$ = $1; }			
	|	FUNC_BOOL	{ $$ = $1; }		
	;	

type_list
	:	type				{ $$ = $1; }						
	|	type_list ',' type		{ $$ = join(2,$1,$3); }
	;

system_constant
	:	ENTRY	{	$$ = $1;	}
	|	IMPORT	{	$$ = $1;	}
	|	EXPORT	{	$$ = $1;	}
	|	RETURN	{	$$ = $1;	}
	;

number
	:	DECIMAL		{ $$ = $1; }				
	|	HEXADECIMAL	{ $$ = $1; }			
	|	BINARY		{ $$ = $1; }			
	|	REAL		{ $$ = $1; }			
	;

logical_operator
	:	AND_OP		{ $$ = $1; }
	|	OR_OP		{ $$ = $1; }
	|	NOT_OP		{ $$ = $1; }
	;

comparison_operator
	:	EQ_OP		{ $$ = $1; }
	|	LT_OP		{ $$ = $1; }
	|	GT_OP		{ $$ = $1; }
	|	LE_OP		{ $$ = $1; }
	|	GE_OP		{ $$ = $1; }
	|	NE_OP		{ $$ = $1; }
	;	

argument
	:	number		{ $$ = parsetree->addLeaf($1); }
	|	ID		{ $$ = parsetree->addLeaf($1); }				
	|	STRING		{ $$ = parsetree->addLeaf($1); }
	|	function_call	{ $$ = parsetree->addLeaf($1); }	
	;

expression_list
	:	expression			{ $$ = parsetree->addParamBlock($1); }
	|	expression_list ',' argument	{ $$ = parsetree->addParamToParamBlock($3,$1); }
	;

function_call
	:	ID '(' ')'			  { $$ = $1; }
	|	ID '(' expression_list ')'        { $$ = join(2,$1,$3); }
	;

code_block
	:	'{' statement_list '}'		{	$$ = $2;	}
	|	'{' '}'				{	$$ = NULL;	}
	;

expression
	:	argument					{ $$ = $1; }
	|	'(' expression ')'				{ $$ = $2; }
	|	'(' argument ')'				{ $$ = $2; }
	|	expression '+' expression			{ $$ = parsetree->addExpr($1, "+", $3); }
	|	expression '-' expression			{ $$ = parsetree->addExpr($1, "-", $3); }
	|	expression '*' expression			{ $$ = parsetree->addExpr($1, "*", $3); }
	|	expression '/' expression			{ $$ = parsetree->addExpr($1, "/", $3); }
	|	expression logical_operator expression		{ $$ = parsetree->addLeaf(join(3,$1->body.value,$2,$3->body.value)); }
	|	'-' argument %prec UMINUS			{ $$ = parsetree->addLeaf(join(2,"-",$2->body.param_value)); }
	;

array
	:	expression			{ $$ = $1; }
	|	array '|' expression		{ /*$$ = join(3,$1,"|",$3);*//*FIXME*/ }
	;

condition
	:	expression					{ $$ = $1; }
	|	expression comparison_operator expression       { $$ = parsetree->addCond($1,$2,$3); }
	;

loop_statement
	:	LOOPIF ':' ':' condition ':' ':' code_block	{ $$ = parsetree->addLoop($4,$7); } 
	;

if_statement
	:	IF ':' ':' condition ':' ':' code_block				        { $$ = parsetree->addIf($4,$7); }
	|	IF ':' ':' condition ':' ':' code_block ELSE ':' ':' code_block		{ $$ = parsetree->addIf($4,$7); /*FIXME*/}
	|	IF ':' ':' '(' condition ')' ':' ':' code_block				        { $$ = parsetree->addIf($5,$9); }
	|	IF ':' ':' '(' condition ')' ':' ':' code_block ELSE ':' ':' code_block		{ $$ = parsetree->addIf($5,$9); /*FIXME*/}
	;

variable_declaration
	:	'[' type ']' ID				{ $$ = parsetree->addVariableDecl($4,$2); }
	;

assignment_statement
	:	system_constant '=' expression ';'	{ $$ = parsetree->addAssign2Expr($1,(char*)"system",(char*)"none",$3); }
	|	system_constant '=' array ';'		{ $$ = parsetree->addAssign2Expr($1,(char*)"system",(char*)"none",$3); }
	|	ID '=' expression ';'			{ $$ = parsetree->addAssign2Expr($1,(char*)"?",(char*)"none",$3); }
	|	ID '=' array ';'			{ $$ = parsetree->addAssign2Expr($1,(char*)"?",(char*)"none",$3); }
	|	ID '=' code_block			{ $$ = parsetree->addAssign2Block($1,(char*)"?",(char*)"none",$3); }
	;

vardeclassign_statement
	:	variable_declaration '=' expression ';'	{ $$ = parsetree->addVardeclAssign2Expr($1,(char*)"none",$3); }	
	|	variable_declaration '=' array ';'	{ $$ = parsetree->addVardeclAssign2Expr($1,(char*)"none",$3); }	
	|	variable_declaration '=' code_block	{ $$ = parsetree->addVardeclAssign2Block($1,(char*)"none",$3); }
	|	variable_declaration '(' type_list ')' '=' expression ';'	{ $$ = parsetree->addVardeclAssign2Expr($1,$3,$6); }		
	|	variable_declaration '(' type_list ')' '=' array ';'		{ $$ = parsetree->addVardeclAssign2Expr($1,$3,$6); }	
	|	variable_declaration '(' type_list ')' '=' code_block		{ $$ = parsetree->addVardeclAssign2Block($1,$3,$6); }	
	;

function_declaration
	:	'[' func_type ']' ID '=' expression ';'				{ $$ = parsetree->addFunction2Expr($4,$2,(char*)"none",$6); }		
	|	'[' func_type ']' ID'=' code_block				{ $$ = parsetree->addFunction2Block($4,$2,(char*)"none",$6); }	
	|	'[' func_type ']' ID '(' type_list ')' '=' expression ';'	{ $$ = parsetree->addFunction2Expr($4,$2,$6,$9); }	
	|	'[' func_type ']' ID '(' type_list ')' '=' code_block		{ $$ = parsetree->addFunction2Block($4,$2,$6,$9); }	
	;

procedure_declaration
	:	'[' PROC ']' ID '=' code_block					{ $$ = parsetree->addProcedure2Block($4,(char*)"none",$6); }	
	|	'[' PROC ']' ID '(' type_list ')' '=' code_block		{ $$ = parsetree->addProcedure2Block($4,$6,$9); }		
	;

procedure_call
	:	ID  ';'				{ $$ = parsetree->addProc($1,NULL); }
	|	ID expression_list ';'		{ $$ = parsetree->addProc($1,$2); }
	;

statement
	:	procedure_call				{ $$ = $1; }
	|	variable_declaration ';'		{ $$ = $1; }
	|	assignment_statement			{ $$ = $1; }
	|	vardeclassign_statement			{ $$ = $1; }
	|	if_statement				{ $$ = $1; }
	|	loop_statement				{ $$ = $1; }
	|	function_declaration			{ $$ = $1; }
	|	procedure_declaration			{ $$ = $1; }
	;

statement_list
	:	statement				{ $$ = parsetree->addBlock($1); }
	|	statement_list statement		{ $$ = parsetree->addStatementToBlock($2,$1);  }
	;

block
	:	statement_list				{ parsetree->setRoot($1); }
	;

%%

