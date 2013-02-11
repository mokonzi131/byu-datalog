/// Michael Landes
/// RDB Manager
/// //////////////

#include <iostream>

#include "parser/lexical.h"
#include "parser/token.h"
#include "parser/parser.h"
#include "datalog/datalogProgram.h"

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
//	for (unsigned int i = 0; i < analyzer.getSize(); ++i)
//		ML_RDBMAN::TokenPrinter::printToken(std::cout, tokens[i]);
//	std::cout << "Total Tokens = " << analyzer.getSize() << std::endl;
//	std::cout << "*********************************************" << std::endl;

	// Parse the Token List
	ML_RDBMAN::DatalogProgram* datalog = NULL;
	try
	{
		datalog = ML_RDBMAN::Parser::parseDatalogProgram(tokens);
		std::cout << "Success!" << std::endl;
	}
	catch(ML_RDBMAN::ParserException& e)
	{
		std::cout << "Failure!" << std::endl;
		std::cout << "\t";
		if (e.getToken() == NULL) std::cout << "Unexpected EOF";
		else ML_RDBMAN::TokenPrinter::printToken(std::cout, e.getToken());
		std::cout << std::endl;
	}
	catch(...)
	{
		std::cout << "Unexpected error occured while parsing tokens... aborting" << std::endl;
		return 2;
	}

	// Print Results


	// Cleanup
	for (unsigned int i = 0; i < tokens.size(); ++i)
		delete tokens[i];
	tokens.clear();

	if (datalog != NULL) datalog->toString();
	if (datalog != NULL) delete datalog;

	return 0;
}
