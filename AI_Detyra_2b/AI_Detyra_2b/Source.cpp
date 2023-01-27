#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Pair;
typedef tuple<double, int, int> Tuple;
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

template <size_t ROW, size_t COL>
bool isUnBlocked(const array<array<int, COL>, ROW>& grid, const Pair& point)
{
	return isValid(grid, point)
		&& grid[point.first][point.second] == 1;
}

bool isDestination(const Pair& position, const Pair& dest)
{
	return position == dest;
}
int main() {

	cout << "Working fine" << endl;
	return 0;
}