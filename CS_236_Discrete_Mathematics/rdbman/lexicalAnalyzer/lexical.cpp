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
	unsigned int currentLine = 1;
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
			case ':':
				processColon(file, currentLine);
				break;
			case '#':
				processComment(file);
				break;
			case '\'':
				processString(file, currentLine);
				break;
			case '\n':
				++currentLine;
				break;
			default:
				if (isalpha(c))
				{
					file.putback(c);
					processID(file, currentLine);
					break;
				}
				if (isspace(c)) break;
				file.close();
				throw LexicalException(LexicalException::Line, currentLine);
		}
	}

	// Cleanup
	file.close();
}

std::size_t
LexicalAnalyzer::getSize()
{
	return tokens.size();
}

std::vector<Token*>&
LexicalAnalyzer::getTokens()
{
	return tokens;
}

void
LexicalAnalyzer::processComment(std::ifstream& file)
{
	while(file.good() && file.peek() != '\n')
		file.ignore(1);
}

void
LexicalAnalyzer::processColon(std::ifstream& file, unsigned int line)
{
	static const std::string colon = ":";
	static const std::string col_dash = ":-";

	if (file.good() && file.peek() != '-')
		tokens.push_back(new Token(const_cast<char*>(colon.c_str()), 1, line, Token::COLON));
	else
	{
		file.ignore(1);
		tokens.push_back(new Token(const_cast<char*>(col_dash.c_str()), 2, line, Token::COLON_DASH));
	}
}

void
LexicalAnalyzer::processString(std::ifstream& file, unsigned int line)
{
	std::string value = "";
	char c = '\0';

	while (file.get(c))
	{
		if (c == '\'')
		{
			tokens.push_back(new Token(const_cast<char*>(value.c_str()), value.size(), line, Token::STRING));
			return;
		}
		if (c == '\n') break;
		value += c;
	}

	file.close();
	throw LexicalException(LexicalException::Line, line);
}

void
LexicalAnalyzer::processID(std::ifstream& file, unsigned int line)
{
	std::string value = "";
	char c = '\0';

	while(file.get(c))
	{
		if (isalnum(c))
			value += c;
		else
		{
			file.putback(c);
			break;
		}
	}

	if (value.compare("Schemes") == 0)
		tokens.push_back(new Token(const_cast<char*>(value.c_str()), value.size(), line, Token::SCHEMES));
	else if (value.compare("Facts") == 0)
		tokens.push_back(new Token(const_cast<char*>(value.c_str()), value.size(), line, Token::FACTS));
	else if (value.compare("Rules") == 0)
		tokens.push_back(new Token(const_cast<char*>(value.c_str()), value.size(), line, Token::RULES));
	else if (value.compare("Queries") == 0)
		tokens.push_back(new Token(const_cast<char*>(value.c_str()), value.size(), line, Token::QUERIES));
	else
		tokens.push_back(new Token(const_cast<char*>(value.c_str()), value.size(), line, Token::ID));
}
