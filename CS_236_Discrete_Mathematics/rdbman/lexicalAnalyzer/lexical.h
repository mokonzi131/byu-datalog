/// Michael Landes
/// RDB Manager
/// //////////////

#include <vector>
#include <exception>

class Token;

#ifndef ML_RDBMAN_LEXICAL_H
#define ML_RDBMAN_LEXICAL_H

namespace ML_RDBMAN
{

class LexicalException : public std::exception
{
	public:
		LexicalException(int _location) : location(_location) {}

		virtual const char* what() const throw() { return "Lexical Analyzer: Line analysis error"; }
		unsigned int where() const throw() { return location; }

	private:
		unsigned int location;
};

class LexicalAnalyzer
{
	public:
		LexicalAnalyzer();
		virtual ~LexicalAnalyzer();

		void process(char* filename);

	private:
		std::vector<Token*> tokens;
};

}

#endif // ML_RDBMAN_LEXICAL_H
