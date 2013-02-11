/// Michael Landes
/// RDB Manager
/// //////////////

#include <vector>

namespace ML_RDBMAN { class Scheme; }

#ifndef ML_RDBMAN_SCHEMELIST_H
#define ML_RDBMAN_SCHEMELIST_H

namespace ML_RDBMAN
{

class SchemeList
{
	public:

		SchemeList();
		SchemeList(const SchemeList& other);
		virtual ~SchemeList();

		void addScheme(Scheme* s);
		const std::vector<Scheme*>& getList();

		void toString() const;

	private:
		std::vector<Scheme*> schemes;
};

}

#endif // ML_RDBMAN_SCHEMELIST_H
