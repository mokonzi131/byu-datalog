/// Michael Landes
/// RDB Manager
/// //////////////

#include "token.h"

using namespace ML_RDBMAN;

Token::Token(char* _token, size_t _length, unsigned int _linenumber, TokenType _tokenType)
	: token(NULL), linenumber(_linenumber), type(_tokenType)
{
	token = new std::string(_token, _length);
}

Token::~Token()
{
	delete token;
}

std::string*
Token::getToken()
{
	return token;
}

unsigned int
Token::getLine()
{
	return linenumber;
}

Token::TokenType
Token::getType()
{
	return type;
}
