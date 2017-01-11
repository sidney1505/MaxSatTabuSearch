template <typeName Solution> // template comparable
class SMetaheuristic {
	Solution bestSolutionFound;
	Solution currentSolution;
	
public:
	virtual void run();
	virtual double eval(Solution);
	virtual void init();
};