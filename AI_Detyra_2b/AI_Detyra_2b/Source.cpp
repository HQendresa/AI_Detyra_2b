#include <iostream>
#include <queue>
typedef pair<int, int> Pair;
typedef tuple<double, int, int> Tuple;

using namespace std;
struct cell {

	Pair parent;

	double f, g, h;
	cell()
		: parent(-1, -1)
		, f(-1)
		, g(-1)
		, h(-1)
	{
	}
};
int main() {

	cout << "Working fine" << endl;
	return 0;
}