#include "math.h"
#include <array>
#include <chrono>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <tuple>

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

template <size_t ROW, size_t COL>
void aStarSearch(const array<array<int, COL>, ROW>& grid,
	const Pair& src, const Pair& dest)
{
	// If the source is out of range
	if (!isValid(grid, src)) {
		printf("Source is invalid\n");
		return;
	}

	// If the destination is out of range
	if (!isValid(grid, dest)) {
		printf("Destination is invalid\n");
		return;
	}

	// Either the source or the destination is blocked
	if (!isUnBlocked(grid, src)
		|| !isUnBlocked(grid, dest)) {
		printf("Source or the destination is blocked\n");
		return;
	}

	// If the destination cell is the same as source cell
	if (isDestination(src, dest)) {
		printf("We are already at the destination\n");
		return;
	}

	bool closedList[ROW][COL];
	memset(closedList, false, sizeof(closedList));

	array<array<cell, COL>, ROW> cellDetails;

	int i, j;
	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent = { i, j };

	std::priority_queue<Tuple, std::vector<Tuple>,
		std::greater<Tuple> >
		openList;

	openList.emplace(0.0, i, j);

	printf("Failed to find the Destination Cell\n");
}

int main() {

	array<array<int, 10>, 9> grid{
		{ { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 } },
		{ { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 } },
		{ { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 } },
		{ { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 } },
		{ { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 } },
		{ { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 } },
		{ { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 } },
		{ { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 } },
		{ { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } } }
	};

	return 0;
}