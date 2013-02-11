/// Michael Landes
/// RDB Manager
/// //////////////

#include "parameter.h"

#include <stdio.h>

using namespace ML_RDBMAN;

Parameter::Parameter(ParameterType _type, const char* _value) : type(_type), value(NULL)
{
	value = new std::string(_value);
}

Parameter::Parameter(const Parameter& other) : value(NULL)
{
	type = other.type;
	value = new std::string(other.value->c_str());
}

Parameter::~Parameter()
{
	delete value;
}

void Parameter::toString() const
{
	switch(type)
	{
		case STRING:
			printf("\'%s\'", value->c_str());
			break;
		case ID:
			printf("%s", value->c_str());
			break;
		default:
			break;
	}
}
