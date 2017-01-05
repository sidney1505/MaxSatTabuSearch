#include <fstream>
using namespace std;

class Reader {
private:
	string url;
	uint nbvar, nbclauses;
	vector<vector<pair<uint,bool>>> clauses;
public:
	Reader(string url) {
		this->url = url;
	}

	// orientiert an Dateiformat DIMACS von http://maxsat.ia.udl.cat/
	void read() {
		std::ifstream infile("thefile.txt");
		// orientiert an http://stackoverflow.com/questions/7868936/read-file-line-by-line
		string line;
		std::istringstream iss;
		do {
			std::getline(infile, line);
			iss = new std::istringstream(line); // eventuell synthax-korrektur noetig
			char c;
			iss >> c;
		} while(c == 'c');
		string format;
		iss >> format;
		if(format != "cnf") {
			cout << "wrong format!" << endl;
		}
		uint nbvar, nbclauses;
		iss >> nbvar >> nbclauses;
		clauses = new vector<vector<pair<uint,bool>>>(nbclauses, vector<uint,bool>(0));
		for(int i = 0; i < nbclauses; i++) {
			std::getline(infile, line);
			iss = new std::istringstream(line);
			int var;
			while(iss >> var && var != 0) {
				clauses[i].push_back(make_pair(abs(var),var > 0));
			}
		}
	}

	vector<vector<pair<uint,bool>>> getClauses()  {
		return clauses;
	}
}