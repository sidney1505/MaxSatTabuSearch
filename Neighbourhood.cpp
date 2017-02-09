#include "Neighbourhood.h"

using namespace std;

Neighbourhood::Neighbourhood() {

}

Neighbourhood::Neighbourhood(vector<bool> &initial_solution, Clauses &clauses, Tabulist<vector<bool>>* tl) {
	//cout << "create neighbourhood instance!" << endl;
	this->current_occupancy = initial_solution;
	this->clauses = clauses;
	tabulist = tl;
	(*tabulist).emplace(initial_solution);
	int nbvars = initial_solution.size();
	occupancies = new vector<vector<bool>>(nbvars, vector<bool>(nbvars));
	//cout << "A" << endl;
	scores = new vector<int>(nbvars);
	//cout << "AA" << endl;
	clause_credits = new vector<vector<int>>(nbvars, vector<int>(clauses.get_nbclauses()));
	//cout << "AAA" << endl;
	pair<int,vector<int>> initial_eval = initial_evaluation(initial_solution);
	//cout << "AAAA" << endl;
	for(int i = 0; i < initial_solution.size(); i++) {
		//cout << "B" << endl;
		(*occupancies)[i] = initial_solution;
		(*scores)[i] = initial_eval.first;
		(*clause_credits)[i] = initial_eval.second;
		// funktioniert das so mit den Referenzen???
		toggleBit((*occupancies)[i], (*scores)[i], (*clause_credits)[i], i);
		if((*scores)[i] > (*scores)[best_neighbour]) {
			best_neighbour = i;
		}
		//cout << "C" << endl;
	}
	//cout << "neighbourhood instance created!" << endl;
}

bool Neighbourhood::update(int modified_bit) {
	current_occupancy[modified_bit] = !current_occupancy[modified_bit];
	tabulist->emplace(current_occupancy);
	best_neighbour = -1;
	for(int i = 0; i < occupancies->size(); i++) {
		toggleBit((*occupancies)[i], (*scores)[i], (*clause_credits)[i], modified_bit);
		if(!tabulist->contains((*occupancies)[i]) && (best_neighbour == -1 || 
			(*scores)[i] > (*scores)[best_neighbour])) {
			best_neighbour = i;
		}
	}
	return best_neighbour != -1;
}

pair<int,vector<int>> Neighbourhood::initial_evaluation(vector<bool> &sol) {
	//cout << "initial_evaluation!" << endl;
	int score = 0;
	vector<int> clause_credits(clauses.get_nbclauses());
	//cout << "x"<< endl;
	for(int i = 0; i < clauses.get_nbvars(); i++) {
		//cout << "i = " << std::to_string(i) << " of " << std::to_string(clauses.get_nbvars()) << endl;
		for(int j = 0; j < (*clauses.get_vars())[i].size(); j++) {
			//cout << "j = " << std::to_string(j) << " of " << std::to_string((*clauses.get_vars()).size()) << endl;
			if(sol[i] && (*clauses.get_vars())[i][j].second || !sol[i] && !(*clauses.get_vars())[i][j].second) {
				clause_credits[(*clauses.get_vars())[i][j].first]++;
			}
			//cout << "y" << endl;
		}
	}
	//cout << "mid" << endl;
	for(int i = 0; i < clause_credits.size(); i++) {
		if(clause_credits[i] > 0) {
			score++;
		}
	}
	//cout << "initial_evaluation finished!" << endl;
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
	string s = "Best valid Neighbour: ";
	for(int i = 0; i < (*occupancies)[best_neighbour].size(); i++) {
		s += std::to_string((*occupancies)[best_neighbour][i]);
	}
	s += "\n";
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
	s += "Tabulist: ";
	for(auto it = tabulist->get_tabulist()->begin(); it != tabulist->get_tabulist()->end(); it++) {
		for(int i = 0; i < it->first.size(); i++) {
			s += std::to_string(it->first[i]);
		}
		s += "  ";
	}
	return s;
}