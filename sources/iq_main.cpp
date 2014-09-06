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

IQ_MAIN.CPP

*/

#include "iq_header.h"

//=======================================
// The illusion of minimalism...
//=======================================

iq_cmdline* cmdline;
iq_parsetree* parsetree;
iq_xmltree* xmltree;
iq_codegen* codegen;
iq_assembler* assembler;

int main(int argc, char** argv)
{
	cout << "IQ+ Compiler v0.1 - (c) 2009 Dr.Kameleon\n\n";

	cmdline = new iq_cmdline ( argv );

	parsetree = new iq_parsetree ( cmdline->getArg(0) );
	parsetree->create();

	xmltree = new iq_xmltree ( parsetree );	
	xmltree->create();

	codegen = new iq_codegen( xmltree );
	codegen->transform();
	
	assembler = new iq_assembler( cmdline->getArg(1) );
	assembler->go();	

	return 0;
}

//====================================================
// This is the end                                   |
// My only friend, the end...                        |
//                                                   |
//---------------------------------------------------|
// *Always Enjoying the ART of Code - Dr.Kameleon    |
//====================================================

