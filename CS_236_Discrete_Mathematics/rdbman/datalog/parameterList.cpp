/// Michael Landes
/// RDB Manager
/// //////////////

#include "parameterList.h"

#include <stdio.h>

#include "parameter.h"

using namespace ML_RDBMAN;

ParameterList::ParameterList() {}

ParameterList::ParameterList(const ParameterList& other)
{
	for (std::vector<Parameter*>::const_iterator it = other.parameters.begin(); it != other.parameters.end(); ++it)
		parameters.push_back(new Parameter(**it));
}

ParameterList::~ParameterList()
{
	for (std::vector<Parameter*>::const_iterator it = parameters.begin(); it != parameters.end(); ++it)
		delete *it;
	parameters.clear();
}

void ParameterList::addParameter(Parameter* p)
{
	parameters.push_back(p);
}

const std::vector<Parameter*>& ParameterList::getList()
{
	return parameters;
}

void ParameterList::toString() const
{
	for (std::vector<Parameter*>::const_iterator it = parameters.begin(); it != parameters.end(); ++it)
	{
		if (it != parameters.begin()) printf(",");
		(*it)->toString();
	}
}
