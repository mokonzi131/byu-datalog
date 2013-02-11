/// Michael Landes
/// RDB Manager
/// //////////////

#include "factList.h"

#include <stdio.h>

#include "fact.h"

using namespace ML_RDBMAN;

FactList::FactList() {}

FactList::FactList(const FactList& other)
{
	for (std::vector<Fact*>::const_iterator it = other.facts.begin(); it != other.facts.end(); ++it)
		facts.push_back(new Fact(**it));
}

FactList::~FactList()
{
	for (std::vector<Fact*>::const_iterator it = facts.begin(); it != facts.end(); ++it)
		delete *it;
	facts.clear();
}

void FactList::addFact(Fact* f)
{
	facts.push_back(f);
}

const std::vector<Fact*>& FactList::getList()
{
	return facts;
}

void FactList::toString() const
{
	printf("Facts(%ld):\n", facts.size());
	for (std::vector<Fact*>::const_iterator it = facts.begin(); it != facts.end(); ++it)
	{
		printf("  ");
		(*it)->toString();
		printf("\n");
	}
}
