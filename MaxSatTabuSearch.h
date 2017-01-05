class MaxSatTabuSearch {

	// innerer vektor beginnt erst bei 1
	private:vector<vector<pair<int,bool>>> conds;
	private:vector<bool> bestSolutionFound; //TODO Bezug auf Template??
	private: vector<bool> current_solution;
	// Optimierung um Kopieren zu vermeiden
	private:vector<vector<bool>> current_neighboorhood;
	// letztes gekippte bit
	private:int last_changed;
	
	private:void init();
	//Verwendung um initiale nachbarschaft zu erhalten
	private:*vector<vector<bool>> getNeighbourhood(vector<bool> &solution);

	// Optimierte Version
	private:void actualiseNeighbourhood();
	
	private:int naive_eval(vector<bool> &solution);


	public:MaxSatTabuSearch(vector<vector<int>> conds, number_of_variables);
}
