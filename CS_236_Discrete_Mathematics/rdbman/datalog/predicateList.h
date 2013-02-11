/// Michael Landes
/// RDB Manager
/// //////////////

#include <string>
#include <vector>

namespace ML_RDBMAN { class Predicate; }

#ifndef ML_RDBMAN_PREDICATELIST_H
#define ML_RDBMAN_PREDICATELIST_H

namespace ML_RDBMAN
{

class PredicateList
{
	public:
		PredicateList();
		PredicateList(const PredicateList& other);
		virtual ~PredicateList();

		void addPredicate(Predicate* p);
		const std::vector<Predicate*>& getList();

		void toString() const;

	private:
		std::vector<Predicate*> predicates;
};

}

#endif // ML_RDBMAN_PREDICATELIST_H
