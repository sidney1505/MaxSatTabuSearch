#include "MaxSatTabuSearch.h"

void MaxSatTabuSearch::init() {

}

void MaxSatTabuSearch::neighbourhood() {

}

int MaxSatTabuSearch::next() {

}

MaxSatTabuSearch::MaxSatTabuSearch(Clauses &clauses, int nbvars/*, int max_tabu_els*/) {
	vector<bool> initial_solution(nbvars);
	current_solution = initial_solution;
	best_solution_found = initial_solution;
	neighbourhood = new Neighbourhood(initial_solution, clauses);
}
