/// Michael Landes
/// RDB Manager
/// //////////////

#include <exception>
#include <vector>

namespace ML_RDBMAN
{
	class DatalogProgram;
	class SchemeList;
	class FactList;
	class RuleList;
	class QueryList;
	class Scheme;
	class Fact;
	class Rule;
	class Query;
	class PredicateList;
	class Predicate;
	class ParameterList;
	class Parameter;
	class Domain;
	class Token;
}

#ifndef ML_RDBMAN_PARSER_H
#define ML_RDBMAN_PARSER_H

namespace ML_RDBMAN
{

class ParserException : public std::exception
{
	public:

		ParserException(Token* _token) : token(_token) {}
		virtual const char* what() const throw() { return "ML_RDBMAN::Parser Error!"; }
		Token* getToken() { return token; }

	private:

		Token* token;
};

class Parser
{
	public:

		static DatalogProgram* parseDatalogProgram(const std::vector<ML_RDBMAN::Token*>&);

	private:

		static SchemeList* parseSchemeList(std::vector<Token*>::const_iterator& it);
		static Scheme* parseScheme(std::vector<Token*>::const_iterator& it);

		static FactList* parseFactList(std::vector<Token*>::const_iterator& it);
		static Fact* parseFact(std::vector<Token*>::const_iterator& it);

		static RuleList* parseRuleList(std::vector<Token*>::const_iterator& it);
		static Rule* parseRule(std::vector<Token*>::const_iterator& it);

		static QueryList* parseQueryList(std::vector<Token*>::const_iterator& it);
		static Query* parseQuery(std::vector<Token*>::const_iterator& it);

		static PredicateList* parsePredicateList(std::vector<Token*>::const_iterator& it);
		static Predicate* parsePredicate(std::vector<Token*>::const_iterator& it);

		static ParameterList* parseParameterList(std::vector<Token*>::const_iterator& it);
		static Parameter* parseParameter(std::vector<Token*>::const_iterator& it);

		static Domain* parseDomain(const std::vector<ML_RDBMAN::Token*>& tokens);
};

}

#endif // ML_RDBMAN_PARSER_H
