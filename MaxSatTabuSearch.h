#include <vector>
#include <stdlib.h>
#include "Clauses.h"
#include "Neighbourhood.h"

using namespace std;

// TODO Template-Paramter mit Vererbung festlegen
class MaxSatTabuSearch:TabuSearch {
private:
	Neighbourhood* neighbourhood;
	vector<bool> current_solution;
	vector<bool> best_solution_found;

public:
	void init();
	void neighbourhood();
	int next();
	MaxSatTabuSearch(vector<vector<int>> conds, number_of_variables);
};
