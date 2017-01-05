//template <typeName Solution> muss das auch in die .h Datei ? 

class SMetaheuristic {

	public: virtual void run();
	public: virtual double eval(Solution);
	public: virtual void init();


	private: Solution bestSolutionFound;
	private: Solution currentSolution;
};
