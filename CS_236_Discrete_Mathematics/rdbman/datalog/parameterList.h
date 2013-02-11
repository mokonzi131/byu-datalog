/// Michael Landes
/// RDB Manager
/// //////////////

#include <string>
#include <vector>

namespace ML_RDBMAN { class Parameter; }

#ifndef ML_RDBMAN_PARAMETERLIST_H
#define ML_RDBMAN_PARAMETERLIST_H

namespace ML_RDBMAN
{

class ParameterList
{
	public:
		ParameterList();
		ParameterList(const ParameterList& other);
		virtual ~ParameterList();

		void addParameter(Parameter* p);
		const std::vector<Parameter*>& getList();

		void toString() const;

	private:
		std::vector<Parameter*> parameters;
};

}

#endif // ML_RDBMAN_PARAMETERLIST_H
