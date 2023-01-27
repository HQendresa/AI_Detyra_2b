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

double calculateHValue(const Pair& src, const Pair& dest)
{
	return sqrt(pow((src.first - dest.first), 2.0)
		+ pow((src.second - dest.second), 2.0));
}

template <size_t ROW, size_t COL>
void tracePath(const array<array<cell, COL>, ROW>& cellDetails, const Pair& dest)
{
	printf("\nThe Path is ");

	stack<Pair> Path;

	int row = dest.first;
	int col = dest.second;
	Pair next_node = cellDetails[row][col].parent;
	do {
		Path.push(next_node);
		next_node = cellDetails[row][col].parent;
		row = next_node.first;
		col = next_node.second;
	} while (cellDetails[row][col].parent != next_node);

	Path.emplace(row, col);
	while (!Path.empty()) {
		Pair p = Path.top();
		Path.pop();
		printf("-> (%d,%d) ", p.first, p.second);
	}
}

int main() {

	cout << "Working fine" << endl;
	return 0;
}