#
# IQ+ Compiler
# Copyright (C) 2009 Dr.Kameleon
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>
# 
# 
# MAKEFILE
# 
# 

#-------------------------
# Definitions
#-------------------------

#-- environment --

APP  = iqc

CPP  = g++
CC   = cc

LEX  = lex
YACC = yacc

RM   = rm -f
CP   = cp

DEST = /usr/bin

#-- C++ stuff --
CPP_OBJECTS = iq_main.o\
	      iq_cmdline.o\
	      iq_parsetree.o\
	      iq_xmltree.o\
	      iq_xml.o\
	      iq_asm.o\
	      iq_codegen.o\
	      iq_symtable.o\
	      iq_assembler.o\
	      iq_utils.o

CPP_SOURCES = iq_main.cpp\
	      iq_cmdline.cpp\
	      iq_parsetree.cpp\
	      iq_xmltree.cpp\
	      iq_xml.cpp\
	      iq_asm.cpp\
	      iq_codegen.cpp\
	      iq_symtable.cpp\
	      iq_assembler.cpp\
              iq_utils.cpp
	      

CPP_FLAGS = -Wall -Wno-write-strings -fexceptions
CPP_LIBS  = -ll

#-- C stuff --
CC_OBJECTS  = lex.yy.o\
              y.tab.o

CC_SOURCES  = lex.yy.c\
              y.tab.c

CC_FLAGS  = -c -x c++

CC_LEXER   = iq_lexer.l
CC_PARSER  = iq_parser.y


#-------------------------
# Main Functions
#-------------------------

all: ${APP}

${APP}: ${CPP_OBJECTS} ${CC_OBJECTS}
	${CPP} ${CFLAGS} ${CPP_OBJECTS} ${CC_OBJECTS} -o ${APP} ${CPP_LIBS}

${CPP_OBJECTS}: ${CPP_SOURCES}
	${CPP} ${CPP_FLAGS} ${CPP_SOURCES} -c

${CC_OBJECTS}: ${CC_SOURCES}
	${CPP} ${CC_FLAGS} ${CC_SOURCES}

${CC_SOURCES}:${CC_LEXER} ${CC_PARSER}
	${LEX} ${CC_LEXER}
	${YACC} -d ${CC_PARSER}	

install: 
	${CP} ${APP} ${DEST}

clean:
	${RM} ${APP} *.o *.c y.tab.h output.asm output.xml

