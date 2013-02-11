/// Michael Landes
/// RDB Manager
/// //////////////

#include "predicate.h"

#include <stdio.h>

#include "parameterList.h"

using namespace ML_RDBMAN;

Predicate::Predicate() : value(NULL), parameters(NULL) {}

Predicate::Predicate(const Predicate& other) : value(NULL), parameters(NULL)
{
	value = new std::string(other.value->c_str());
	parameters = new ParameterList(*other.parameters);
}

Predicate::~Predicate()
{
	if (value != NULL) delete value;
	if (parameters != NULL) delete parameters;
}

void Predicate::setValue(const char* _value)
{
	value = new std::string(_value);
}

void Predicate::setParameterList(ParameterList* _parameters)
{
	parameters = _parameters;
}

void Predicate::toString() const
{
	printf("%s(", value->c_str());
	parameters->toString();
	printf(")");
}
