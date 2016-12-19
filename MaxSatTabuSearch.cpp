# include <stdlib.h>

class MaxSatTabuSearch {
private:
	// innerer vektor beginnt erst bei 1
	vector<vector<pair<int,bool>>> conds;
	vector<bool> bestSolutionFound; //TODO Bezug auf Template??
	vector<bool> current_solution;
	// Optimierung um Kopieren zu vermeiden
	vector<vector<bool>> current_neighboorhood;
	// letztes gekippte bit
	int last_changed;

	void init() {
		for(i = 0; i < current_solution.size(); i++) {
			srand(); // benötigte libraries?
			bool randbool = rand() & 1; // cast richtig?
			current_solution[i] = randbool;
		}
		bestSolutionFound = current_solution;
		current_neighboorhood = *getNeighbourhood()
	}

	//Verwendung um initiale nachbarschaft zu erhalten
	*vector<vector<bool>> getNeighbourhood(vector<bool> &solution) {
		// klassenvariablen oder lokale variablen???
		vector<vector<bool>> neighbourhood(solution.size(), vector<bool>(solution.size()));
		vector<bool> it = *solution;
		// wiederholte if-abfrge in schleife vermeiden!
		it[0] = !it[0];
		neighbourhood[0] = it;
		for(int i = 1; i < *solution.size(); i++) {
			// doppelte hard-copy vermeiden!
			it[i-1] = !it[i-1];
			it[i] = !it[i];
			neighbourhood[i] = it[i];
		}
		// hardcopy vermeiden, daher link
		return &neighbourhood;
	}

	// Optimierte Version
	void actualiseNeighbourhood() {
		for(int i = 0; i < solution.size(); i++) {
			current_neighboorhood[i][i] = !current_neighboorhood[i][i];
			current_neighboorhood[i][last_changed] = !current_neighboorhood[i][last_changed];			
		}
		current_neighboorhood[last_changed][last_changed] = !current_neighboorhood[last_changed][last_changed];
		// TODO direkte Evaluation der neuen Nachbarschaft
	}

	//
	int naive_eval(vector<bool> &solution) {
		int score = 0;
		for(int i = 0; i < conds.size(); i++) {
			for(int j = 1; j < conds[i].size(); j++) {
				if(*solution[fst(conds[i][j])] && snd(conds[i][j]) || !*solution[fst(conds[i][j])] && !snd(conds[i][j])) {
					score++;
					break;
				}
			}
		}
		return score;
	}

public:
	MaxSatTabuSearch(vector<vector<int>> conds, number_of_variables) {
		this->conds = conds;
		// TODO Anzahl Klauseln bestimmen
		// number_of_variables = ...
		// sind gegeben im Dimacs-Format!
		vector<bool> bestSolutionFound(number_of_variables);
		vector<bool> current_solution(number_of_variables);
	}
}