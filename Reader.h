//using namespace std;

class Reader {
private:
	private: string url;
	private: uint nbvar;
	private: uint nbclauses;
public:
	public: Reader(string url); 

	// orientiert an Dateiformat DIMACS von http://maxsat.ia.udl.cat/
	public: read();
}
