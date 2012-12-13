/// Michael Landes
/// RDB Manager
/// //////////////

#include "lexical.h"

#include <stddef.h>
#include <vector>

using namespace ML_RDBMAN;

LexicalAnalyzer::LexicalAnalyzer() {}

LexicalAnalyzer::~LexicalAnalyzer() {}

void
LexicalAnalyzer::process(char* filename)
{
	throw LexicalException(-1);
//	open file for parsing as a stream

//	loop through contents

//	create tokens and add to list
}
