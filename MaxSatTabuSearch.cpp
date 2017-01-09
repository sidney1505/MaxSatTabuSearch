# include <stdlib.h>
# include <iostream>
# include <vector>
# include <time.h>

using namespace std;

class MaxSatTabuSearch {
private:
	// mapt Variablen zu Klauseln (entweder positiv oder negativ)
	vector<vector<pair<uint,bool>>> conds;
	//TODO Bezug auf Template??
	vector<bool> bestSolutionFound;
	vector<bool> current_solution;
	// Optimierung um Kopieren zu vermeiden
	// Vektor, der Tupel aus Belegung, deren Credits und derem Score enthält
	vector<tuple<vector<bool>,vector<uint>,uint>> current_neighboorhood; // Klasse auslagern
	// letztes gekippte bit, wird 
	int last_changed;

	void init() {
		for(int i = 0; i < current_solution.size(); i++) {
			srand(0); // benötigte libraries?
			bool randbool = rand() & 1; // cast richtig?
			current_solution[i] = randbool;
		}
		bestSolutionFound = current_solution;
		current_neighboorhood = initial_neighbourhood(current_solution);
	}

	//Verwendung um initiale nachbarschaft zu erhalten
	vector<vector<bool>> initial_neighbourhood(vector<bool> &solution) {
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
		// hardcopy vermeiden, daher pointer
		return neighbourhood;
	};

	// nötig um initiale Evaluation zu erhalten
	int initial_evaluation(vector<bool> &solution) {
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

	// Optimierte Version
	void neighbourhood() {
		for(int i = 0; i < solution.size(); i++) {
			current_neighboorhood[i][last_changed] = !current_neighboorhood[i][last_changed];

		}
		// TODO direkte Evaluation der neuen Nachbarschaft
	}

public:
	MaxSatTabuSearch(vector<vector<int>> conds, int number_of_variables) {
		this->conds = conds;
		// TODO Anzahl Klauseln bestimmen
		// number_of_variables = ...
		// sind gegeben im Dimacs-Format!
		vector<bool> bestSolutionFound(number_of_variables);
		vector<bool> current_solution(number_of_variables);
	};
};