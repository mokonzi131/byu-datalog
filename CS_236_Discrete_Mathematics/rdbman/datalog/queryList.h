/// Michael Landes
/// RDB Manager
/// //////////////

#include <vector>

namespace ML_RDBMAN { class Query; }

#ifndef ML_RDBMAN_QUERYLIST_H
#define ML_RDBMAN_QUERYLIST_H

namespace ML_RDBMAN
{

class QueryList
{
	public:

		QueryList();
		QueryList(const QueryList& other);
		virtual ~QueryList();

		void addQuery(Query* q);
		const std::vector<Query*>& getList();

		void toString() const;

	private:
		std::vector<Query*> queries;
};

}

#endif // ML_RDBMAN_QUERYLIST_H
