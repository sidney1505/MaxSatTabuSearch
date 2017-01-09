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
	Clauses(vector<vector<pair<int,bool>>> clauses, int nbvars, int nbclauses);
	string to_string();
};