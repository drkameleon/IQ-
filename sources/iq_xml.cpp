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

IQ_XML.CPP

*/

#include "iq_header.h"

iq_xml::iq_xml(string fname)
{
	filename = fname;
}

void iq_xml::openWrite(void)
{
	xml_out.open ( filename.c_str() );
}

void iq_xml::closeWrite(void)
{
	xml_out.close();
}

void iq_xml::addElement (char* name, char* value)
{
	xml_out << "<" << name << ">" << endl;
	xml_out << value << endl;
	xml_out << "</" << name << ">" << endl;
}

void iq_xml::addValue (char* value)
{
	xml_out << value << endl;
}

void iq_xml::openSection (char* name)
{
	xml_out << "<" << name << ">" << endl;
}

void iq_xml::openSectionWithParam (char* name, char* paramname, int k)
{
	xml_out << "<" << name << " " << paramname << "=\"" << k << "\" >" << endl;
}

void iq_xml::openSectionWithStrParam (char* name, char* paramname, char* k)
{
	xml_out << "<" << name << " " << paramname << "=\"" << k << "\" >" << endl;
}


void iq_xml::closeSection (char* name)
{
	xml_out << "</" << name << ">" << endl;
}
