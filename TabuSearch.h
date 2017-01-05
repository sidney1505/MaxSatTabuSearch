class TabuSearch : SMetaheuristic {

	public: void run();

	private: TabuList<Solution> tl;
	private: virtual *vector<Solution> getNeighbourhood();
	private: virtual void chooseNext();
}
