#include <map>
#include <vector>

using namespace std;

template <typename Solution>
class Tabulist {
private:
	int max_elements;
	int current_elements;
	bool is_full = false;
	// Jede Solution ist zu der naechsten Solution gemappt
	map<Solution,Solution>* tabulist;
	Solution last_in; // map pointer verwenden
	Solution first_in;

public:
	Tabulist();
	Tabulist(int max_elements);
	void emplace(Solution solution);
	bool contains(Solution solution);
	// string to_string();
};
