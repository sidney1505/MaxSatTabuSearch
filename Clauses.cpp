#include "Clauses.h"

using namespace std;

Clauses::Clauses() {
	
}

Clauses::Clauses(vector<vector<pair<int,bool>>> clauses, int nbvars, int nbclauses) {
	this->nbvars = nbvars;
	this->nbclauses = nbclauses;
	vars = new vector<vector<pair<int,bool>>>(nbvars, vector<pair<int,bool>>(0));
	for(int i = 0; i < nbclauses; i++) {
		for(int j = 0; j < clauses[i].size(); j++) {
			pair<int,bool> p = clauses[i][j];
			(*vars)[p.first - 1].push_back(make_pair(i, p.second)); // TODO potentielle Fehlerquelle!
		}
	}
}

string Clauses::to_string() {
	string s = "nbclauses " + std::to_string(nbclauses) + " nbvars " + std::to_string(nbvars) + "\n";
	for(int i = 0; i < nbvars; i++) {
		for(int j = 0; j < (*vars)[i].size(); j++) {
			if((*vars)[i][j].second) {
				s += std::to_string((*vars)[i][j].first + 1) + " ";
			} else {
				s += std::to_string(-1 * ((*vars)[i][j].first + 1)) + " ";
			}
		}
		s += "\n";
	}
	return s;
}

int Clauses::get_nbclauses() {
	return nbclauses;
}

int Clauses::get_nbvars() {
	return nbvars;
}

vector<vector<pair<int,bool>>>* Clauses::get_vars() {
	return vars;
}