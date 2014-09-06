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

IQ_PARSETREE.CPP

*/

#include "iq_header.h"

iq_parsetree::iq_parsetree(string filename) 
{
	yyin = fopen ( filename.c_str(), "r" );	
}

void iq_parsetree::create(void)
{
	yyparse();
}

//====================================================
// Tree Manipulation ( a.k.a. Holy Shit )
//====================================================

pTree* iq_parsetree::addLeaf (char* str) 
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = leaf_node;

	result->body.value = str;

	return result;	
}

pTree* iq_parsetree::addExpr (pTree* left, char* oper, pTree* right) 
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = expression_node;

	result->body.expression.left = left;
	result->body.expression.oper = oper;
	result->body.expression.right = right;

	return result;	
}

pTree* iq_parsetree::addProc (char* id, pTree* params)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = proccall_node;

	result->body.procedure.id = id;
	result->body.procedure.params = params;

	return result;
}

pTree* iq_parsetree::addVariableDecl (char* id, char* type)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = variabledecl_node;

	result->body.variabledecl.id = id;
	result->body.variabledecl.type = type;

	return result;
}

pTree* iq_parsetree::addAssign2Expr (char* id, char* type, char* params, pTree* expression)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = assignment_node;

	result->body.assignment.id = id;
	result->body.assignment.type = type;
	result->body.assignment.params = params;
	result->body.assignment.contentType = expression_content;
	result->body.assignment.content.expression = expression;

	return result;
}

pTree* iq_parsetree::addAssign2Block(char* id, char* type, char* params, pTree* block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = assignment_node;

	result->body.assignment.id = id;
	result->body.assignment.type = type;
	result->body.assignment.params = params;
	result->body.assignment.contentType = block_content;
	result->body.assignment.content.block = block;

	return result;
}

pTree* iq_parsetree::addVardeclAssign2Expr (pTree* vardecl, char* params, pTree* expression)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = vardeclassignment_node;

	result->body.vardeclassignment.vardecl = vardecl;
	result->body.vardeclassignment.params = params;
	result->body.vardeclassignment.contentType = expression_content;
	result->body.vardeclassignment.content.expression = expression;

	return result;
}

pTree* iq_parsetree::addVardeclAssign2Block(pTree* vardecl, char* params, pTree* block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = vardeclassignment_node;

	result->body.vardeclassignment.vardecl = vardecl;
	result->body.vardeclassignment.params = params;
	result->body.vardeclassignment.contentType = block_content;
	result->body.vardeclassignment.content.block = block;

	return result;
}

pTree* iq_parsetree::addFunction2Expr (char* id, char* type, char* params, pTree* expression)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = functiondecl_node;

	result->body.functiondecl.id = id;
	result->body.functiondecl.type = type;
	result->body.functiondecl.params = params;
	result->body.functiondecl.contentType = expression_content;
	result->body.functiondecl.content.expression = expression;

	return result;
}

pTree* iq_parsetree::addFunction2Block(char* id, char* type, char* params, pTree* block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = functiondecl_node;

	result->body.functiondecl.id = id;
	result->body.functiondecl.type = type;
	result->body.functiondecl.params = params;
	result->body.functiondecl.contentType = block_content;
	result->body.functiondecl.content.block = block;

	return result;
}

pTree* iq_parsetree::addProcedure2Block(char* id, char* params, pTree* block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = proceduredecl_node;

	result->body.proceduredecl.id = id;
	result->body.proceduredecl.params = params;
	result->body.proceduredecl.contentType = block_content;
	result->body.proceduredecl.content.block = block;

	return result;
}

pTree* iq_parsetree::addIf (pTree* condition, pTree* block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = ifcase_node;

	result->body.ifcase.condition = condition;
	result->body.ifcase.block = block;

	return result;
}

pTree* iq_parsetree::addLoop (pTree* condition, pTree* block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = loopcase_node;

	result->body.loopcase.condition = condition;
	result->body.loopcase.block = block;

	return result;
}

pTree* iq_parsetree::addCond (pTree* expression1, char* oper, pTree* expression2)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = condition_node;

	result->body.stcondition.expression1 = expression1;
	result->body.stcondition.oper = oper;
	result->body.stcondition.expression2 = expression2;

	return result;
}

pTree* iq_parsetree::addStatementToBlock (pTree* statement, pTree* block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = statement_node;

	result->body.statement = statement;

	int indx = block->body.BLOCK.nos;
	block->body.BLOCK.stats[indx] = result;
	
	block->body.BLOCK.nos++;	

	return block;

}

pTree* iq_parsetree::addBlock (pTree* statement)
{
	pTree *rez = (pTree*) malloc (sizeof(pTree));
	rez->nodeType = statement_node;

	rez->body.statement = statement;

	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = block_node;

	result->body.BLOCK.stats = new pTree* [1000];
	result->body.BLOCK.stats[0] = rez;
	result->body.BLOCK.nos = 1;

	return result;
}

pTree* iq_parsetree::addParamToParamBlock (pTree* param, pTree* param_block)
{
	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = param_node;

	result->body.param_value = param;

	int indx = param_block->body.PARAM_BLOCK.nop;
	param_block->body.PARAM_BLOCK.params[indx] = result;
	
	param_block->body.PARAM_BLOCK.nop++;	

	return param_block;

}

pTree* iq_parsetree::addParamBlock (pTree* param)
{
	pTree *rez = (pTree*) malloc (sizeof(pTree));
	rez->nodeType = param_node;

	rez->body.param_value = param;

	pTree *result = (pTree*) malloc (sizeof(pTree));
	result->nodeType = param_block_node;

	result->body.PARAM_BLOCK.params = new pTree* [1000];
	result->body.PARAM_BLOCK.params[0] = rez;
	result->body.PARAM_BLOCK.nop = 1;

	return result;
}

void iq_parsetree::setRoot (pTree* root)
{
	TreeRoot = root;
}

pTree* iq_parsetree::getRoot (void)
{
	return TreeRoot;
}

