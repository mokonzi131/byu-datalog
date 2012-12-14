/// Michael Landes
/// RDB Manager
/// //////////////

#include <vector>
#include <exception>

namespace ML_RDBMAN { class Token; }

#ifndef ML_RDBMAN_LEXICAL_H
#define ML_RDBMAN_LEXICAL_H

namespace ML_RDBMAN
{

class LexicalException : public std::exception
{
	public:

		enum ErrorType
		{
			Undefined,
			FileIO,
			Line
		};

		LexicalException(ErrorType _type) : type(_type) {}
		LexicalException(ErrorType _type, int _location) : type(_type), location(_location) {}

		virtual const char* what() const throw() { return "Lexical Analyzer: Line analysis error"; }
		unsigned int where() const throw() { return location; }
		ErrorType which() const throw() { return type; }

	private:
		ErrorType type;
		unsigned int location;
};

class LexicalAnalyzer
{
	public:
		LexicalAnalyzer();
		virtual ~LexicalAnalyzer();

		void process(const char* filename);

	private:
		std::vector<Token*> tokens;
};

}

#endif // ML_RDBMAN_LEXICAL_H
