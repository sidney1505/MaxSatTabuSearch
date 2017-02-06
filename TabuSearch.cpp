#include "TabuSearch.h"

using namespace std;

template <typename Solution>
void TabuSearch<Solution>::run() {
	//SMetaheuristic<Solution>::init(); // undefined reference???
	int i = 0;
	do {
		if(augment)  {
			cout << "Current Solution is " << sol_to_string(SMetaheuristic<Solution>::current_solution);
			cout << " with score " << to_string(SMetaheuristic<Solution>::best_score) << endl;
			cout << "Best Solution found is " << sol_to_string(SMetaheuristic<Solution>::best_solution_found);
			cout << " with score " << to_string(SMetaheuristic<Solution>::best_score) << endl << endl;
			if(i == 0) {
				cout << "Neighbourhood after " << to_string(i + 1) << " Iteration:" << endl;
			} else {
				cout << "Neighbourhood after " << to_string(i + 1) << " Iterations:" << endl;
			}
		}
		update_neighbourhood();
		next();
		i++;
	} while(i < max_iterations);
	cout << "Best Solution found is " << sol_to_string(SMetaheuristic<Solution>::best_solution_found);
	cout << " with score " << to_string(SMetaheuristic<Solution>::best_score) << endl;
}