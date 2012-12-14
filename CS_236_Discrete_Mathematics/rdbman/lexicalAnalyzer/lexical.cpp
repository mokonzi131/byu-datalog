/// Michael Landes
/// RDB Manager
/// //////////////

#include "lexical.h"

#include <stddef.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <ctype.h>

#include "token.h"

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
	int currentLine = 1;
	char c = '\0';
	while(file.good())
	{
		file.get(c);
		switch(c)
		{
			case ',':
				tokens.push_back(new Token(&c, 1, currentLine, Token::COMMA));
				break;
			case '.':
				tokens.push_back(new Token(&c, 1, currentLine, Token::PERIOD));
				break;
			case '?':
				tokens.push_back(new Token(&c, 1, currentLine, Token::Q_MARK));
				break;
			case '(':
				tokens.push_back(new Token(&c, 1, currentLine, Token::LEFT_PAREN));
				break;
			case ')':
				tokens.push_back(new Token(&c, 1, currentLine, Token::RIGHT_PAREN));
				break;
			default:
				std::cout << c;
		}
		if (c == '\n') ++currentLine;
		if (isspace(c)) continue;
	}
	std::cout << "Read: " << currentLine << " lines." << std::endl;

	// Cleanup
	file.close();
	for (unsigned int i = 0; i < tokens.size(); ++i)
		TokenPrinter::printToken(std::cout, tokens[i]);
}
