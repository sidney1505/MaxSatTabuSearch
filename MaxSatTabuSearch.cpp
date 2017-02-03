#include "MaxSatTabuSearch.h"

void MaxSatTabuSearch::init() {

}

void MaxSatTabuSearch::update_neighbourhood() {
	auto best_neighbour = neighbourhood->get_best_neighbour();
	neighbourhood->update(get<1>(best_neighbour));
	current_solution = get<0>(best_neighbour);
	if(get<2>(best_neighbour) > best_score) {
		best_score = get<2>(best_neighbour);
		best_solution_found = current_solution;
	}
	if(augment) {
		cout << endl << "Neighbourhood: " << endl << neighbourhood->to_string() << endl << endl;
	}
}

int MaxSatTabuSearch::next() {

}

int MaxSatTabuSearch::eval(vector<bool> solution) {
	return neighbourhood->initial_evaluation(solution).first;
}

MaxSatTabuSearch::MaxSatTabuSearch(Clauses &clauses, int nbvars, int max_tabu_els,
		int max_iterations, bool augment) {
	tabulist = new Tabulist<vector<bool>>(max_tabu_els);
	this->augment = augment;
	this->max_iterations = max_iterations;
	vector<bool> initial_solution(nbvars);
	current_solution = initial_solution;
	best_solution_found = initial_solution;
	neighbourhood = new Neighbourhood(initial_solution, clauses, tabulist);
	best_score = eval(best_solution_found);
	cout << "size " << to_string(current_solution.size()) << endl;
	if(augment) {
		cout << "augment: " << to_string(augment) << endl;
		// cout << endl << "Neighbourhood: " << endl << neighbourhood->to_string() << endl << endl;
	}
}

