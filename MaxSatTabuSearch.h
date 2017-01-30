#include <vector>
#include <stdlib.h>
#include "Neighbourhood.h"
//#include "TabuSearch.h"

using namespace std;

// TODO Template-Paramter mit Vererbung festlegen
class MaxSatTabuSearch/* : TabuSearch */ {
private:
	Tabulist* tabulist;
	Neighbourhood* neighbourhood;
	vector<bool> current_solution;
	vector<bool> best_solution_found;
	int best_score;
	int max_iterations;
	bool augment;

public:
	int eval(vector<bool> solution);
	void init();
	void update_neighbourhood();
	int next();
	// tabusearch
	void run();
	MaxSatTabuSearch(Clauses &clauses, int nbvars, int max_tabu_els, int max_iterations, 
		bool augment);
};
