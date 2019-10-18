def spiralPrint(arr):
    n = len(arr)
    m = len(arr[0])
    rowStart = 0
    rowEnd = len(arr)-1
    colStart = 0
    colEnd = len(arr[0])-1
    count = 0
    while(count<(n*m)):
        # Print the first row
        for i in range(colStart,colEnd+1):
            print(arr[rowStart][i],"",end='')
            count+=1
        rowStart+=1
        
        #Print the last column 
        for i in range(rowStart,rowEnd+1):        
            print(arr[i][colEnd],"",end='')
            count+=1
        colEnd-=1
        
        for i in range(colEnd,colStart-1,-1):
            print(arr[rowEnd][i],"",end='')
            count+=1
        rowEnd-=1
        
        for i in range(rowEnd,rowStart-1,-1):
            print(arr[i][colStart],"",end='')
            count+=1
        
        colStart+=1
        
        
#Main
l=[int(i) for i in input().strip().split(' ')]
m, n=l[0], l[1]
arr = [ [ l[(j*n)+i+2] for i in range(n)] for j in range(m)]
spiralPrint(arr)
