/// Michael Landes
/// RDB Manager
/// //////////////

#include "ruleList.h"

#include <stdio.h>

#include "rule.h"

using namespace ML_RDBMAN;

RuleList::RuleList() {}

RuleList::RuleList(const RuleList& other)
{
	for (std::vector<Rule*>::const_iterator it = other.rules.begin(); it != other.rules.end(); ++it)
		rules.push_back(new Rule(**it));
}

RuleList::~RuleList()
{
	for (std::vector<Rule*>::const_iterator it = rules.begin(); it != rules.end(); ++it)
		delete *it;
	rules.clear();
}

void RuleList::addRule(Rule* r)
{
	rules.push_back(r);
}

const std::vector<Rule*>& RuleList::getList()
{
	return rules;
}

void RuleList::toString() const
{
	printf("Rules(%ld):\n", rules.size());
	for (std::vector<Rule*>::const_iterator it = rules.begin(); it != rules.end(); ++it)
	{
		printf("  ");
		(*it)->toString();
		printf("\n");
	}
}
