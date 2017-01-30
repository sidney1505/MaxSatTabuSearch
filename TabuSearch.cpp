#include "TabuSearch.h"

using namespace std;

void TabuSearch::run() {
	init();
	int i = 0;
	do {
		update_neighbourhood();
		next();
		i++;
	} while(i < 1000);
}