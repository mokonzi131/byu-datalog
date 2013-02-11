/// Michael Landes
/// RDB Manager
/// //////////////

#include "predicateList.h"

#include <stdio.h>

#include "predicate.h"

using namespace ML_RDBMAN;

PredicateList::PredicateList() {}

PredicateList::PredicateList(const PredicateList& other)
{
	for (std::vector<Predicate*>::const_iterator it = other.predicates.begin(); it != other.predicates.end(); ++it)
		predicates.push_back(new Predicate(**it));
}

PredicateList::~PredicateList()
{
	for (std::vector<Predicate*>::const_iterator it = predicates.begin(); it != predicates.end(); ++it)
		delete *it;
	predicates.clear();
}

void PredicateList::addPredicate(Predicate* p)
{
	predicates.push_back(p);
}

const std::vector<Predicate*>& PredicateList::getList()
{
	return predicates;
}

void PredicateList::toString() const
{
	for (std::vector<Predicate*>::const_iterator it = predicates.begin(); it != predicates.end(); ++it)
	{
		if (it != predicates.begin()) printf(",");
		(*it)->toString();
	}
}
