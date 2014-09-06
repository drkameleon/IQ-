%{
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

IQ_LEXER.L

*/

#include <stdio.h>
#include "iq_header.h"
#include "y.tab.h"

void count();

%}

DIGIT			[0-9]
LETTER			[a-zA-Z_]
HEX			[a-fA-F0-9]
BINARY			[0-1]

%%
^[ \t]*"//".*\n				{ /* This is a '//' single-line comment */ }

"program"				{ count(); return(PROGRAM); }
"library"				{ count(); return(LIBRARY); }

"_str"					{ count(); return(FUNC_STR); }
"_int"					{ count(); return(FUNC_INT); }
"_float"				{ count(); return(FUNC_FLOAT); }
"_chr"					{ count(); return(FUNC_CHR); }
"_bool"					{ count(); return(FUNC_BOOL); }

"proc"					{ count(); return(PROC); }
"str"					{ count(); return(STR); }
"int"					{ count(); return(INT); }
"float"					{ count(); return(FLOAT); }
"chr"					{ count(); return(CHR); }
"bool"					{ count(); return(BOOL); }
"rule"					{ count(); return(RULE); }

"#proc"					{ count(); return(PROC_ARR); }
"#str"					{ count(); return(STR_ARR); }
"#int"					{ count(); return(INT_ARR); }
"#float"				{ count(); return(FLOAT_ARR); }
"#chr"					{ count(); return(CHR_ARR); }
"#bool"					{ count(); return(BOOL_ARR); }
"#rule"					{ count(); return(RULE_ARR); }

"if"					{ count(); return(IF); }
"elseif"				{ count(); return(ELSEIF); }
"else"					{ count(); return(ELSE); }
"loopif"				{ count(); return(LOOPIF); }

"$entry"				{ count(); return(ENTRY); }
"$import"				{ count(); return(IMPORT); }
"$export"				{ count(); return(EXPORT); }
"$return"				{ count(); return(RETURN); }

"and"					{ count(); return(AND_OP); }
"or"					{ count(); return(OR_OP); }
"not"					{ count(); return(NOT_OP); }

{LETTER}({LETTER}|{DIGIT})*		{ count(); return(ID); }

{DIGIT}+				{ count(); return(DECIMAL); 	/* DECIMAL NUMBER */}
0"h"{HEX}+				{ count(); return(HEXADECIMAL); /* HEXADECIMAL NUMBER */}
0"b"{BINARY}+				{ count(); return(BINARY); 	/* BINARY NUMBER */}  
{DIGIT}+"."{DIGIT}+			{ count(); return(REAL); 	/* REAL NUMBER */}

\".+\"					{ count(); return(STRING); }

"=="					{ count(); return(EQ_OP); }
"<<"					{ count(); return(LT_OP); }
">>"					{ count(); return(GT_OP); }
"<="					{ count(); return(LE_OP); }
">="					{ count(); return(GE_OP); }
"/="					{ count(); return(NE_OP); }

"-->"					{ count(); return(RANGE); }

"("					{ count(); return('('); }
")"					{ count(); return(')'); }
"{"					{ count(); return('{'); }
"}"					{ count(); return('}'); }
"["					{ count(); return('['); }
"]"					{ count(); return(']'); }

"-"					{ count(); return('-'); }
"+"					{ count(); return('+'); }
"*"					{ count(); return('*'); }
"/"					{ count(); return('/'); }

"="					{ count(); return('='); }
";"					{ count(); return(';'); }
","					{ count(); return(','); }
":"					{ count(); return(':'); }
"."					{ count(); return('.'); }
"?"					{ count(); return('?'); }
"%"					{ count(); return('%'); }
"&"					{ count(); return('&'); }
"$"					{ count(); return('$'); }
"#"					{ count(); return('#'); }
"@"					{ count(); return('@'); }
"|"					{ count(); return('|'); }
"!"					{ count(); return('!'); }
"~"					{ count(); return('~'); }
"^"					{ count(); return('^'); }

[ \t\v\n\f]				{ count(); }
.					{ /* ignore everything else */ }

%%

int yycolumn = 0;

void count()
{
	int i;
	
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			yycolumn = 0;
		else if (yytext[i] == '\t')
			yycolumn += 8 - (yycolumn % 8);
		else
			yycolumn++;

	//ECHO;

	yylval.str=strdup(yytext);
}


