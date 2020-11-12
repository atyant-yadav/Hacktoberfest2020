// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;
#define SZ 100

// Function to get the maximum path
// sum from top-left cell to all
// other cells of the given matrix
void pathSum(const int mat[SZ][SZ],
			int N, int M)
{

	// Store the maximum path sum
	int dp[N][M];

	// Initialize the value
	// of dp[i][j] to 0.
	memset(dp, 0, sizeof(dp));

	// Base case
	dp[0][0] = mat[0][0];
	for (int i = 1; i < N; i++) {
		dp[i][0] = mat[i][0]
				+ dp[i - 1][0];
	}

	for (int j = 1; j < M; j++) {
		dp[0][j] = mat[0][j]
				+ dp[0][j - 1];
	}

	// Compute the value of dp[i][j]
	// using the recurrence relation
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			dp[i][j] = mat[i][j]
					+ max(dp[i - 1][j],
							dp[i][j - 1]);
		}
	}

	// Print maximum path sum from
	// the top-left cell
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

// Driver Code
int main()
{
	int mat[SZ][SZ]
		= { { 3, 2, 1 },
			{ 6, 5, 4 },
			{ 7, 8, 9 } };
	int N = 3;
	int M = 3;

	pathSum(mat, N, M);
}
