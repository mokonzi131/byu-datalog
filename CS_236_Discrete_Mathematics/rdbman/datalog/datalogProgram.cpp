/// Michael Landes
/// RDB Manager
/// //////////////

#include "datalogProgram.h"

#include <stdlib.h>
#include <stdio.h>

#include "schemeList.h"
#include "factList.h"
#include "ruleList.h"
#include "queryList.h"
#include "domain.h"

using namespace ML_RDBMAN;

DatalogProgram::DatalogProgram() : schemeList(NULL), factList(NULL), ruleList(NULL), queryList(NULL) {}

DatalogProgram::~DatalogProgram()
{
	if (schemeList != NULL) delete schemeList;
	if (factList != NULL) delete factList;
	if (ruleList != NULL) delete ruleList;
	if (queryList != NULL) delete queryList;
}

bool DatalogProgram::setSchemeList(SchemeList* list)
{
	if (schemeList != NULL) return false;
	schemeList = list;
	return true;
}

bool DatalogProgram::setFactList(FactList* list)
{
	if (factList != NULL) return false;
	factList = list;
	return true;
}

bool DatalogProgram::setRuleList(RuleList* list)
{
	if (ruleList != NULL) return false;
	ruleList = list;
	return true;
}

bool DatalogProgram::setQueryList(QueryList* list)
{
	if (queryList != NULL) return false;
	queryList = list;
	return true;
}

bool DatalogProgram::setDomain(Domain* dom)
{
	if (domain != NULL) return false;
	domain = dom;
	return true;
}

void DatalogProgram::toString() const
{
	if (schemeList != NULL) schemeList->toString();
	if (factList != NULL) factList->toString();
	if (ruleList != NULL) ruleList->toString();
	if (queryList != NULL) queryList->toString();
	if (domain != NULL) domain->toString();
}
