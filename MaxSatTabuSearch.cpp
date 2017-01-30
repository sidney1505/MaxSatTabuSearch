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

// tabusearch
void MaxSatTabuSearch::run() {
	init();
	int i = 0;
	do {
		if(augment)  {
			cout << "iteration " << to_string(i) << endl;
		}
		update_neighbourhood();
		next();
		i++;
	} while(i < max_iterations);
	cout << "Best Solution found is ";
	for(int i = 0; i < best_solution_found.size(); i++) {
		cout << to_string(best_solution_found[i]);
	}
	cout << " with score " << to_string(best_score) << endl;
}

MaxSatTabuSearch::MaxSatTabuSearch(Clauses &clauses, int nbvars, int max_tabu_els,
		int max_iterations, bool augment) {
	this->augment = augment;
	this->max_iterations = max_iterations;
	tabulist = new Tabulist(max_tabu_els);
	vector<bool> initial_solution(nbvars); // optimimierbar
	current_solution = initial_solution;
	best_solution_found = initial_solution;
	neighbourhood = new Neighbourhood(initial_solution, clauses, tabulist);
	best_score = eval(best_solution_found);
	if(augment) {
		cout << "aument: " << to_string(augment) << endl;
		cout << endl << "Neighbourhood: " << endl << neighbourhood->to_string() << endl << endl;
	}
}

