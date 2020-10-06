//SUDOKU SOLVER using Recursion and BackTracking
#include <bits/stdc++.h>
using namespace std;
bool checkplacenumber(int mat[9][9],int i,int j,int number,int n){
    for(int x=0;x<n;x++){
        if(mat[x][j]==number ||  mat[i][x]==number)
            return false;
    }
    int rootn=sqrt(n);
    int rx=(i/rootn)*rootn;
    int px=(j/rootn)*rootn;

    for(int x=rx;x<rx+rootn;x++){
        for(int y=px;y<px+rootn;y++){
            if(number==mat[x][y])return false;
        }
    }
return true;
}
bool solvesudoku(int mat[9][9],int i,int j,int n){
    //base case when all rows are traversed
    if(i==n){
        //print sudoku
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
                }
                cout<<endl;
                }
        return true;
    }
    // when all columns of a particular row  is traversed
    if(j==n){return solvesudoku(mat,i+1,0,n);}
    //recursion and backtracking steps
    if(mat[i][j]!=0)return solvesudoku(mat,i,j+1,n);

    for (int number=1;number<=n;number++){
        if(checkplacenumber(mat,i,j,number,n)){
            mat[i][j]=number;
            bool canbesolved=solvesudoku(mat,i,j+1,n);
            if(canbesolved)return true;
        }
    }
    mat[i][j]=0;
    return false;


}
int main() {
  int mat[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int res=solvesudoku(mat,0,0,n);
    if(res)cout<<"Sudoku is solved"<<endl;
    else cout<<"Sudoku is not solved"<<endl;
}
