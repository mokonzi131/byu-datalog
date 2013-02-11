/// Michael Landes
/// RDB Manager
/// //////////////

namespace ML_RDBMAN
{
	class SchemeList;
	class FactList;
	class RuleList;
	class QueryList;
	class Domain;
}

#ifndef ML_RDBMAN_DATALOGPROGRAM_H
#define ML_RDBMAN_DATALOGPROGRAM_H

namespace ML_RDBMAN
{

class DatalogProgram
{
	public:

		DatalogProgram();
		virtual ~DatalogProgram();

		bool setSchemeList(SchemeList*);
		bool setFactList(FactList*);
		bool setRuleList(RuleList*);
		bool setQueryList(QueryList*);
		bool setDomain(Domain*);

		void toString() const;

	private:

		SchemeList* schemeList;
		FactList* factList;
		RuleList* ruleList;
		QueryList* queryList;
		Domain* domain;
};

}

#endif // ML_RDBMAN_DATALOGPROGRAM_H
