/// Michael Landes
/// RDB Manager
/// //////////////

#include <vector>

namespace ML_RDBMAN { class Fact; }

#ifndef ML_RDBMAN_FACTLIST_H
#define ML_RDBMAN_FACTLIST_H

namespace ML_RDBMAN
{

class FactList
{
	public:

		FactList();
		FactList(const FactList& other);
		virtual ~FactList();

		void addFact(Fact* f);
		const std::vector<Fact*>& getList();

		void toString() const;

	private:
		std::vector<Fact*> facts;
};

}

#endif // ML_RDBMAN_FACTLIST_H
