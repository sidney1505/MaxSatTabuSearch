#include <stdlib.h>
#include <iostream>
#include <tuple>
#include <string>
#include <chrono>
#include "Reader.h"
#include "MaxSatTabuSearch.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]) {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	if(argc != 5) {
		cout << "wrong count of parameters!" << endl;
		return 0;
	}
	Reader reader(argv[1]);
	if(!reader.read()) {
		return 0;
	}
	Clauses clauses(reader.get_clauses(), reader.get_nbvars(), reader.get_nbclauses());
	if(stoi(argv[4])) {
		cout << "Clauses mapped to variables:" << endl;
		cout << reader.to_string() << endl;
		cout << "Variables mapped to clauses: " << endl;
		cout << clauses.to_string() << endl;
		cout << endl << "start search!" << endl;
	}
	MaxSatTabuSearch msts(clauses, reader.get_nbvars(), stoi(argv[2]), stoi(argv[3]), 
		stoi(argv[4]));
	msts.run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    int minutes = (int) duration / (60 * 1000 * 1000);
    duration -= minutes * 60 * 1000 * 1000;
    int seconds = (int) duration / (1000 * 1000);
    duration -= seconds * 1000 * 1000;
    int millis = (int) duration / 1000;
    cout << "Search needed " << std::to_string(minutes) << " mins " << std::to_string(seconds) << " s ";
    cout << std::to_string(millis) << " millis" << endl << endl;
    return 0;
}