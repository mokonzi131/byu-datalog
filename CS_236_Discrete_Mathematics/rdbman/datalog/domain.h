/// Michael Landes
/// RDB Manager
/// //////////////

#include <set>
#include <string>

#ifndef ML_RDBMAN_DOMAIN_H
#define ML_RDBMAN_DOMAIN_H

namespace ML_RDBMAN
{

class Domain
{
	public:
		Domain();
		Domain(const Domain& other);
		virtual ~Domain();

		void addElement(const char* element);

		void toString() const;

	private:
		std::set<std::string> elements;
};

}

#endif // ML_RDBMAN_DOMAIN_H
