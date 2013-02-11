/// Michael Landes
/// RDB Manager
/// //////////////

namespace ML_RDBMAN { class Predicate; }

#ifndef ML_RDBMAN_SCHEME_H
#define ML_RDBMAN_SCHEME_H

namespace ML_RDBMAN
{

class Scheme
{
	public:
		Scheme(Predicate* _predicate);
		Scheme(const Scheme& other);
		virtual ~Scheme();

		void toString() const;

	private:
		Predicate* predicate;
};

}

#endif // ML_RDBMAN_SCHEME_H
