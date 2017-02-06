#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <string>
#include "Reader.h"
#include "MaxSatTabuSearch.h"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 5) {
		cout << "wrong count of parameters!" << endl;
		return 0;
	}
	Reader reader(argv[1]);
	reader.read();
	Clauses clauses(reader.get_clauses(), reader.get_nbvars(), reader.get_nbclauses());
	if(stoi(argv[4])) {
		cout << "Variables mapped to clauses: " << endl;
		cout << clauses.to_string() << endl;
	}
	MaxSatTabuSearch msts(clauses, reader.get_nbvars(), stoi(argv[2]), stoi(argv[3]), 
		stoi(argv[4]));
	msts.run();
}