/// Michael Landes
/// RDB Manager
/// //////////////

#include <iostream>

#include "lexicalAnalyzer/lexical.h"
#include "lexicalAnalyzer/token.h"

int main(int args, char** argv)
{
	// Get input file
	if (args != 2)
	{
		std::cout << "Usage: " << argv[0] << " <input>" << std::endl;
		return 1;
	}
	const char* input = argv[1];

	// Perform Lexical Analysis on Input Stream
	ML_RDBMAN::LexicalAnalyzer analyzer;
	try
	{
		analyzer.process(input);
	}
	catch(ML_RDBMAN::LexicalException& e)
	{
		switch(e.which())
		{
			case ML_RDBMAN::LexicalException::FileIO:
				std::cout << "Error reading file" << std::endl;
				break;
			case ML_RDBMAN::LexicalException::Line:
				std::cout << "Error on line " << e.where() << std::endl;
				break;
			default:
				std::cout << "Lexical Analyzer encountered an undefined error" << std::endl;
		}
		return 1;
	}
	catch(...)
	{
		std::cout << "Unexpected error occured... aborting" << std::endl;
		return 1;
	}

	// Print results
	std::vector<ML_RDBMAN::Token*>& tokens = analyzer.getTokens();
	for (unsigned int i = 0; i < analyzer.getSize(); ++i)
		ML_RDBMAN::TokenPrinter::printToken(std::cout, tokens[i]);
	std::cout << "Total Tokens = " << analyzer.getSize() << std::endl;

	return 0;
}
