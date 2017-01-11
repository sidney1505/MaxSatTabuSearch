# include "SMetaheuristic.h"

using namespace std;

class TabuSearch : SMetaheuristic {
	TabuList<Solution> tl;
	virtual *vector<Solution> neighbourhood();
	virtual Solution next();
	virtual void updateTabulist(Solution current_solution);
};
