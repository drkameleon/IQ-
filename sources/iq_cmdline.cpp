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

IQ_CMDLINE.CPP

*/

#include "iq_header.h"

iq_cmdline::iq_cmdline(char** argv) 
{
	int cnt = -1;

	while (*argv)
	{
		if (cnt!=-1) arg[cnt]=string(*argv);

		*argv++;	
		cnt++;
	}
	argc = cnt;
}

void iq_cmdline::printAll(void)
{
	for (int x=0; x<argc; x++)
		cout << "arg[" << x << "] = " << arg[x] << endl;
}

