/// Michael Landes
/// RDB Manager
/// //////////////

#include <string>

#ifndef ML_RDBMAN_PARAMETER_H
#define ML_RDBMAN_PARAMETER_H

namespace ML_RDBMAN
{

class Parameter
{
	public:
		enum ParameterType
		{
			STRING,
			ID
		};

		Parameter(ParameterType _type, const char* _value);
		Parameter(const Parameter& other);
		virtual ~Parameter();

		void toString() const;

	private:
		ParameterType type;
		std::string* value;
};

}

#endif // ML_RDBMAN_PARAMETER_H
