# include <stdlib.h>
# include <iostream>
# include "Reader.h"
# include "Clauses.h"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "wrong count of parameters" << endl;
	}
	Reader reader(argv[1]);
	cout << "Reader inititialisiert!" << endl;
	reader.read();
	cout << "Erfolgreich gelesen!" << endl;
	cout << reader.to_string() << endl;
	Clauses clauses(reader.get_clauses(), reader.get_nbvars(), reader.get_nbclauses());
	cout << "Klauseln erfolgreich erstellt!" << endl;
	cout << clauses.to_string() << endl;
}