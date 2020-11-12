// Program for solving sudoku

#include <iostream>
#include <math.h>
using namespace std;
bool mfixed[20][20] = {};

int canPlace(int board[][20], int n, int x,int y,int num)
{
	// to check along row and column
	for (int i = 0; i < n ; ++i)
	{
		if(board[i][y] == num) return false;
		if(board[x][i] == num) return false;
	}
	// to check in the box 
	int rootN  = sqrt(n);
	int sRow = x / rootN;
	int sCol = y / rootN;
	int startRow = sRow*rootN;
	int startCol = sCol*rootN; 
	for (int row = startRow; row < startRow + rootN; ++row)
	{
		for (int col = startCol; col < startCol + rootN; ++col)
		{
			if (board[row][col] == num) return false;
			
		}
	}
	return true;
}
int solveSudoku(int board[][20], int n, int x,int y)
{
	if (x == n && y == 0) return true;
	
	if (y == n) return solveSudoku(board,n,x+1,0);

	if (mfixed[x][y]) return solveSudoku(board,n,x,y+1);

	for (int num = 1; num <= n; ++num)
	{
		if (canPlace(board,n,x,y,num) == true)
		{
			board[x][y] = num;
			bool isSuccessful = solveSudoku(board,n,x,y+1);
			if (isSuccessful) return true;
			else board[x][y] = 0;
		}
	}
	return false;
}
int main()
{
	int board[20][20]= {};			
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];	
			if (board[i][j] != 0)
			{
				mfixed[i][j] = true;
			}
		}
	}

	solveSudoku(board, n, 0, 0);
	cout << "================================= \n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
		cout<< board[i][j] << " ";	
		}
		cout<<endl;
	}
}
