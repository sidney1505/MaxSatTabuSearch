#include "TabuSearch.h"

using namepspace std;

void TabuSearch::run() {
	init();
	int i = 0;
	do {
		neighbourhood();
		next();
		i++;
	} while(i < 1000);
}