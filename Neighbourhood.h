#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include "Clauses.h"
#include "Tabulist.cpp"

using namespace std;

class Neighbourhood {
private:
	Clauses clauses;
	Tabulist<vector<bool>>* tabulist;
	int best_neighbour = 0;
	vector<vector<bool>>* occupancies;
	vector<int>* scores;
	vector<bool> current_occupancy;
	vector<vector<int>>* clause_credits;
	void toggleBit(vector<bool> &occupancy, int &score,	vector<int> &clause_credits, int bit_to_toggle);

public:
	Neighbourhood();
	Neighbourhood(vector<bool> &initial_solution, Clauses &clauses, Tabulist<vector<bool>>* tl);
	bool update(int modified_bit);
	// -> (belegung, modified_bit, score)
	tuple<vector<bool>,int,int> get_best_neighbour();
	// ((belegung, score, clause_credits), bit_to_toggle) -> 
	// (score, clause_credits)
	pair<int,vector<int>> initial_evaluation(vector<bool> &sol);
	string to_string();
};