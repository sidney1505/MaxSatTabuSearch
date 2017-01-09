# include <stdlib.h>
# include <vector>

using namespace std;

class Reader {
private:
	string url;
	int nbvars;
	int nbclauses;
	vector<vector<pair<int,bool>>>* clauses;
public:
	Reader(string url); 
	void read();
	vector<vector<pair<int,bool>>> get_clauses();
	int get_nbvars();
	int get_nbclauses();
	string to_string();
};
