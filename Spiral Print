from sys import stdin
def printdata(arr, i, j, nRows, mCols): 
        
    if (i > nRows or j >mCols): 
        return 
            
    for p in range(i, mCols): 
        print(arr[i][p], end = " ") 
          
    for p in range(i + 1, nRows): 
        print(arr[p][mCols - 1], end = " ") 
           
    if ((nRows - 1) != i):  
        for p in range(mCols - 2, j - 1, -1): 
            print(arr[nRows - 1][p], end = " ") 
                
    if ((mCols - 1) != j): 
        for p in range(nRows - 2, i, -1): 
            print(arr[p][j], end = " ") 
              
    printdata(arr, i + 1, j + 1, nRows - 1, mCols - 1) 
    
    
def take2DInput() :
    li = stdin.readline().rstrip().split(" ")
    nRows =int(li[0])
    mCols = int(li[1])
     
    if nRows == 0:
        return list(), 0, 0
     
    mat = [list(map(int, input().strip().split(" "))) for row in range(nRows)]
    return mat, nRows, mCols

t = int(stdin.readline().rstrip())
 
while t > 0 :
 
    mat, nRows, mCols = take2DInput()
    printdata(mat,0,0,nRows, mCols)
    print()
 
    t -= 1
