#include <vector>
#include <stdlib.h>

using namespace std;

class Neighbourhood {
private:
	Clauses* clauses;
	int best_neighbour = 0;
	vector<vector<bool>, int, vector<int>>* occupancies;
	vector<int>* scores;
	vector<vector<int>>* clause_credits;

public:
	Neighbourhood(vector<bool> initial_solution);
	void update(int modified_bit);
	// -> (belegung, modified_bit, score)
	tuple<vector<bool>,int,int> get_best_neighbour();
	// ((belegung, score, clause_credits), bit_to_toggle) -> 
	void toggleBit(vector<bool> &occupancy, int &score,	vector<int> &clause_credits, int bit_to_toggle);
	// (score, clause_credits)
	pair<int,vector<int>> initial_evaluation(vector<bool> sol);
}