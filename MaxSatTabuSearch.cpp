#include "MaxSatTabuSearch.h"

void MaxSatTabuSearch::init() {

}

void MaxSatTabuSearch::neighbourhood() {
	auto best_neighbour = nh.get_best_neighbour();
	nh.update(get<1>(best_neighbour));
	current_solution = get<0>(best_neighbour);
	if(get<2>(best_neighbour) > best_score) {
		best_score = get<2>(best_neighbour);
		best_solution_found = current_solution;
	}
	cout << endl << "Neighbourhood: " << endl << nh.to_string() << endl << endl;
}

int MaxSatTabuSearch::next() {

}

int MaxSatTabuSearch::eval(vector<bool> solution) {
	return nh->initial_solution(solution).first;
}

MaxSatTabuSearch::MaxSatTabuSearch(Clauses &clauses, int nbvars, int max_tabu_els) {
	tabulist = new Tabulist(1000);
	vector<bool> initial_solution(nbvars); // optimimierbar
	current_solution = initial_solution;
	best_solution_found = initial_solution;
	neighbourhood = new Neighbourhood(initial_solution, clauses);
	best_score = neighbourhood->eval(best_solution_found);
	cout << endl << "Neighbourhood: " << endl << nh.to_string() << endl << endl;
}
