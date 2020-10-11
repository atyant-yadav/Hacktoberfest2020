// C++ program to demonstrate use of map
// for pairs
#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> vis;

// Print positions that are not marked
// as visited
void printPositions(int a[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (vis[{ i, j }] == 0)
				cout << "(" << i << ", " << j << ")"
					<< "\n";
}

int main()
{
	int mat[3][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };

	// Marking some positions as visited
	vis[{ 0, 0 }] = 1; // visit (0, 0)
	vis[{ 1, 0 }] = 1; // visit (1, 0)
	vis[{ 1, 1 }] = 1; // visit (1, 1)
	vis[{ 2, 2 }] = 1; // visit (2, 2)

	// print which positions in matrix are not visited by rat
	printPositions(mat);
	return 0;
}
