# VARIABLES #
EXE = bin/rdbman

CC = g++
OPTIONS = -g -Wall

# BUILD SYSTEM #
$(EXE) : main.cpp
	$(CC) $(OPTIONS) -o $(EXE) main.cpp

# TARGETS #
.PHONY : release clean
release : $(EXE)

clean :
	rm -f $(EXE)
