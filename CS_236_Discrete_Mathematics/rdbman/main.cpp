/// Michael Landes
/// RDB Manager
/// //////////////

#include <iostream>

#include "lexicalAnalyzer/lexical.h"

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
	}
	catch(...)
	{
		std::cout << "Unexpected error occured... aborting" << std::endl;
	}

	// Print results

	return 0;
}
