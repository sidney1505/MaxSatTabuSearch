// # include "SMetaheuristic.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
// geht das nicht weniger dreckig?
#include "Neighbourhood.h"
#include "SMetaheuristic.h"


using namespace std;

template <typename Solution>
class TabuSearch : public SMetaheuristic<Solution> {
protected:
	Tabulist<Solution>* tabulist;
	int max_iterations;
	bool augment;
public:
	// http://stackoverflow.com/questions/23255256/undefined-reference-to-vtable-for-class-constructor
	virtual void update_neighbourhood() = 0;
	virtual int next() = 0;
	void run();
};
