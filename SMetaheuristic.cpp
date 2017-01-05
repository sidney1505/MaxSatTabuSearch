template <typeName Solution> // template comparable
class SMetaheuristic {
public:
	virtual void run();
	virtual double eval(Solution);
	virtual void init();

private:
	Solution bestSolutionFound;
	Solution currentSolution;
};