#include <vector>
#include <stdlib.h>
//Wieso???
#include "TabuSearch.cpp"

using namespace std;

class MaxSatTabuSearch : public TabuSearch<vector<bool>> {
private:
	Neighbourhood* neighbourhood;
public:
	string sol_to_string(vector<bool> solution);
	void init();
	bool update_neighbourhood();
	int next();
	int eval(std::vector<bool> solution);
	MaxSatTabuSearch(Clauses &clauses, int nbvars, int max_tabu_els, int max_iterations, 
		bool augment);
};
