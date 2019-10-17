import java.util.*;
import java.io.*;

class Rat_Maze{
    public boolean isSafe(int[][] Maze, int N, int x, int y) {
        return(x<N && y<N && Maze[x][y]==0);
    }

    public boolean findPath(int[][] Maze, int N, int i, int j) {
        
        if(i==(N-1) && j==(N-1)){
            Maze[i][j] = 5;
            return true;
        }
        else if(isSafe(Maze, N, i, j)) {
            Maze[i][j] = 5;
            
            if(findPath(Maze, N, i+1, j) || findPath(Maze, N, i, j+1)){
                return true;
            }
            else{
                Maze[i][j] = 0;
                return false;
            }
        }
        return false;
    }
    public void printMaze(int[][] Maze, int N) {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                System.out.print(Maze[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        int N=6;
        int[][] Maze = new int[N][N];
        Maze[2][1] = Maze[3][1] = Maze[3][2] = Maze[4][2] = Maze[3][3] = Maze[3][5] = 1;
        Maze[4][3] = Maze[5][3] = Maze[0][5] = Maze[1][5] = Maze[2][5] = Maze[4][5] = 1;
        Rat_Maze r = new Rat_Maze();

        
        

        if(r.findPath(Maze, N, 0, 0)) {
            r.printMaze(Maze, N);
        }
        else{
            System.out.println("Jerry can't find path to go home.");
        }


    }
}
//N = 6;
//Block = X;
//Possible Path = 0;
//S = start, H = Home;
        //  S 0 0 0 0 X  00 01 02 03 04 05
        //  0 0 0 0 0 X  10 11 12 13 14 15
        //  0 X 0 0 0 X  20 21 22 23 24 25
        //  0 X X X 0 X  30 31 32 33 34 35
        //  0 0 X X 0 X  40 41 42 43 44 45
        //  0 0 0 X 0 H  50 51 52 53 54 55