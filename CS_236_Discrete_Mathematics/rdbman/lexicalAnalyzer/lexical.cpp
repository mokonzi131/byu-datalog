/// Michael Landes
/// RDB Manager
/// //////////////

#include "lexical.h"

#include <stddef.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace ML_RDBMAN;

LexicalAnalyzer::LexicalAnalyzer() {}

LexicalAnalyzer::~LexicalAnalyzer() {}

void
LexicalAnalyzer::process(const char* filename)
{
	// Open file for processing
	std::ifstream file;
	file.open(filename, std::ios::in);
	if (!file.is_open())
		throw LexicalException(LexicalException::FileIO);

	// Process file
	while(file.good())
	{
		char c;
		file.get(c);
		std::cout << c;
	}

	// Cleanup
	file.close();
}
