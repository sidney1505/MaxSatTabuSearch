# include <fstream>
# include <sstream>
# include <stdlib.h>
# include <iostream>
# include "Reader.h"

using namespace std;

Reader::Reader(string url) {
	this->url = url;
}

// orientiert an Dateiformat DIMACS von http://maxsat.ia.udl.cat/
void Reader::read() {
	ifstream infile(url);
	// orientiert an http://stackoverflow.com/questions/7868936/read-file-line-by-line
	string line;
	istringstream* iss;
	char c;
	do {
		getline(infile, line);
		iss = new istringstream(line); // eventuell synthax-korrektur noetig
		*iss >> c;
	} while(c == 'c');
	string format;
	*iss >> format;
	if(format != "cnf") {
		cout << "wrong format!" << endl;
	}
	*iss >> nbvars >> nbclauses;
	clauses = new vector<vector<pair<int,bool>>>(nbclauses, vector<pair<int,bool>>(0));
	for(int i = 0; i < nbclauses; i++) {
		std::getline(infile, line);
		iss = new std::istringstream(line);
		int var;
		while(*iss >> var && var != 0) {
			(*clauses)[i].push_back(make_pair(abs(var),var > 0));
		}
	}
}

vector<vector<pair<int,bool>>> Reader::get_clauses()  {
	return (*clauses);
}

int Reader::get_nbvars() {
	return nbvars;
}

int Reader::get_nbclauses() {
	return nbclauses;
}

string Reader::to_string() {
	string s = "nbclauses " + std::to_string(nbclauses) + " nbvars " + std::to_string(nbvars) + "\n";
	for(int i = 0; i < nbclauses; i++) {
		for(int j = 0; j < (*clauses)[i].size(); j++) {
			if((*clauses)[i][j].second) {
				s += std::to_string((*clauses)[i][j].first) + " ";
			} else {
				s += std::to_string(-1 * (*clauses)[i][j].first) + " ";
			}
		}
		s += "\n";
	}
	return s;
}