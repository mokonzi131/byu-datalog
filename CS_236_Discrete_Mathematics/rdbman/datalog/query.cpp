/// Michael Landes
/// RDB Manager
/// //////////////

#include "query.h"

#include <stdio.h>

#include "predicate.h"

using namespace ML_RDBMAN;

Query::Query(Predicate* _predicate) : predicate(_predicate) {}

Query::Query(const Query& other) : predicate(NULL)
{
	predicate = new Predicate(*other.predicate);
}

Query::~Query()
{
	delete predicate;
}

void Query::toString() const
{
	predicate->toString();
	printf("?");
}
