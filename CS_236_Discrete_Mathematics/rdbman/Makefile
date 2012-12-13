# VARIABLES #
EXE = bin/rdbman
OBJ = lexicalAnalyzer/token.o

CC = g++
OPTIONS = -g -Wall

# BUILD SYSTEM #
$(EXE) : main.cpp $(OBJ)
	$(CC) $(OPTIONS) -o $(EXE) main.cpp $(OBJ)

lexicalAnalyzer/token.o : lexicalAnalyzer/token.cpp lexicalAnalyzer/token.h
	$(CC) -c $(OPTIONS) -o lexicalAnalyzer/token.o lexicalAnalyzer/token.cpp

# TARGETS #
.PHONY : release clean
release : $(EXE)

clean :
	rm -f $(EXE)
	rm -f lexicalAnalyzer/*.o
