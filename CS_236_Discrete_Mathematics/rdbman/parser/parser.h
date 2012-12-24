/// Michael Landes
/// RDB Manager
/// //////////////

#include <exception>
#include <vector>

namespace ML_RDBMAN { class DatalogProgram; class Token; }

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

		Parser();
		virtual ~Parser();

		DatalogProgram* parseDatalogProgram(const std::vector<ML_RDBMAN::Token*>&);

	private:

		void parseSchemeList(std::vector<Token*>::const_iterator& it);
		void parseFactList(std::vector<Token*>::const_iterator& it);
		void parseRuleList(std::vector<Token*>::const_iterator& it);
		void parseQueryList(std::vector<Token*>::const_iterator& it);
};

}

#endif // ML_RDBMAN_PARSER_H
