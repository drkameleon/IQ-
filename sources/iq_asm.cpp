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

IQ_ASM.CPP

*/

#include "iq_header.h"

iq_asm::iq_asm(void)
{

}

string iq_asm::mov ( string dest, string src )
{
	RETURN_ASM ( "\t\t" << ASM_MOV << " " << dest << ", " << src << "\t\t;\t" << dest << " = " << src );
}

string iq_asm::mov ( string type, string dest, string src )
{
	RETURN_ASM ( "\t\t" << ASM_MOV << " " << type << " " << dest << ", " << src << "\t\t;\t" << dest << " = " << src );
}

string iq_asm::call ( string proc )
{
	RETURN_ASM ( "\t\t" << ASM_CALL << " " << proc << "\t\t;\t" << proc );
}

string iq_asm::push ( string value )
{
	RETURN_ASM ( "\t\t" << ASM_PUSH << " " << value << "\t\t\t;\t" << "Push " << value << " to stack" );
}

string iq_asm::pusha (void)
{
	RETURN_ASM ( "\t\t" << ASM_PUSHA << "\t\t;\t" << "Push all to stack" );
}

string iq_asm::pop ( string value )
{
	RETURN_ASM ( "\t\t" << ASM_POP << " " << value << "\t\t\t;\t" << "Pop " << value << " from stack" );
}

string iq_asm::popa (void)
{
	RETURN_ASM ( "\t\t" << ASM_POPA << "\t\t;\t" << "Pop all from stack" );
}

string iq_asm::resb ( string id, string n )
{
	RETURN_ASM ( "\t\t" << id << " " << ASM_RESB << " " << n << "\t\t;\t" << " Declare " << id << " as BYTE" );
}

string iq_asm::resw ( string id, string n )
{
	RETURN_ASM ( "\t\t" << id << " " << ASM_RESW << " " << n << "\t\t;\t" << " Declare " << id << " as WORD" );
}

string iq_asm::resd ( string id, string n )
{
	RETURN_ASM ( "\t\t" << id << " " << ASM_RESD << " " << n << "\t\t;\t" << " Declare " << id << " as DOUBLE-WORD" );
}

string iq_asm::ret ( void )
{
	RETURN_ASM ( "\t\t" << ASM_RET );
}

string iq_asm::add ( string dest, string src )
{
	RETURN_ASM ( "\t\t" << ASM_ADD << " " << dest << ", " << src << "\t\t;\t" << dest << " += " << src );
}

string iq_asm::sub ( string dest, string src )
{
	RETURN_ASM ( "\t\t" << ASM_SUB << " " << dest << ", " << src << "\t\t;\t" << dest << " -= " << src );
}

string iq_asm::mul ( string src )
{
	RETURN_ASM ( "\t\t" << ASM_MUL << " " << src << "\t\t\t;\t" << EAX << " *= " << src );
}

string iq_asm::div ( string src )
{
	RETURN_ASM ( "\t\t" << ASM_DIV << " " << src << "\t\t\t;\t" << EAX << " /= " << src );
}

string iq_asm::je ( string loc )
{
	RETURN_ASM ( "\t\t" << ASM_JE << " " << loc << "\t\t\t;\t" << "If equal, jump to " << loc );
}

string iq_asm::jne ( string loc )
{
	RETURN_ASM ( "\t\t" << ASM_JNE << " " << loc << "\t\t\t;\t" << "If not-equal, jump to " << loc );
}

string iq_asm::jg ( string loc )
{
	RETURN_ASM ( "\t\t" << ASM_JG << " " << loc << "\t\t\t;\t" << "If greater, jump to " << loc );
}

string iq_asm::jl ( string loc )
{
	RETURN_ASM ( "\t\t" << ASM_JL << " " << loc << "\t\t\t;\t" << "If less, jump to " << loc );
}

string iq_asm::jge ( string loc )
{
	RETURN_ASM ( "\t\t" << ASM_JGE << " " << loc << "\t\t\t;\t" << "If greater or equal, jump to " << loc );
}

string iq_asm::jle ( string loc )
{
	RETURN_ASM ( "\t\t" << ASM_JLE << " " << loc << "\t\t\t;\t" << "If less equal, jump to " << loc );
}

string iq_asm::jmp ( string loc )
{
	RETURN_ASM ( "\t\t" << ASM_JMP << " " << loc << "\t\t\t;\t" << "Unconditionally, jump to " << loc );
}

string iq_asm::cmp ( string first, string second )
{
	RETURN_ASM ( "\t\t" << ASM_CMP << " " << first << ", " << second << "\t\t;\t" << "Compare " << first << ", " << second );
}
