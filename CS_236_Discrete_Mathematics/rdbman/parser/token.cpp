/// Michael Landes
/// RDB Manager
/// //////////////

#include "token.h"

#include <ostream>

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

Token::TokenType
Token::getType()
{
	return type;
}

void
TokenPrinter::printToken(std::ostream& out, Token* token)
{
	out << "(";
	switch(token->type)
	{
		case Token::COMMA:
			out << "COMMA"; break;
		case Token::PERIOD:
			out << "PERIOD"; break;
		case Token::Q_MARK:
			out << "Q_MARK"; break;
		case Token::LEFT_PAREN:
			out << "LEFT_PAREN"; break;
		case Token::RIGHT_PAREN:
			out << "RIGHT_PAREN"; break;
		case Token::COLON:
			out << "COLON"; break;
		case Token::COLON_DASH:
			out << "COLON_DASH"; break;
		case Token::SCHEMES:
			out << "SCHEMES"; break;
		case Token::FACTS:
			out << "FACTS"; break;
		case Token::RULES:
			out << "RULES"; break;
		case Token::QUERIES:
			out << "QUERIES"; break;
		case Token::ID:
			out << "ID"; break;
		case Token::STRING:
			out << "STRING"; break;
		case Token::COMMENT:
			out << "COMMENT"; break;
		case Token::WHITESPACE:
			out << "WHITESPACE"; break;
	}
	out << ",\"" << token->token->c_str() << "\",";
	out << token->linenumber;
	out << ")" << std::endl;
}
