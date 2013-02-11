/// Michael Landes
/// RDB Manager
/// //////////////

namespace ML_RDBMAN { class Predicate; }

#ifndef ML_RDBMAN_QUERY_H
#define ML_RDBMAN_QUERY_H

namespace ML_RDBMAN
{

class Query
{
	public:
		Query(Predicate* _predicate);
		Query(const Query& other);
		virtual ~Query();

		void toString() const;

	private:
		Predicate* predicate;
};

}

#endif // ML_RDBMAN_QUERY_H
