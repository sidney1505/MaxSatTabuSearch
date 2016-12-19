class TabuSearch : SMetaheuristic {
public:
	void run() {
		init();
		do {
			actualiseNeighbourhood();
			actualiseCurrentSolution();
		} while(!break_condition);
	}

private:
	TabuList<Solution> tl;
	virtual *vector<Solution> getNeighbourhood();
	virtual void chooseNext();
}