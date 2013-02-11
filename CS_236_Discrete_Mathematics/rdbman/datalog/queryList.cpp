/// Michael Landes
/// RDB Manager
/// //////////////

#include "queryList.h"

#include <stdio.h>

#include "query.h"

using namespace ML_RDBMAN;

QueryList::QueryList() {}

QueryList::QueryList(const QueryList& other)
{
	for (std::vector<Query*>::const_iterator it = other.queries.begin(); it != other.queries.end(); ++it)
		queries.push_back(new Query(**it));
}

QueryList::~QueryList()
{
	for (std::vector<Query*>::const_iterator it = queries.begin(); it != queries.end(); ++it)
		delete *it;
	queries.clear();
}

void QueryList::addQuery(Query* q)
{
	queries.push_back(q);
}

const std::vector<Query*>& QueryList::getList()
{
	return queries;
}

void QueryList::toString() const
{
	printf("Queries(%ld):\n", queries.size());
	for (std::vector<Query*>::const_iterator it = queries.begin(); it != queries.end(); ++it)
	{
		printf("  ");
		(*it)->toString();
		printf("\n");
	}
}
