template <typename Solution> // template comparable
class SMetaheuristic {
public:
	Solution current_solution;
	Solution best_solution_found;
	int best_score;
	int max_score;
	virtual void run() = 0;
	virtual int eval(Solution solution) = 0;
	virtual void init() = 0;
};