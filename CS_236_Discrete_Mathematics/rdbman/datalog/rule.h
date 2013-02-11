/// Michael Landes
/// RDB Manager
/// //////////////

namespace ML_RDBMAN { class Predicate; class PredicateList; }

#ifndef ML_RDBMAN_RULE_H
#define ML_RDBMAN_RULE_H

namespace ML_RDBMAN
{

class Rule
{
	public:
		Rule(Predicate* _predicate, PredicateList* _plist);
		Rule(const Rule& other);
		virtual ~Rule();

		void toString() const;

	private:
		Predicate* predicate;
		PredicateList* plist;
};

}

#endif // ML_RDBMAN_RULE_H
