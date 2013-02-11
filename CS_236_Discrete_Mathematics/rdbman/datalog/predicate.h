/// Michael Landes
/// RDB Manager
/// //////////////

#include <string>

namespace ML_RDBMAN{ class ParameterList; }

#ifndef ML_RDBMAN_PREDICATE_H
#define ML_RDBMAN_PREDICATE_H

namespace ML_RDBMAN
{

class Predicate
{
	public:

		Predicate();
		Predicate(const Predicate& other);
		virtual ~Predicate();

		void setValue(const char* _value);
		void setParameterList(ParameterList* _parameters);

		void toString() const;

	private:
		std::string* value;
		ParameterList* parameters;
};

}

#endif // ML_RDBMAN_PREDICATE_H
