/// Michael Landes
/// RDB Manager
/// //////////////

#include "schemeList.h"

#include <stdio.h>

#include "scheme.h"

using namespace ML_RDBMAN;

SchemeList::SchemeList() {}

SchemeList::SchemeList(const SchemeList& other)
{
	for (std::vector<Scheme*>::const_iterator it = other.schemes.begin(); it != other.schemes.end(); ++it)
		schemes.push_back(new Scheme(**it));
}

SchemeList::~SchemeList()
{
	for (std::vector<Scheme*>::const_iterator it = schemes.begin(); it != schemes.end(); ++it)
		delete *it;
	schemes.clear();
}

void SchemeList::addScheme(Scheme* s)
{
	schemes.push_back(s);
}

const std::vector<Scheme*>& SchemeList::getList()
{
	return schemes;
}

void SchemeList::toString() const
{
	printf("Schemes(%ld):\n", schemes.size());
	for (std::vector<Scheme*>::const_iterator it = schemes.begin(); it != schemes.end(); ++it)
	{
		printf("  ");
		(*it)->toString();
		printf("\n");
	}
}
