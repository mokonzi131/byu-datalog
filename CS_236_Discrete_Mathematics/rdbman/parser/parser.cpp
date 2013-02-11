/// Michael Landes
/// RDB Manager
/// //////////////

#include "parser.h"

#include <stdlib.h>
#include <stdio.h>

#include "datalog/datalogProgram.h"
#include "datalog/schemeList.h"
#include "datalog/factList.h"
#include "datalog/ruleList.h"
#include "datalog/queryList.h"
#include "datalog/scheme.h"
#include "datalog/fact.h"
#include "datalog/rule.h"
#include "datalog/query.h"
#include "datalog/predicateList.h"
#include "datalog/predicate.h"
#include "datalog/parameterList.h"
#include "datalog/parameter.h"
#include "datalog/domain.h"
#include "token.h"

using namespace ML_RDBMAN;

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
	SchemeList* schemeList = parseSchemeList(it);
	datalogProgram->setSchemeList(schemeList);

	// FACTS : <Fact List>
	token = *it++;
	if (token == NULL || token->getType() != Token::FACTS) throw ParserException(token);
	token = *it++;
	if (token == NULL || token->getType() != Token::COLON) throw ParserException(token);
	FactList* factList = parseFactList(it);
	datalogProgram->setFactList(factList);

	// RULES : <Rule List>
	token = *it++;
	if (token == NULL || token->getType() != Token::RULES) throw ParserException(token);
	token = *it++;
	if (token == NULL || token->getType() != Token::COLON) throw ParserException(token);
	RuleList* ruleList = parseRuleList(it);
	datalogProgram->setRuleList(ruleList);

	// QUERIES : <Query List>
	token = *it++;
	if (token == NULL || token->getType() != Token::QUERIES) throw ParserException(token);
	token = *it++;
	if (token == NULL || token->getType() != Token::COLON) throw ParserException(token);
	QueryList* queryList = parseQueryList(it);
	datalogProgram->setQueryList(queryList);

	// EOF
	token = *it++;
	if (token != NULL) throw ParserException(token);

	// Domain = all "string" tokens
	Domain* domain = parseDomain(tokens);
	datalogProgram->setDomain(domain);

	return datalogProgram;
}

SchemeList* Parser::parseSchemeList(std::vector<Token*>::const_iterator& it)
{
	SchemeList* schemeList = new SchemeList();

	// <Scheme> <SchemeList> | <Scheme>
	Scheme* scheme = parseScheme(it);
	schemeList->addScheme(scheme);

	std::vector<Token*>::const_iterator tt = it;
	SchemeList* tail = NULL;
	try
	{
		tail = parseSchemeList(tt);
		for (std::vector<Scheme*>::const_iterator dt = tail->getList().begin(); dt != tail->getList().end(); ++dt)
			schemeList->addScheme(new Scheme(**dt));
		it = tt;
	}
	catch (ParserException e) {}
	if (tail != NULL) delete tail;

	return schemeList;
}

Scheme* Parser::parseScheme(std::vector<Token*>::const_iterator& it)
{
	// <Predicate>
	Predicate* predicate = parsePredicate(it);

	Scheme* scheme = new Scheme(predicate);

	return scheme;
}

FactList* Parser::parseFactList(std::vector<Token*>::const_iterator& it)
{
	FactList* factList = new FactList();

	// <Fact> <FactList> | e
	Fact* fact = NULL;
	std::vector<Token*>::const_iterator tt = it;
	FactList* tail = NULL;
	try
	{
		fact = parseFact(tt);
		factList->addFact(fact);
		tail = parseFactList(tt);
		for (std::vector<Fact*>::const_iterator dt = tail->getList().begin(); dt != tail->getList().end(); ++dt)
			factList->addFact(new Fact(**dt));
		it = tt;
	}
	catch (ParserException e) {}
	if (tail != NULL) delete tail;

	return factList;
}

Fact* Parser::parseFact(std::vector<Token*>::const_iterator& it)
{
	// <Preducate> .
	Predicate* predicate = parsePredicate(it);

	Fact* fact = new Fact(predicate);

	Token* token = *it++;
	if (token == NULL || token->getType() != Token::PERIOD) throw ParserException(token);

	return fact;
}

RuleList* Parser::parseRuleList(std::vector<Token*>::const_iterator& it)
{
	RuleList* ruleList = new RuleList();

	// <Rule> <RuleList> | e
	Rule* rule = NULL;
	std::vector<Token*>::const_iterator tt = it;
	RuleList* tail = NULL;
	try
	{
		rule = parseRule(tt);
		ruleList->addRule(rule);
		tail = parseRuleList(tt);
		for (std::vector<Rule*>::const_iterator dt = tail->getList().begin(); dt != tail->getList().end(); ++dt)
			ruleList->addRule(new Rule(**dt));
		it = tt;
	}
	catch (ParserException e) {}
	if (tail != NULL) delete tail;

	return ruleList;
}

Rule* Parser::parseRule(std::vector<Token*>::const_iterator& it)
{
	// <Predicate> :- <PredicateList> .
	Predicate* predicate = parsePredicate(it);

	Token* token = *it++;
	if (token == NULL || token->getType() != Token::COLON_DASH) throw ParserException(token);

	PredicateList* plist = parsePredicateList(it);

	token = *it++;
	if (token == NULL || token->getType() != Token::PERIOD) throw ParserException(token);

	Rule* rule = new Rule(predicate, plist);

	return rule;
}

QueryList* Parser::parseQueryList(std::vector<Token*>::const_iterator& it)
{
	QueryList* queryList = new QueryList();

	// <Query> <QueryList> | <Query>
	Query* query = parseQuery(it);
	queryList->addQuery(query);

	std::vector<Token*>::const_iterator tt = it;
	QueryList* tail = NULL;
	try
	{
		tail = parseQueryList(tt);
		for (std::vector<Query*>::const_iterator dt = tail->getList().begin(); dt != tail->getList().end(); ++dt)
			queryList->addQuery(new Query(**dt));
		it = tt;
	}
	catch (ParserException e) {}
	if (tail != NULL) delete tail;

	return queryList;
}

Query* Parser::parseQuery(std::vector<Token*>::const_iterator& it)
{
	// <Preducate> ?
	Predicate* predicate = parsePredicate(it);

	Query* query = new Query(predicate);

	Token* token = *it++;
	if (token == NULL || token->getType() != Token::Q_MARK) throw ParserException(token);

	return query;
}

PredicateList* Parser::parsePredicateList(std::vector<Token*>::const_iterator& it)
{
	PredicateList* predicates = new PredicateList();

	// <Predicate> | <Predicate> , <PredicateList>
	Predicate* predicate = parsePredicate(it);
	predicates->addPredicate(predicate);

	if (*it != NULL && (*it)->getType() == Token::COMMA)
	{
		++it;
		PredicateList* tail = new PredicateList();
		tail = parsePredicateList(it);
		for (std::vector<Predicate*>::const_iterator it = tail->getList().begin(); it != tail->getList().end(); ++it)
			predicates->addPredicate(new Predicate(**it));
		delete tail;
	}

	return predicates;
}

Predicate* Parser::parsePredicate(std::vector<Token*>::const_iterator& it)
{
	Predicate* predicate = new Predicate();

	// Identifier ( <Parameter List> )
	Token* token = *it++;
	if (token == NULL || token->getType() != Token::ID) throw ParserException(token);
	predicate->setValue(token->getValue());

	token = *it++;
	if (token == NULL || token->getType() != Token::LEFT_PAREN) throw ParserException(token);

	ParameterList* parameterList = parseParameterList(it);
	predicate->setParameterList(parameterList);

	token = *it++;
	if (token == NULL || token->getType() != Token::RIGHT_PAREN) throw ParserException(token);

	return predicate;
}

ParameterList* Parser::parseParameterList(std::vector<Token*>::const_iterator& it)
{
	ParameterList* parameters = new ParameterList();

	// <Parameter> | <Parameter> , <ParameterList>
	Parameter* parameter = parseParameter(it);
	parameters->addParameter(parameter);

	if (*it != NULL && (*it)->getType() == Token::COMMA)
	{
		++it;
		ParameterList* tail = new ParameterList();
		tail = parseParameterList(it);
		for (std::vector<Parameter*>::const_iterator it = tail->getList().begin(); it != tail->getList().end(); ++it)
			parameters->addParameter(new Parameter(**it));
		delete tail;
	}
	return parameters;
}

Parameter* Parser::parseParameter(std::vector<Token*>::const_iterator& it)
{
	// STRING | ID
	Token* token = *it++;
	if (token == NULL || (token->getType() != Token::STRING && token->getType() != Token::ID)) throw ParserException(token);

	Parameter* parameter = new Parameter((token->getType() == Token::STRING ? Parameter::STRING : Parameter::ID), token->getValue());

	return parameter;
}

Domain* Parser::parseDomain(const std::vector<Token*>& tokens)
{
	// All Token::STRING values
	Domain* domain = new Domain();

	for (std::vector<Token*>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		if ((*it)->getType() == Token::STRING) domain->addElement((*it)->getValue());
	}

	return domain;
}
