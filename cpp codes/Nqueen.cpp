/*
In N*N chess board place N queens , such that all queens are safe.
(Remember Queen can move any number of squares vertically, horizontally and diagionally)
*/

#include<bits/stdc++.h>
using namespace std;

//isSafe function is used to check whether a queen can be placed at (i,j)
//To check if queen is safe or not , if have to check if a queen is present vertically
//(in that column) , and diagonally(both left and right)
bool isSafe(int board[][10] , int i , int j , int n) {

	//check for column
	for (int row = 0; row < i; row++) {
		if (board[row][j] == 1)
			return false;
	}

	//check for left diagonal
	int x = i - 1;
	int y = j - 1;
	while (x >= 0 and y >= 0) {
		if (board[x][y] == 1)
			return false;

		x--;
		y--;
	}

	//check for right diagonal
	x = i - 1;
	y = j + 1;
	while (x >= 0 and y < n) {
		if (board[x][y] == 1)
			return false;

		x--;
		y++;
	}

	return true;
}

bool placeNqueens(int n , int i , int board[][10]) {  //i will keep track of current row

	//base case
	if (i == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true; //we found our solution
	}

	//first we will try to place the queen in current row
	for (int j = 0; j < n; j++) {
		if (isSafe(board, i, j, n)) {
			board[i][j] = 1;

			bool nextQueenRakhPaye = placeNqueens(n, i + 1, board);
			if (nextQueenRakhPaye) {
				return true;
			}

			//backtracking
			board[i][j] = 0;
		}
	}

	return false;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;

	int board[10][10] = {0};
	placeNqueens(n , 0 , board);


	return 0;
}

/*
The above program prints only one possible solution.
To get all the possible solutions remove this
if (nextQueenRakhPaye) {
	return true;
}

*/