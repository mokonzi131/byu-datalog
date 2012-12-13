/// Michael Landes
/// RDB Manager
/// //////////////

#include <iostream>

#include "lexicalAnalyzer/lexical.h"

int main()
{
	///std::cout << "Hello World!" << std::endl;

	// Perform Lexical Analysis on Input Stream
	ML_RDBMAN::LexicalAnalyzer analyzer;
	try
	{
		analyzer.process("test");
	}
	catch(ML_RDBMAN::LexicalException& e)
	{
		std::cout << "Error on line " << e.where() << std::endl;
	}

	// Parse List of Tokens
	// ...

	return 0;
}
