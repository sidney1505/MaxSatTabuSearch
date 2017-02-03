// # include "SMetaheuristic.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
// geht das nicht weniger dreckig?
#include "Neighbourhood.h"


using namespace std;

template <typename Solution>
class TabuSearch /*: public SMetaheuristic*/ {
protected:
	Tabulist<Solution>* tabulist;
	Solution current_solution;
	Solution best_solution_found;
	int max_iterations;
	bool augment;
	int best_score;
public:
	// http://stackoverflow.com/questions/23255256/undefined-reference-to-vtable-for-class-constructor
	virtual void init() = 0;
	virtual void update_neighbourhood() = 0;
	virtual int next() = 0;
	void run();
};
