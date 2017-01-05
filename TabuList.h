class TabuList {

	private: uint max_elements;
	private: uint current_elements;
	private: bool is_full = false;
	// Jede Solution ist zu der naechsten Solution gemappt
	private: map<Solution,Solution> tabulist;
	private: Solution last_in; // map pointer verwenden
	private: Solution first_in;


	public: TabuList(uint max_elements); 

	public: void emplace(Solution solution); 

	public: bool contains(Solution solution);
}
