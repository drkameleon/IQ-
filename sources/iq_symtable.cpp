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

IQ_SYMTABLE.CPP

*/

#include "iq_header.h"

iq_symtable::iq_symtable(void)
{
	
}

void iq_symtable::addVariable (string nm, string tp)
{
	var_sym vs;

	vs.name = nm;
	vs.type = tp;

	Variables.push_back(vs);
}

void iq_symtable::addFunction (string nm, string tp)
{
	func_sym fs;

	fs.name = nm;
	fs.type = tp;

	Functions.push_back(fs);
}

void iq_symtable::addProcedure (string nm)
{
	proc_sym ps;

	ps.name = nm;

	Procedures.push_back(ps);	
}

var_sym iq_symtable::getVariable (string nm)
{
	var_sym vs;
	
	for (unsigned int i=0; i<Variables.size(); i++)
		if (Variables[i].name == nm) 
			return Variables[i];

	return vs;
}

func_sym iq_symtable::getFunction (string nm)
{
	func_sym fs;

	for (unsigned int i=0; i<Functions.size(); i++)
		if (Functions[i].name == nm) 
			return Functions[i];

	return fs;
}

proc_sym iq_symtable::getProcedure (string nm)
{
	proc_sym ps;

	for (unsigned int i=0; i<Procedures.size(); i++)
		if (Procedures[i].name == nm) 
			return Procedures[i];

	return ps;
}

bool iq_symtable::existsVariable (string nm)
{
	for (unsigned int i=0; i<Variables.size(); i++)
		if (Variables[i].name == nm) 
			return true;

	return false;
}

bool iq_symtable::existsFunction (string nm)
{
	for (unsigned int i=0; i<Functions.size(); i++)
		if (Functions[i].name == nm) 
			return true;

	return false;
}

bool iq_symtable::existsProcedure (string nm)
{
	for (unsigned int i=0; i<Procedures.size(); i++)
		if (Procedures[i].name == nm) 
			return true;

	return false;
}

void iq_symtable::printAllVariables(void)
{
	for (unsigned int i=0; i<Variables.size(); i++)
        {
		cout << "Variable #" << i+1 << endl;
		cout << "\t-- name : " << Variables[i].name << endl;
		cout << "\t-- type : " << Variables[i].type << endl;	
        } 
}

void iq_symtable::printAllFunctions(void)
{
	for (unsigned int i=0; i<Functions.size(); i++)
        {
		cout << "Function #" << i+1 << endl;
		cout << "\t-- name : " << Functions[i].name << endl;
		cout << "\t-- type : " << Functions[i].type << endl;	
        } 
}

void iq_symtable::printAllProcedures(void)
{
	for (unsigned int i=0; i<Procedures.size(); i++)
        {
		cout << "Procedure #" << i+1 << endl;
		cout << "\t-- name : " << Procedures[i].name << endl;
        } 
}

void iq_symtable::printAll(void)
{
	printAllVariables();
	printAllFunctions();
	printAllProcedures();
}

