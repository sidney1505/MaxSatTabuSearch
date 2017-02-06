#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <string>
#include "Reader.h"
#include "MaxSatTabuSearch.h"

using namespace std;

// g++ -std=c++11 main.cpp Clauses.cpp Reader.cpp Neighbourhood.cpp Tabulist.cpp MaxSatTabuSearch.cpp TabuSearch.cpp
int main(int argc, char *argv[]) {
	if(argc != 5) {
		cout << "wrong count of parameters" << endl;
	}
	Reader reader(argv[1]);
	reader.read();
	Clauses clauses(reader.get_clauses(), reader.get_nbvars(), reader.get_nbclauses());
	MaxSatTabuSearch msts(clauses, reader.get_nbvars(), stoi(argv[2]), stoi(argv[3]), 
		stoi(argv[4]));
	msts.run();
}