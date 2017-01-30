// # include "SMetaheuristic.h"

using namespace std;

// template <typename Solution>
class TabuSearch /*: SMetaheuristic*/ {
public:
	virtual void init();
	virtual void update_neighbourhood();
	virtual int next();
	void run();
};
