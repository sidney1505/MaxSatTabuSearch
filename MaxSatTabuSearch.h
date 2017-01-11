#include <vector>
#include <stdlib.h>
#include "Clauses.h"

using namespace std;

// TODO Template-Paramter mit Vererbung festlegen
class MaxSatTabuSearch:TabuSearch {
private:
	// ACHTUNG innerer vektor beginnt erst bei 1
	Clauses* clauses;
	// Optimierung um Kopieren zu vermeiden
	vector<vector<bool>> current_neighboorhood;
	// letztes gekippte bit
	int last_changed;

public:
	void init();
	//Verwendung um initiale nachbarschaft zu erhalten
	*vector<vector<bool>> getNeighbourhood(vector<bool> &solution);
	// Optimierte Version
	void neighbourhood();	
	int naive_eval(vector<bool> &solution);
	MaxSatTabuSearch(vector<vector<int>> conds, number_of_variables);
};
