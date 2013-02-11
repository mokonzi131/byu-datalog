# VARIABLES #
EXE = bin/rdbman
OBJ =   parser/token.o \
		parser/lexical.o \
		parser/parser.o \
		datalog/datalogProgram.o \
		datalog/schemeList.o \
		datalog/factList.o \
		datalog/ruleList.o \
		datalog/queryList.o \
		datalog/scheme.o \
		datalog/rule.o \
		datalog/fact.o \
		datalog/query.o \
		datalog/predicateList.o \
		datalog/parameterList.o \
		datalog/predicate.o \
		datalog/parameter.o \
		datalog/domain.o \

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

datalog/schemeList.o : datalog/schemeList.cpp datalog/schemeList.h
	$(CC) -c $(OPTIONS) -o datalog/schemeList.o datalog/schemeList.cpp

datalog/factList.o : datalog/factList.cpp datalog/factList.h
	$(CC) -c $(OPTIONS) -o datalog/factList.o datalog/factList.cpp

datalog/ruleList.o : datalog/ruleList.cpp datalog/ruleList.h
	$(CC) -c $(OPTIONS) -o datalog/ruleList.o datalog/ruleList.cpp

datalog/queryList.o : datalog/queryList.cpp datalog/queryList.h
	$(CC) -c $(OPTIONS) -o datalog/queryList.o datalog/queryList.cpp

datalog/scheme.o : datalog/scheme.cpp datalog/scheme.h
	$(CC) -c $(OPTIONS) -o datalog/scheme.o datalog/scheme.cpp

datalog/fact.o : datalog/fact.cpp datalog/fact.h
	$(CC) -c $(OPTIONS) -o datalog/fact.o datalog/fact.cpp

datalog/rule.o : datalog/rule.cpp datalog/rule.h
	$(CC) -c $(OPTIONS) -o datalog/rule.o datalog/rule.cpp

datalog/query.o : datalog/query.cpp datalog/query.h
	$(CC) -c $(OPTIONS) -o datalog/query.o datalog/query.cpp

datalog/predicateList.o : datalog/predicateList.cpp datalog/predicateList.h
	$(CC) -c $(OPTIONS) -o datalog/predicateList.o datalog/predicateList.cpp

datalog/parameterList.o : datalog/parameterList.cpp datalog/parameterList.h
	$(CC) -c $(OPTIONS) -o datalog/parameterList.o datalog/parameterList.cpp

datalog/predicate.o : datalog/predicate.cpp datalog/predicate.h
	$(CC) -c $(OPTIONS) -o datalog/predicate.o datalog/predicate.cpp

datalog/parameter.o : datalog/parameter.cpp datalog/parameter.h
	$(CC) -c $(OPTIONS) -o datalog/parameter.o datalog/parameter.cpp

datalog/domain.o : datalog/domain.cpp datalog/domain.h
	$(CC) -c $(OPTIONS) -o datalog/domain.o datalog/domain.cpp

# TARGETS #
.PHONY : release clean
release : $(EXE)

clean :
	rm -f $(EXE)
	rm -f parser/*.o
	rm -f datalog/*.o
