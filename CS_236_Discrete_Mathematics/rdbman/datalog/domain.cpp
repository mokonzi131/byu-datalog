/// Michael Landes
/// RDB Manager
/// //////////////

#include "domain.h"

#include <stdio.h>

using namespace ML_RDBMAN;

Domain::Domain() {}

Domain::Domain(const Domain& other)
{
	for (std::set<std::string>::const_iterator it = other.elements.begin(); it != other.elements.end(); ++it)
		elements.insert(std::string((*it).c_str()));
}

Domain::~Domain() {}

void Domain::addElement(const char* element)
{
	elements.insert(std::string(element));
}

void Domain::toString() const
{
	printf("Domain(%ld):\n", elements.size());
	for (std::set<std::string>::const_iterator it = elements.begin(); it != elements.end(); ++it)
		printf("  \'%s\'\n", (*it).c_str());
}
