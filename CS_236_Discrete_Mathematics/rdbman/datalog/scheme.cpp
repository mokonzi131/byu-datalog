/// Michael Landes
/// RDB Manager
/// //////////////

#include "scheme.h"

#include <stdio.h>

#include "predicate.h"

using namespace ML_RDBMAN;

Scheme::Scheme(Predicate* _predicate) : predicate(_predicate) {}

Scheme::Scheme(const Scheme& other) : predicate(NULL)
{
	predicate = new Predicate(*other.predicate);
}

Scheme::~Scheme()
{
	delete predicate;
}

void Scheme::toString() const
{
	predicate->toString();
}
