#include <stdlib.h>
#include "TabuSearch.h"

using namepspace std;

void TabuSearch::run() {
	init();
	uint i = 0;
	do {
		neighbourhood();
		current_solution = next();
		updateTabulist(current_solution);
		i++;
	} while(i < 1000000);
}