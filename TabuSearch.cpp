class TabuSearch : SMetaheuristic {
public:
	void run() {
		for(uint_64 i = 0; i < MAX_ITERATIONS; i++) {
			chooseNext();
		}
	}
private:
	TabuList<Solution> tl;
	virtual vector<Solution> getNeighbourhood();
	virtual void chooseNext();
}