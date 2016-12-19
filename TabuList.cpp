class TabuList {
private:
	uint_64 max_elements;
	map<Solution,Solution> tabulist;
	Solution last_in; //pointer verwenden

public:
	TabuList(uint_64 max_els) {
		max_elements = max_els;
	}

	void emplace(Solution solution) {

	}

	bool contains(Solution solution) {

	}
}