/// Michael Landes
/// RDB Manager
/// //////////////

#include <string>

#ifndef ML_RDBMAN_TOKEN_H
#define ML_RDBMAN_TOKEN_H

namespace ML_RDBMAN
{

class Token
{
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

	public:
		Token(char*, size_t, unsigned int, TokenType);
		virtual ~Token();

		std::string* 	getToken();
		unsigned int 	getLine();
		TokenType 		getType();

	private:
		std::string*	token;
		unsigned int	linenumber;
		TokenType 		type;
};

}

#endif // TOKEN_H
