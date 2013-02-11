/// Michael Landes
/// RDB Manager
/// //////////////

#include <vector>

namespace ML_RDBMAN { class Rule; }

#ifndef ML_RDBMAN_RULELIST_H
#define ML_RDBMAN_RULELIST_H

namespace ML_RDBMAN
{

class RuleList
{
	public:
		RuleList();
		RuleList(const RuleList& other);
		virtual ~RuleList();

		void addRule(Rule* r);
		const std::vector<Rule*>& getList();

		void toString() const;

	private:
		std::vector<Rule*> rules;
};

}

#endif // ML_RDBMAN_RULELIST_H
