/// Michael Landes
/// RDB Manager
/// //////////////

#include <string>
#include <ostream>

#ifndef ML_RDBMAN_TOKEN_H
#define ML_RDBMAN_TOKEN_H

namespace ML_RDBMAN
{

class Token
{
	friend class TokenPrinter;
	public:
		enum TokenType
		{
			COMMA,
			PERIOD,
			Q_MARK,
			LEFT_PAREN,
			RIGHT_PAREN,
			COLON,
			COLON_DASH,
			SCHEMES,
			FACTS,
			RULES,
			QUERIES,
			ID,
			STRING,
			COMMENT,
			WHITESPACE
		};

		Token(char* _token, size_t _length, unsigned int _linenumber, TokenType _type);
		virtual ~Token();

	private:
		std::string*	token;
		unsigned int	linenumber;
		TokenType 		type;
};

class TokenPrinter
{
	public:
		static void printToken(std::ostream& out, Token* token);
};

}

#endif
