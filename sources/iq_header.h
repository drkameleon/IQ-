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

IQ_HEADER.H

*/

#ifndef __IQ_HEADER_H

#define __IQ_HEADER_H

#define __IQ_DEBUG

//=======================================
// Includes
//=======================================


#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <list>
#include <vector>
#include <stack>
#include <cstdarg>

using namespace std;

//=======================================
// Definitions
//=======================================

// XML-related
//---------------------

#define XML_STATEMENT		"statement"
#define XML_PROCEDURE		"procedure"
#define XML_VARIABLE		"variable"
#define XML_IF			"if"
#define XML_LOOP		"loop"
#define XML_ASSIGNMENT		"assignment"
#define XML_FUNCTIONDECL	"function_decl"
#define XML_PROCEDUREDECL	"procedure_decl"

#define XML_ID			"identifier"
#define XML_ARGS		"args"
#define XML_TYPE		"type"
#define XML_CONDITION		"condition"
#define XML_BLOCK		"block"
#define XML_CONTENT		"content"
#define XML_PARAM_BLOCK 	"paramlist"
#define XML_PARAM		"param"
#define XML_OPERATOR		"operator"
#define XML_EXPRESSION		"expression"
#define XML_LEFT		"left"
#define XML_RIGHT		"right"

#define XML_INDEX_PRM		"index"
#define XML_PARAM_PRM		"param"

#define XML_ROOT		"root"

#define XML_OUT			"output.xml"

#define NON			-1

// Assembly-related
//---------------------

#define EAX			"eax"
#define EBX			"ebx"
#define ECX			"ecx"
#define EDX			"edx"

#define AH			"ah"
#define AL			"al"
#define BH			"bh"
#define BL			"bl"
#define CH			"ch"
#define CL			"cl"
#define DH			"dh"
#define DL			"dl"

#define ESI			"esi"
#define EDI			"edi"

#define EBP			"ebp"
#define ESP			"esp"

#define ASM_MOV			"mov"
#define ASM_CALL		"call"
#define ASM_PUSH		"push"
#define ASM_PUSHA		"pusha"
#define ASM_POP			"pop"
#define ASM_POPA		"popa"
#define ASM_RESB		"resb"
#define ASM_RESW		"resw"
#define ASM_RESD		"resd"
#define ASM_RET			"ret"
#define ASM_ADD			"add"
#define ASM_SUB			"sub"
#define ASM_MUL			"mul"
#define ASM_DIV			"div"

#define ASM_JE			"je"
#define ASM_JNE			"jne"
#define ASM_JG			"jg"
#define ASM_JL			"jl"
#define ASM_JGE			"jge"
#define ASM_JLE			"jle"
#define ASM_JMP			"jmp"

#define ASM_CMP			"cmp"

#define ASM_OUT			"output.asm"

//=======================================
// Declarations
//=======================================

// EXTERNAL
//---------------------

extern FILE *yyin;
extern char *yytext; 
extern int yylex(void);
extern int yyparse(void);
extern int yycolumn;

// iq_utils.cpp
//---------------------

char* join(int numargs,...);
int intLength(const char* cstr);
bool isInt(const char* cstr);
string itos(int i);

// iq_cmdline.cpp
//---------------------

class iq_cmdline
{
	string arg[20];
	int argc;

	public:
		iq_cmdline(char** argv);
		void printAll(void);

		string getArg(int x) { return arg[x]; }
		int getArgc(void) { return argc; }
			
};

// iq_parsetree.cpp
//---------------------

enum typeof_node 
{ 
	proccall_node, 
	variabledecl_node, 
	assignment_node, 
	ifcase_node, 
	loopcase_node, 
	leaf_node, 
	condition_node, 
	statement_node,
	block_node,
	param_node,
	param_block_node,
	expression_node,
	functiondecl_node,
	proceduredecl_node,
	vardeclassignment_node
};

enum typeof_content { expression_content, block_content };

typedef struct pTree 
{
	enum typeof_node nodeType;
	union 
	{
		struct 
		{
			char* id;
			struct pTree* params;
		} procedure;

		struct 
		{
			char* id;
			char* type;
		} variabledecl;

		struct 
		{
			char* id;
			char* type;
			char* params;
			
			enum typeof_content contentType;
			union 
			{
				struct pTree* expression;
				struct pTree* block;
			} content;
		} assignment;
	
		struct 
		{
			struct pTree* vardecl;

			char* params;
			
			enum typeof_content contentType;
			union 
			{
				struct pTree* expression;
				struct pTree* block;
			} content;
		} vardeclassignment;

		struct 
		{
			char* id;
			char* type;
			char* params;
			
			enum typeof_content contentType;
			union 
			{
				struct pTree* expression;
				struct pTree* block;
			} content;
		} functiondecl;

		struct 
		{
			char* id;
			char* params;
			
			enum typeof_content contentType;
			union 
			{
				struct pTree* expression;
				struct pTree* block;
			} content;
		} proceduredecl;

		struct 
		{
			struct pTree* condition;
			struct pTree* block;
		} ifcase;

		struct 
		{
			struct pTree* condition;
			struct pTree* block;
		} loopcase;	
	
		struct 
		{
			struct pTree* expression1;
			struct pTree* expression2;
			char* oper;
		} stcondition;	

		struct 
		{
			struct pTree* left;
			struct pTree* right;
			char* oper;
		} expression;

		struct
		{
			int nos;			
			struct pTree** stats;
		} BLOCK;

		struct
		{
			int nop;
			struct pTree** params;
		} PARAM_BLOCK;

		struct pTree* statement;
		struct pTree* param_value;
		char* value;
	} body;
} pTree;

class iq_parsetree
{
	private:
		pTree* TreeRoot;

	public:
		iq_parsetree(string filename);

		void create(void);

		static pTree* addLeaf (char* str); 
		static pTree* addExpr (pTree* left, char* oper, pTree* right); 
		static pTree* addProc (char* id, pTree* params);
		static pTree* addVariableDecl (char* id, char* type);
		static pTree* addAssign2Expr (char* id, char* type, char* params, pTree* expression);
		static pTree* addAssign2Block (char* id, char* type, char* params, pTree* block);
		static pTree* addVardeclAssign2Expr (pTree* vardecl, char* params, pTree* expression);
		static pTree* addVardeclAssign2Block (pTree* vardecl, char* params, pTree* block);
		static pTree* addFunction2Expr (char* id, char* type, char* params, pTree* expression);
		static pTree* addFunction2Block (char* id, char* type, char* params, pTree* block);
		static pTree* addProcedure2Block (char* id, char* params, pTree* block);
		static pTree* addIf (pTree* condition, pTree* block);
		static pTree* addLoop (pTree* condition, pTree* block);
		static pTree* addCond (pTree* expression1, char* oper, pTree* expression2);

		static pTree* addStatementToBlock (pTree* statement, pTree* block);
		static pTree* addBlock (pTree* statement);

		static pTree* addParamToParamBlock (pTree* param, pTree* param_block);
		static pTree* addParamBlock (pTree* param);

		void setRoot (pTree* root);
		pTree* getRoot (void);

};

// iq_xml.cpp
//---------------------

class iq_xml
{
	private:	
		ifstream xml_in;
		ofstream xml_out;

		string filename;
	public:
		iq_xml(string fname);

		void openWrite(void);
		void closeWrite(void);

		void addElement (char* name, char* value);
		void addValue (char* value);
		void openSection (char* name);
		void openSectionWithParam (char* name, char* paramname, int k);
		void openSectionWithStrParam (char* name, char* paramname, char* k);
		void closeSection (char* name);

};

// iq_asm.cpp
//---------------------

#define RETURN_ASM(x) \
stringstream ss;\
ss << x << endl;\
return ss.str();

class iq_asm
{
	public:
		iq_asm(void);

		string mov   ( string dest, string src );			// mov dest, src		; dest = src
		string mov   ( string type, string dest, string src );		// mov type dest, src		; dest = src

		string add   ( string dest, string src );			// add dest, src		; dest += src
		string sub   ( string dest, string src );			// sub dest, src		; dest -= src
		string mul   ( string src );					// mul src			; eax  *= src
		string div   ( string src );					// div src			; eax  /= src

		string call  ( string proc );					// call proc			; proc

		string push  ( string value );					// push value			; push value to stack
		string pusha ( void );						// pusha			; push all to stack
		string pop   ( string value );					// pop value			; pop value from stack
		string popa  ( void );						// popa				; pop all from stack
		
		string resb  ( string id, string n );				// id resb n			; declare id as byte
		string resw  ( string id, string n );				// id resw n			; declare id as word
		string resd  ( string id, string n );				// id resd n			; declare id as double-word
		string ret   ( void );						// ret				; return

		string je    ( string loc );					// je loc			; jump to loc, if equal
		string jne   ( string loc );					// jne loc			; jump to loc, if not-equal
		string jg    ( string loc );					// jg loc			; jump to loc, if greater
		string jl    ( string loc );					// jl loc			; jump to loc, if less
		string jge   ( string loc );					// jge loc			; jump to loc, if greater or equal
		string jle   ( string loc );					// jle loc			; jump to loc, if less or equal
		string jmp   ( string loc );					// jmp loc			; unconditionally, jump to loc
	
		string cmp   ( string first, string second );			// cmp first, second		; jump to loc, if equal
};

// iq_xmltree.cpp
//---------------------

class iq_xmltree
{
	private:
		ofstream xml_out;
		iq_parsetree* parseTree;
		iq_xml* xml;

	public:
		iq_xmltree(iq_parsetree* ptree);

		void create (void);
		void encodeNode (pTree *t, int n); 
		
		void addXMLelement (char* name, char* value);
		void addXMLvalue (char* value);
		void openXMLsection (char* name);
		void openXMLsectionWithParam (char* name, char* paramname, int k);
		void closeXMLsection (char* name);
		iq_parsetree* getParseTree (void) { return parseTree; }
};

// iq_symtable.cpp
//---------------------

typedef vector<string> arg_array;

struct var_sym
{
	string name;
	string type;
};

struct func_sym
{
	string name;
	string type;
	arg_array args;
};

struct proc_sym
{
	string name;
	arg_array args;
};

class iq_symtable
{
	private:
		vector<var_sym> Variables;
		vector<func_sym> Functions;
		vector<proc_sym> Procedures;

	public:
		iq_symtable(void);

		void addVariable  (string nm, string tp);
		void addFunction  (string nm, string tp);
		void addProcedure (string nm);

		var_sym getVariable   (string nm);
		func_sym getFunction  (string nm);	
		proc_sym getProcedure (string nm);

		bool existsVariable  (string nm);
		bool existsFunction  (string nm);
		bool existsProcedure (string nm);

		void printAllVariables (void);
		void printAllFunctions (void);
		void printAllProcedures (void);
		void printAll (void);
};

// iq_codegen.cpp
//---------------------

#define ASM_INCLUDES "%include \"lib/asm_io.inc\"\n"

#define ASM_PRE_DATA \
";==========================\n\
;   Initialised Data\n\
;==========================\n\
segment .data\n"


#define ASM_PRE_BSS \
";==========================\n\
;   Uninitialised Data\n\
;==========================\n\
segment .bss\n"

#define ASM_PRE_TEXT \
";==========================\n\
;   Main Program\n\
;==========================\n\
segment .text\n\
\tglobal asm_main\n\n\
\tasm_main:\n\
\t\tenter 0,0\t\t;\tsetup routine\n\
\t\tpusha\n\
\t\tcall proc_main"

#define ASM_POST_TEXT \
"\t\tpopa\n\
\t\tmov eax, 0\n\
\t\tleave\n\
\t\tret\n"

#define INSERT_COMMENT_PRE_PROC(x,y) \
seg_TEXT << "\t;===================================" << endl;\
seg_TEXT << "\t; PROCEDURE " << x << endl;\
seg_TEXT << "\t;" << endl;\
seg_TEXT << "\t; args : " << y << endl;\
seg_TEXT << "\t;-----------------------------------" << endl;

#define INSERT_COMMENT_POST_PROC(x) \
seg_TEXT << "\t;-----------------------------------" << endl;\
seg_TEXT << "\t; END OF PROCEDURE " << t->body.proceduredecl.id << endl;\
seg_TEXT << "\t;===================================" << endl;

#define INSERT_COMMENT_PRE_FUNC(x,y) \
seg_TEXT << "\t;===================================" << endl;\
seg_TEXT << "\t; FUNCTION " << x << endl;\
seg_TEXT << "\t;" << endl;\
seg_TEXT << "\t; args : " << y << endl;\
seg_TEXT << "\t;-----------------------------------" << endl;

#define INSERT_COMMENT_POST_FUNC(x) \
seg_TEXT << "\t;-----------------------------------" << endl;\
seg_TEXT << "\t; END OF FUNCTION " << t->body.proceduredecl.id << endl;\
seg_TEXT << "\t;===================================" << endl;

class iq_codegen
{
	private:
		ofstream ASM;
		iq_xmltree* xmlTree;
		iq_parsetree* parseTree;
		iq_symtable* symTable;
		iq_asm* as;

		int noIfBlocks, noLoopBlocks;

		stringstream seg_DATA, seg_BSS, seg_TEXT;

	public:
		iq_codegen(iq_xmltree* xtree);
		void transform(void);
		void convertNode (pTree *t, int n);

		void initASM(void);
		void finalizeASM(void);
		void writeASMtoFile(void);
};

// iq_assembler.cpp
//---------------------

class iq_assembler
{
	private:
		string filename;
	public:
		iq_assembler(string fname);
		void go();
};

//=======================================
// 'Coz they gotta be... extrovert !
//=======================================

	extern iq_cmdline* cmdline;
	extern iq_parsetree* parsetree;
	extern pTree* last_node;

#endif

