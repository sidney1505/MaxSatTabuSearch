#include <vector>
#include <stdlib.h>
#include "Clauses.h"
#include "Neighbourhood.h"

using namespace std;

// TODO Template-Paramter mit Vererbung festlegen
class MaxSatTabuSearch:TabuSearch {
private:
	Tabulist tabulist;
	Neighbourhood* nh;
	vector<bool> current_solution;
	vector<bool> best_solution_found;
	int best_score;

public:
	void init();
	void neighbourhood();
	int next();
	int eval(vector<bool> solution);
	MaxSatTabuSearch(Clauses &clauses, int nbvars, int max_tabu_els);
};
