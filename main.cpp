#include <stdlib.h>
#include <iostream>
#include <tuple>
#include "Reader.h"
#include "Neighbourhood.h"

using namespace std;

// g++ -std=c++11 main.cpp Reader.cpp Clauses.cpp Neighbourhood.cpp
int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "wrong count of parameters" << endl;
	}
	Reader reader(argv[1]);
	reader.read();
	cout << "Reading successful!" << endl << reader.to_string() << endl << endl;
	Clauses clauses(reader.get_clauses(), reader.get_nbvars(), reader.get_nbclauses());
	cout << endl << "Clauses:" << endl << clauses.to_string() << endl;
	vector<bool> initial_solution(reader.get_nbvars());
	Neighbourhood nh(initial_solution, clauses);
	cout << endl << "Neighbourhood: " << endl << nh.to_string() << endl << endl;
	auto best_neighbour = nh.get_best_neighbour();
	nh.update(get<1>(best_neighbour));
	cout << endl << "Neighbourhood after update: " << endl << nh.to_string() << endl << endl;
	cout << endl << std::to_string(get<1>(nh.get_best_neighbour())) << endl;
}