# VARIABLES #
EXE = bin/rdbman
OBJ = parser/token.o \
		parser/lexical.o \
		parser/parser.o \
		datalog/datalogProgram.o

CC = g++
OPTIONS = -g -Wall -I ./

# BUILD SYSTEM #
$(EXE) : main.cpp $(OBJ)
	$(CC) $(OPTIONS) -o $(EXE) main.cpp $(OBJ)

parser/token.o : parser/token.cpp parser/token.h
	$(CC) -c $(OPTIONS) -o parser/token.o parser/token.cpp

parser/lexical.o : parser/lexical.cpp parser/lexical.h
	$(CC) -c $(OPTIONS) -o parser/lexical.o parser/lexical.cpp

parser/parser.o : parser/parser.cpp parser/parser.h
	$(CC) -c $(OPTIONS) -o parser/parser.o parser/parser.cpp

datalog/datalogProgram.o : datalog/datalogProgram.cpp datalog/datalogProgram.h
	$(CC) -c $(OPTIONS) -o datalog/datalogProgram.o datalog/datalogProgram.cpp

# TARGETS #
.PHONY : release clean
release : $(EXE)

clean :
	rm -f $(EXE)
	rm -f parser/*.o
	rm -f datalog/*.o
