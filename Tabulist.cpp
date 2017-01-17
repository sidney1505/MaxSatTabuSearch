#include <vector>
#include <iostream>
#include "Tabulist.h"

using namespace std;

Tabulist::Tabulist() {

}

Tabulist::Tabulist(int max_elements) {
	this->max_elements = max_elements;
	tabulist = new map<vector<bool>,vector<bool>>();
}

void Tabulist::emplace(vector<bool> solution) {
	if(tabulist->size() != 0) {
		(*tabulist)[last_in] = solution; // Naechstes Element erst jetzt bekannt
	}
	tabulist->emplace(solution, solution);
	last_in = solution;
	if(is_full) {
		vector<bool> buf = (*tabulist)[first_in];
		(*tabulist).erase(first_in);
		first_in = buf;
	} else if(++current_elements == max_elements) {
		is_full = true;
	}
}

bool Tabulist::contains(vector<bool> solution) {
	return tabulist->find(solution) != tabulist->end();
}

string Tabulist::to_string() {
	string s = "tabulist:\n";
	for(auto it = tabulist->begin(); it != tabulist->end(); it++) {
		for(int i = 0; i < it->first.size(); i++) {
			s += std::to_string(it->first[i]);
		}
		s += "\n";
	}
	return s;
}