#include <map>
#include <vector>

using namespace std;

// template <typename Solution>

class Tabulist {
private:
	int max_elements;
	int current_elements;
	bool is_full = false;
	// Jede Solution ist zu der naechsten Solution gemappt
	map<vector<bool>,vector<bool>>* tabulist;
	vector<bool> last_in; // map pointer verwenden
	vector<bool> first_in;

public:
	Tabulist();
	Tabulist(int max_elements);
	void emplace(vector<bool> solution);
	bool contains(vector<bool> solution);
	string to_string();
};
