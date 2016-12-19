#include <fstream>
using namespace std;

class Reader {
private:
	string url;
	uint nbvar;
	uint nbclauses;
public:
	Reader(string url) {
		this->url = url;
	}

	// orientiert an Dateiformat DIMACS von http://maxsat.ia.udl.cat/
	read() {
		fstream f(url,ios::in);
		f.open();
		string s;
		while(f >> s && s == "c") {
			//skip line
		}
		if(s == "p" && f >> s && s = "cnf") {
			f >> nbvar >> nbclauses;
		}
		// Leerzeichen und next-line unterschiende???
	}
}