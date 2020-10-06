#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
#define N 9

void printMatrix(vector<vector<int>> matrix){
    for(int row = 0; row < N; row++){
        for(int col =0; col < N; col++){
            cout<<matrix[row][col]<<" ";
        }
    }
    cout<<endl;
}

bool findUnassignedLocation(vector<vector<int>> matrix, int &row, int &col){
    for(row = 0; row < N; row++){
        for(col =0; col < N; col++){
            if(matrix[row][col] == UNASSIGNED)
                return true;
        }
    }
    return false;
}

bool usedInRow(vector<vector<int>> matrix, int row, int num){
    for(int col=0; col < N; col++){
        if(matrix[row][col] == num)
          return true;
    }
    return false;
}

bool usedInColumn(vector<vector<int>> matrix, int col, int num){
    for(int row = 0; row < N; row++){
        if(matrix[row][col] == num)
           return true;
    }
    return false;
}

bool usedInBox(vector<vector<int>> matrix, int boxStartRow, int boxStartCol, int num){
    for(int row = 0;row < 3; row++){
        for(int col =0; col < 3; col++){
            if(matrix[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}



bool isSafe(vector<vector<int>> matrix, int row, int col, int num){
    return (!usedInRow(matrix, row, num) && !usedInColumn(matrix, col, num) && !usedInBox(matrix, row - row%3, col - col%3, num));
}
bool solveSudoku(vector<vector<int>> &matrix){
    int row, col;
    
    if(!findUnassignedLocation(matrix, row, col))
         return true;
    
    for(int num = 1; num <= 9 ; num++){
        if(isSafe(matrix, row , col, num)){
            matrix[row][col] = num;
            
            if(solveSudoku(matrix))
               return true;
        
            matrix[row][col] = UNASSIGNED;
        }
        
    }
    return false;
    
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    vector<vector<int>> matrix(9,vector<int>(9,0));
	    cout<<"Enter 9X9 matrix to be solved(Enter 0 for marking it as an empty cell)"<<endl;
	    for(int i = 0; i < N; i++)
	        for(int j = 0 ; j < N; j++)
	              cin>>matrix[i][j];
	    
	    if(solveSudoku(matrix) == true)
	        printMatrix(matrix);
	    else     
	         cout<<"No solution exists";
	         
	}
	return 0;
}
