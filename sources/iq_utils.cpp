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

IQ_UTILS.CPP

*/

#include "iq_header.h"

const char* spaces = " \t";
const char* digits = "0123456789";

char* join(int numargs,...)
{
	va_list ap;
  	int args = 0;

	stringstream buff;

	va_start(ap, numargs);

	while(args < numargs)
	{
		buff << va_arg(ap, const char *) << " ";
		args++;
	}

	string res = buff.str();
	char * cstr = new char [res.size()+1];
	strcpy (cstr, res.c_str());

	va_end(ap);

	return cstr;
}

int intLength(const char* cstr)
{
  int    k, n = 0;
  if (cstr)
  {
    n = strspn(cstr,spaces);
    cstr += n;
    if (*cstr == '-' || *cstr == '+')
        ++cstr, ++n;
    k = strspn(cstr,digits);
    n = k?n+k:0;
  }
  return n;
}

bool isInt(const char* cstr)
{
  return intLength(cstr) > 0;
}

string itos(int i)
{
    stringstream s;
    s << i;
    return s.str();
}

