#include "Neighbourhood.h"

using namespace std;

Neighbourhood::Neighbourhood() {

}

Neighbourhood::Neighbourhood(vector<bool> &initial_solution, Clauses &clauses, Tabulist<vector<bool>>* tl) {
	this->current_occupancy = initial_solution;
	this->clauses = clauses;
	tabulist = tl;
	(*tabulist).emplace(initial_solution);
	int nbvars = initial_solution.size();
	occupancies = new vector<vector<bool>>(nbvars, vector<bool>(nbvars));
	scores = new vector<int>(nbvars);
	clause_credits = new vector<vector<int>>(nbvars, vector<int>(clauses.get_nbclauses()));
	pair<int,vector<int>> initial_eval = initial_evaluation(initial_solution);
	for(int i = 0; i < initial_solution.size(); i++) {
		(*occupancies)[i] = initial_solution;
		(*scores)[i] = initial_eval.first;
		(*clause_credits)[i] = initial_eval.second;
		// funktioniert das so mit den Referenzen???
		toggleBit((*occupancies)[i], (*scores)[i], (*clause_credits)[i], i);
		if((*scores)[i] > (*scores)[best_neighbour]) {
			best_neighbour = i;
		}
	}
}

void Neighbourhood::update(int modified_bit) {
	current_occupancy[modified_bit] = !current_occupancy[modified_bit];
	tabulist->emplace(current_occupancy);
	// TODO Tabuliste beachten!!!
	best_neighbour = 0;
	for(int i = 0; i < occupancies->size(); i++) {
		// cout << std::to_string((*scores)[i]) << " " << std::to_string((*scores)[best_neighbour]) << endl;
		toggleBit((*occupancies)[i], (*scores)[i], (*clause_credits)[i], modified_bit);
		if((*scores)[i] > (*scores)[best_neighbour] && !tabulist->contains((*occupancies)[i])) {
			best_neighbour = i;
		}
	}
}

pair<int,vector<int>> Neighbourhood::initial_evaluation(vector<bool> &sol) {
	int score = 0;
	vector<int> clause_credits(clauses.get_nbclauses());
	for(int i = 0; i < clauses.get_nbvars(); i++) {
		for(int j = 0; j < (*clauses.get_vars()).size(); j++) {
			if(sol[i] && (*clauses.get_vars())[i][j].second || !sol[i] && !(*clauses.get_vars())[i][j].second) {
				clause_credits[(*clauses.get_vars())[i][j].first]++;
			}
		}
	}
	for(int i = 0; i < clause_credits.size(); i++) {
		if(clause_credits[i] > 0) {
			score++;
		}
	}
	return make_pair(score,clause_credits);
}

void Neighbourhood::toggleBit(vector<bool> &occupancy, int &score, vector<int> &clause_credits, 
	int bit_to_toggle) {
	occupancy[bit_to_toggle] = !occupancy[bit_to_toggle];
	// TODO potentielle Fehler untersuchen!!!
	for(int i = 0; i < (*clauses.get_vars())[bit_to_toggle].size(); i++) {
		if((*clauses.get_vars())[bit_to_toggle][i].second && occupancy[bit_to_toggle]
			|| !(*clauses.get_vars())[bit_to_toggle][i].second && !occupancy[bit_to_toggle]) {
			clause_credits[(*clauses.get_vars())[bit_to_toggle][i].first]++;
			if(clause_credits[(*clauses.get_vars())[bit_to_toggle][i].first] == 1) {
				score++;
			}
		} else {
			clause_credits[(*clauses.get_vars())[bit_to_toggle][i].first]--;
			if(clause_credits[(*clauses.get_vars())[bit_to_toggle][i].first] == 0) {
				score--;
			}
		}
	}
}

tuple<vector<bool>,int,int> Neighbourhood::get_best_neighbour() {
	return make_tuple((*occupancies)[best_neighbour],best_neighbour,(*scores)[best_neighbour]);
}

string Neighbourhood::to_string() {
	string s = "Best valid Neighbour: " + std::to_string(best_neighbour) + "\n";
	for(int i = 0; i < (*occupancies).size(); i++) {
		s += std::to_string(i) + " ";
		for(int j = 0; j < (*occupancies)[i].size(); j++) {
			s += std::to_string((*occupancies)[i][j]);
		}
		s += " " + std::to_string((*scores)[i]) + " (";
		for(int j = 0; j < (*clause_credits)[i].size(); j++) {
			s += std::to_string((*clause_credits)[i][j]);
			if(j != (*clause_credits)[i].size() - 1) {
				s += ",";
			}
		}
		s += ")\n";
	}
	// s += (*tabulist).to_string();
	return s;
}