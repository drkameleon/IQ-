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

IQ_CODEGEN.CPP

*/

#include "iq_header.h"

iq_codegen::iq_codegen(iq_xmltree* xtree)
{	
	xmlTree = xtree;
	parseTree = xmlTree->getParseTree();
	as = new iq_asm();

	symTable = new iq_symtable();

	noIfBlocks   = 1;
	noLoopBlocks = 1;
}

void iq_codegen::transform(void)
{
	initASM();
	finalizeASM();

	convertNode ( parseTree->getRoot(), NON ); 
	
	writeASMtoFile();

	symTable->printAll();
}

void iq_codegen::convertNode (pTree *t, int n) 
{
	#define step 1
	string k, l, r;	
	if (t==NULL) return;

	if (t)
	{
		switch (t->nodeType)
		{
			case proccall_node:
				convertNode ( t->body.procedure.params, NON );

				k = ((string) t->body.procedure.id);
				if ( (k != "print_int") && (k != "print_nl") )
					k = "proc_" + k;

				seg_TEXT << as->call ( k );
				break;
			case variabledecl_node:
				symTable->addVariable ( t->body.variabledecl.id, t->body.variabledecl.type );
				seg_BSS << as->resd ( t->body.variabledecl.id, "1" );
				break;
			case expression_node:
				convertNode ( t->body.expression.left, 0 );	
				convertNode ( t->body.expression.right, 1 );
						
				seg_TEXT << as->pop(EBX);
				seg_TEXT << as->pop(EAX);

				if (t->body.expression.oper==(string)"+")
					seg_TEXT << as->add(EAX,EBX);
				else if (t->body.expression.oper==(string)"-")
					seg_TEXT << as->sub(EAX,EBX);
				else if (t->body.expression.oper==(string)"*")
					seg_TEXT << as->mul(EBX);
				else if (t->body.expression.oper==(string)"/")
				{
					seg_TEXT << "xor edx, edx" << endl;
					seg_TEXT << as->div(EBX);
				}

				seg_TEXT << as->push(EAX);
				break;
			case functiondecl_node:
				symTable->addFunction ( t->body.functiondecl.id, t->body.functiondecl.type );
				seg_TEXT << "\tjmp after_end" << t->body.functiondecl.type << "_" << t->body.functiondecl.id << endl;
				#ifdef __IQ_DEBUG
				INSERT_COMMENT_PRE_FUNC ( t->body.functiondecl.id, t->body.functiondecl.params );
				#endif
				seg_TEXT << "\t" << t->body.functiondecl.type << "_" << t->body.functiondecl.id << ":" << endl;
				seg_TEXT << as->push(EBP) << as->mov(EBP,ESP);
				if (t->body.assignment.contentType == expression_content)	
					convertNode ( t->body.functiondecl.content.expression, NON );
				else
					convertNode ( t->body.functiondecl.content.block, NON );
				seg_TEXT << "\tend" << t->body.functiondecl.type << "_" << t->body.functiondecl.id << ":" << endl;
				seg_TEXT << as->pop(EBP);
				seg_TEXT << as->ret();
				#ifdef __IQ_DEBUG
				INSERT_COMMENT_POST_FUNC ( t->body.functiondecl.id );
				#endif
				seg_TEXT << "\tafter_end" << t->body.functiondecl.type << "_" << t->body.functiondecl.id << ":" << endl;
				break;
			case proceduredecl_node:
				symTable->addProcedure ( t->body.proceduredecl.id );
				seg_TEXT << "\tjmp after_end_proc_" << t->body.proceduredecl.id << endl;
				
				#ifdef __IQ_DEBUG
				INSERT_COMMENT_PRE_PROC ( t->body.proceduredecl.id, t->body.proceduredecl.params );
				#endif
			
				seg_TEXT << "\tproc_" << t->body.proceduredecl.id << ":" << endl;
				seg_TEXT << as->push(EBP) << as->mov(EBP,ESP);
				convertNode ( t->body.proceduredecl.content.block, NON );
				seg_TEXT << "\tend_proc_" << t->body.proceduredecl.id << ":" << endl;
				seg_TEXT << as->pop(EBP);
				seg_TEXT << as->ret();

				#ifdef __IQ_DEBUG
				INSERT_COMMENT_POST_PROC ( t->body.proceduredecl.id );
				#endif
				
				seg_TEXT << "\tafter_end_proc_" << t->body.proceduredecl.id << ":" << endl;
				break;
			case assignment_node:
				if (t->body.assignment.contentType == expression_content)	
				{
					convertNode ( t->body.assignment.content.expression, NON );
					seg_TEXT << as->pop(EAX);
				}
				else
					convertNode ( t->body.assignment.content.block, NON );

				k = (string)t->body.assignment.id;
				if (k=="$return")
				{	/*seg_TEXT << as->push(EAX);*/
				}
				else
				{
					k = "dword[" + k + "]";
					seg_TEXT << as->mov(k, EAX);
				}
				break;
			case vardeclassignment_node:
				convertNode ( t->body.vardeclassignment.vardecl, NON );
				if (t->body.vardeclassignment.contentType == expression_content)	
				{
					convertNode ( t->body.vardeclassignment.content.expression, NON );
					seg_TEXT << as->pop(EAX);
				}
				else
					convertNode ( t->body.vardeclassignment.content.block, NON );

				k = "dword[" + (string)t->body.vardeclassignment.vardecl->body.variabledecl.id + "]";
				seg_TEXT << as->mov(k, EAX);
				break;
			case block_node:
				for (int p=0; p<t->body.BLOCK.nos; p++)
					convertNode ( t->body.BLOCK.stats[p], p );

				break;
			case leaf_node:
				k = (string) t->body.value;

				if ( isInt(t->body.value) )
					k = k;
				else if (symTable->existsVariable(t->body.value))	
				{
					k = "dword[" + k + "]";
					cout << "VARIABLE call :: " << k << endl;
				}
				else if (symTable->existsFunction(t->body.value))
				{
					k = symTable->getFunction(t->body.value).type + "_" + k;
					seg_TEXT << as->call ( k );
					seg_TEXT << as->push ( EAX );
					cout << "FUNCTION call :: " << k << endl;
					break;
				}

				if ((n==0)||(n==1))
				{
					seg_TEXT << as->push(k);
				}
				else
				{
					seg_TEXT << as->mov(EAX, k);
					seg_TEXT << as->push(EAX);
				}
				break;
			case condition_node:
				convertNode ( t->body.stcondition.expression1, NON );
				convertNode ( t->body.stcondition.expression2, NON );
				seg_TEXT << as->pop(EBX);
				seg_TEXT << as->pop(EAX);
				seg_TEXT << as->cmp(EAX,EBX);				
				break;
			case ifcase_node:
				convertNode ( t->body.ifcase.condition, NON );
				k = t->body.ifcase.condition->body.stcondition.oper;

				l = "\tif_block_end_" + itos(noIfBlocks);
				r = "\tif_block_" + itos(noIfBlocks);
				r = r + ":";
								
				if ( k == "==")
					seg_TEXT << as->jne(l);
				else if ( k == "/=")
					seg_TEXT << as->je(l);
				else if ( k == ">>")
					seg_TEXT << as->jle(l);
				else if ( k == "<<")
					seg_TEXT << as->jge(l);
				else if ( k == ">=")
					seg_TEXT << as->jl(l);
				else if ( k == "<=")
					seg_TEXT << as->jg(l);
	
				seg_TEXT << r << endl;
				convertNode ( t->body.ifcase.block, NON );
				seg_TEXT << l << ":" << endl;
				noIfBlocks++;
				break;
			case loopcase_node:
				l = "\tloop_block_condition_" + noLoopBlocks;
				seg_TEXT << l << ":" << endl;
				convertNode ( t->body.loopcase.condition, NON );
				k = t->body.loopcase.condition->body.stcondition.oper;

				l = "\tloop_block_end_" + itos(noLoopBlocks);
				r = "\tloop_block_" + itos(noLoopBlocks);
				r = r + ":";
				
				
				if ( k == "==")
					seg_TEXT << as->jne(l);
				else if ( k == "/=")
					seg_TEXT << as->je(l);
				else if ( k == ">>")
					seg_TEXT << as->jle(l);
				else if ( k == "<<")
					seg_TEXT << as->jge(l);
				else if ( k == ">=")
					seg_TEXT << as->jl(l);
				else if ( k == "<=")
					seg_TEXT << as->jg(l);
	
				seg_TEXT << r << endl;
				convertNode ( t->body.loopcase.block, NON );
				r = "loop_block_condition_" + itos(noLoopBlocks);
				seg_TEXT << as->jmp (r);
				seg_TEXT << l << ":" << endl;
				noLoopBlocks++;
				break;
			case statement_node:
				convertNode ( t->body.statement, NON );
				break;
			case param_block_node:
				for (int p=0; p<t->body.PARAM_BLOCK.nop; p++)
					convertNode ( t->body.PARAM_BLOCK.params[p], p );

				break;
			case param_node:
				k = "[" + (string) t->body.param_value->body.value + "]";
				seg_TEXT << as->mov(EAX, k);
				break;
			default:
				break;
		}
	}	
}

void iq_codegen::initASM(void)
{	
	seg_DATA << ASM_INCLUDES << endl;
	seg_DATA << ASM_PRE_DATA << endl;

	seg_BSS << ASM_PRE_BSS << endl;

	seg_TEXT << ASM_PRE_TEXT << endl;
}

void iq_codegen::finalizeASM(void)
{
	seg_TEXT << ASM_POST_TEXT << endl;
}

void iq_codegen::writeASMtoFile(void)
{
	ASM.open("output.asm");

	ASM << seg_DATA.str() << seg_BSS.str() << seg_TEXT.str() << endl;

	ASM.close();
}
