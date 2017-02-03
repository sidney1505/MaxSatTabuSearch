#include <vector>
#include <stdlib.h>
//Wieso???
#include "TabuSearch.cpp"

using namespace std;

class MaxSatTabuSearch : public TabuSearch<vector<bool>> {
private:
	Neighbourhood* neighbourhood;
public:
	int eval(vector<bool> solution);
	void init();
	void update_neighbourhood();
	int next();
	MaxSatTabuSearch(Clauses &clauses, int nbvars, int max_tabu_els, int max_iterations, 
		bool augment);
};
