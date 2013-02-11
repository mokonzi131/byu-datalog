/// Michael Landes
/// RDB Manager
/// //////////////

namespace ML_RDBMAN { class Predicate; }

#ifndef ML_RDBMAN_FACT_H
#define ML_RDBMAN_FACT_H

namespace ML_RDBMAN
{

class Fact
{
	public:
		Fact(Predicate* _predicate);
		Fact(const Fact& other);
		virtual ~Fact();

		void toString() const;

	private:
		Predicate* predicate;
};

}

#endif // ML_RDBMAN_FACT_H
