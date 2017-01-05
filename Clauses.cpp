using namespace std;

class Clauses {
private:
	vector<vector<pair<int,bool>>> vars;

public:
	Clauses(vector<vector<int,bool>> &clauses, uint nbvars) {
		vars = vector<vector<int,bool>>>(nbvars, vector<int,bool>(0));
		for(int i = 0; i < nbvars; i++) {
			for(int j = 0; j < clauses[i].size(); j++) {
				pair<int,bool> p = clauses[i][j];
				vars[fst(p)].push_back(make_pair(i, snd(p))); // TODO potentielle Fehlerquelle!
			}
		}
	}
}