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

IQ_XMLTREE.CPP

*/

#include "iq_header.h"

iq_xmltree::iq_xmltree(iq_parsetree* ptree)
{
	parseTree = ptree;
}

void iq_xmltree::create(void)
{
	xml = new iq_xml ( XML_OUT );

	xml->openWrite();
	xml->openSection ( XML_ROOT );

	encodeNode ( parseTree->getRoot(), NON );

	xml->closeSection ( XML_ROOT );
	xml->closeWrite();
}

void iq_xmltree::encodeNode (pTree *t, int n) 
{
	#define step 1
	
	if (t==NULL) return;

	if (t)
	{
		switch (t->nodeType)
		{
			case proccall_node:
				xml->openSection ( XML_PROCEDURE );
					xml->addElement ( XML_ID, t->body.procedure.id );
					encodeNode ( t->body.procedure.params, NON );
				xml->closeSection ( XML_PROCEDURE );
				break;
			case variabledecl_node:
				xml->openSection ( XML_VARIABLE );
					xml->addElement ( XML_ID, t->body.variabledecl.id );
					xml->addElement ( XML_TYPE, t->body.variabledecl.type );
				xml->closeSection ( XML_VARIABLE );
				break;
			case expression_node:
				xml->openSectionWithStrParam ( XML_OPERATOR, XML_PARAM_PRM, t->body.expression.oper );
					xml->openSection ( XML_LEFT );
						encodeNode ( t->body.expression.left, NON );	
					xml->closeSection ( XML_LEFT );
					xml->openSection ( XML_RIGHT );
						encodeNode ( t->body.expression.right, NON );
					xml->closeSection ( XML_RIGHT );
				xml->closeSection ( XML_OPERATOR );
				break;
			case assignment_node:
				xml->openSection ( XML_ASSIGNMENT );
					xml->addElement ( XML_ID, t->body.assignment.id );
					xml->addElement ( XML_TYPE, t->body.assignment.type );
					xml->addElement ( XML_ARGS, t->body.assignment.params );
					xml->openSection ( XML_CONTENT );
						if (t->body.assignment.contentType == expression_content)	
						{
							xml->openSection ( XML_EXPRESSION );
								encodeNode ( t->body.assignment.content.expression, NON );
							xml->closeSection ( XML_EXPRESSION );
						}
						else
							encodeNode ( t->body.assignment.content.block, NON );
					xml->closeSection ( XML_CONTENT );
				xml->closeSection ( XML_ASSIGNMENT );
				break;
			case vardeclassignment_node:
				xml->openSection ( XML_ASSIGNMENT );
					encodeNode ( t->body.vardeclassignment.vardecl, NON );
					xml->addElement ( XML_ARGS, t->body.vardeclassignment.params );
					xml->openSection ( XML_CONTENT );
						if (t->body.vardeclassignment.contentType == expression_content)	
						{
							xml->openSection ( XML_EXPRESSION );
								encodeNode ( t->body.vardeclassignment.content.expression, NON );
							xml->closeSection ( XML_EXPRESSION );
						}
						else
							encodeNode ( t->body.vardeclassignment.content.block, NON );
					xml->closeSection ( XML_CONTENT );
				xml->closeSection ( XML_ASSIGNMENT );
				break;
			case functiondecl_node:
				xml->openSection ( XML_FUNCTIONDECL );
					xml->addElement ( XML_ID, t->body.functiondecl.id );
					xml->addElement ( XML_TYPE, t->body.functiondecl.type );
					xml->addElement ( XML_ARGS, t->body.functiondecl.params );
					xml->openSection ( XML_CONTENT );
						if (t->body.functiondecl.contentType == expression_content)	
						{
							xml->openSection ( XML_EXPRESSION );
								encodeNode ( t->body.functiondecl.content.expression, NON );
							xml->closeSection ( XML_EXPRESSION );
						}
						else
							encodeNode ( t->body.functiondecl.content.block, NON );
					xml->closeSection ( XML_CONTENT );
				xml->closeSection ( XML_FUNCTIONDECL );
				break;
			case proceduredecl_node:
				xml->openSection ( XML_PROCEDUREDECL );
					xml->addElement ( XML_ID, t->body.proceduredecl.id );
					xml->addElement ( XML_ARGS, t->body.proceduredecl.params );
					xml->openSection ( XML_CONTENT );
						encodeNode ( t->body.proceduredecl.content.block, NON );
					xml->closeSection ( XML_CONTENT );
				xml->closeSection ( XML_PROCEDUREDECL );
				break;
			case block_node:
				xml->openSection ( XML_BLOCK );
					for (int p=0; p<t->body.BLOCK.nos; p++)
						encodeNode ( t->body.BLOCK.stats[p], p );

				xml->closeSection ( XML_BLOCK );
				break;
			case leaf_node:
				xml->addValue ( t->body.value );
				break;
			case condition_node:
				xml->openSection ( XML_CONDITION );
					xml->openSectionWithStrParam ( XML_OPERATOR, XML_PARAM_PRM, t->body.stcondition.oper );
						xml->openSectionWithParam ( XML_EXPRESSION, XML_INDEX_PRM, 0);
							encodeNode ( t->body.stcondition.expression1, NON );
						xml->closeSection ( XML_EXPRESSION );
						xml->openSectionWithParam ( XML_EXPRESSION, XML_INDEX_PRM, 1);
							encodeNode ( t->body.stcondition.expression2, NON );
						xml->closeSection ( XML_EXPRESSION );
					xml->closeSection ( XML_OPERATOR );
				xml->closeSection ( XML_CONDITION );
				break;
			case ifcase_node:
				xml->openSection ( XML_IF );
					encodeNode ( t->body.ifcase.condition, NON );
					xml->openSection ( XML_BLOCK );
						encodeNode ( t->body.ifcase.block, NON );
					xml->closeSection ( XML_BLOCK );
				xml->closeSection ( XML_IF );
				break;
			case loopcase_node:
				xml->openSection ( XML_LOOP );
					encodeNode ( t->body.loopcase.condition, NON );
					xml->openSection ( XML_BLOCK );
						encodeNode ( t->body.loopcase.block, NON );
					xml->closeSection ( XML_BLOCK );
				xml->closeSection ( XML_LOOP );
				break;
			case statement_node:
				xml->openSectionWithParam ( XML_STATEMENT, XML_INDEX_PRM, n );
					encodeNode ( t->body.statement, NON );
				xml->closeSection ( XML_STATEMENT );
				break;
			case param_block_node:
				xml->openSection ( XML_PARAM_BLOCK );
					for (int p=0; p<t->body.PARAM_BLOCK.nop; p++)
						encodeNode ( t->body.PARAM_BLOCK.params[p], p );

				xml->closeSection ( XML_PARAM_BLOCK );
				break;
			case param_node:
				xml->openSectionWithParam ( XML_PARAM, XML_INDEX_PRM, n );
					xml->openSection ( XML_EXPRESSION );
						encodeNode ( t->body.param_value, NON );
					xml->closeSection ( XML_EXPRESSION );
				xml->closeSection ( XML_PARAM );
				break;
			default:
				break;
		}
	}	
}
