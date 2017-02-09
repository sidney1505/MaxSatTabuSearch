#include "TabuSearch.h"

using namespace std;

template <typename Solution>
void TabuSearch<Solution>::run() {
	//SMetaheuristic<Solution>::init(); // undefined reference???
	int i = 0;
	do {
		if(augment)  {
			if(i == 0) {
				cout << "Neighbourhood after " << to_string(i + 1) << " Iteration:" << endl;
			} else {
				cout << "Neighbourhood after " << to_string(i + 1) << " Iterations:" << endl;
			}
		}
		if(!update_neighbourhood()) {
			cout << "Search finished early!" << endl;
			break;
		}
		if(augment)  {
			cout << "Current Solution is " << sol_to_string(SMetaheuristic<Solution>::current_solution);
			cout << " with score " << to_string(SMetaheuristic<Solution>::best_score) << endl;
			cout << "Best Solution found is " << sol_to_string(SMetaheuristic<Solution>::best_solution_found);
			cout << " with score " << to_string(SMetaheuristic<Solution>::best_score) << endl << endl;
		}
		next();
		i++;
	} while(i < max_iterations);
	cout << endl << "Best Solution found is " << sol_to_string(SMetaheuristic<Solution>::best_solution_found);
	cout << " with score " << to_string(SMetaheuristic<Solution>::best_score) << "/";
	cout << std::to_string(SMetaheuristic<Solution>::max_score) << " ~ ";
	cout << std::to_string(100 * ((double) SMetaheuristic<Solution>::best_score) 
		/ ((double) SMetaheuristic<Solution>::max_score)) << "%" << endl;
}