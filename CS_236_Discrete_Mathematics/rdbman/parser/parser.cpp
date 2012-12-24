/// Michael Landes
/// RDB Manager
/// //////////////

#include "parser.h"

#include <stdlib.h>
#include <stdio.h>

#include "datalog/datalogProgram.h"
#include "token.h"

using namespace ML_RDBMAN;

Parser::Parser() {}

Parser::~Parser() {}

DatalogProgram* Parser::parseDatalogProgram(const std::vector<Token*>& tokens)
{
	DatalogProgram* datalogProgram = new DatalogProgram();
	std::vector<Token*>::const_iterator it = tokens.begin();
	Token* token;

	// SCHEMES : <Scheme List>
	token = *it++;
	if (token == NULL || token->getType() != Token::SCHEMES) throw ParserException(token);
	token = *it++;
	if (token == NULL || token->getType() != Token::COLON) throw ParserException(token);
	parseSchemeList(it);

	// FACTS : <Fact List>
	token = *it++;
	if (token == NULL || token->getType() != Token::FACTS) throw ParserException(token);
	token = *it++;
	if (token == NULL || token->getType() != Token::COLON) throw ParserException(token);
	parseFactList(it);

	// RULES : <Rule List>
	token = *it++;
	if (token == NULL || token->getType() != Token::RULES) throw ParserException(token);
	token = *it++;
	if (token == NULL || token->getType() != Token::COLON) throw ParserException(token);
	parseRuleList(it);

	// QUERIES : <Query List>
	token = *it++;
	if (token == NULL || token->getType() != Token::QUERIES) throw ParserException(token);
	token = *it++;
	if (token == NULL || token->getType() != Token::COLON) throw ParserException(token);
	parseQueryList(it);

	// EOF
	token = *it++;
	if (token != NULL) throw ParserException(token);

	return datalogProgram;
}

void Parser::parseSchemeList(std::vector<Token*>::const_iterator& it)
{
	// TODO
}

void Parser::parseFactList(std::vector<Token*>::const_iterator& it)
{
	// TODO
}

void Parser::parseRuleList(std::vector<Token*>::const_iterator& it)
{
	// TODO
}

void Parser::parseQueryList(std::vector<Token*>::const_iterator& it)
{
	// TODO
}
