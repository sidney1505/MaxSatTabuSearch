class TabuList {
private:
	uint max_elements;
	uint current_elements;
	bool is_full = false;
	// Jede Solution ist zu der naechsten Solution gemappt
	map<Solution,Solution> tabulist;
	Solution last_in; // map pointer verwenden
	Solution first_in;

public:
	TabuList(uint max_elements) {
		this->max_elements = max_elements;
		tabulist();
	}

	void emplace(Solution solution) {
		tabulist[last_in] = solution; // Naechstes Element erst jetzt bekannt
		tabulist.emplace(solution, solution);
		last_in = solution;
		if(is_full) {
			Solution buf = tabulist[first_in];
			tabulist.erase(first_in);
			first_in = buf;
		} else if(++current_elements == max_elements) {
			is_full = true;
		}
	}

	bool contains(Solution solution) {
		return tabulist.find(solution) == tabulist.end();
	}
}