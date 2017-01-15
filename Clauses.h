#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Clauses {
private:
	// mapt Variablen zu Klauseln
	vector<vector<pair<int,bool>>>* vars;
	int nbvars, nbclauses;

public:
	// http://stackoverflow.com/questions/26076997/in-constructor-candidate-expects-1-argument-0-provided
	Clauses(); // erscheint mir sehr seltsam! Rechnen mit potentiellen Fehlern!
	Clauses(vector<vector<pair<int,bool>>> clauses, int nbvars, int nbclauses);
	string to_string();
	int get_nbclauses();
	int get_nbvars();
	vector<vector<pair<int,bool>>>* get_vars();
};