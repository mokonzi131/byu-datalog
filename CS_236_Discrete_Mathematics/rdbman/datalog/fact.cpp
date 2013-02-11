/// Michael Landes
/// RDB Manager
/// //////////////

#include "fact.h"

#include <stdio.h>

#include "predicate.h"

using namespace ML_RDBMAN;

Fact::Fact(Predicate* _predicate) : predicate(_predicate) {}

Fact::Fact(const Fact& other) : predicate(NULL)
{
	predicate = new Predicate(*other.predicate);
}

Fact::~Fact()
{
	delete predicate;
}

void Fact::toString() const
{
	predicate->toString();
	printf(".");
}
