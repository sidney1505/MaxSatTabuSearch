#include "TabuSearch.h"

using namespace std;

template <typename Solution>
void TabuSearch<Solution>::run() {
	//SMetaheuristic<Solution>::init(); // undefined reference???
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
	/*for(int i = 0; i < best_solution_found.size(); i++) {
		cout << to_string(best_solution_found[i]);
	}*/
	cout << " with score " << to_string(SMetaheuristic<Solution>::best_score) << endl;
}