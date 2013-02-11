/// Michael Landes
/// RDB Manager
/// //////////////

#include "rule.h"

#include <stdio.h>

#include "predicate.h"
#include "predicateList.h"

using namespace ML_RDBMAN;

Rule::Rule(Predicate* _predicate, PredicateList* _plist) : predicate(_predicate), plist(_plist) {}

Rule::Rule(const Rule& other) : predicate(NULL), plist(NULL)
{
	predicate = new Predicate(*other.predicate);
	plist = new PredicateList(*other.plist);
}

Rule::~Rule()
{
	delete predicate;
	delete plist;
}

void Rule::toString() const
{
	predicate->toString();
	printf(" :- ");
	plist->toString();
	printf(".");
}
