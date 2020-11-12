/*

Min Jumps Array
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array. 
Each element in the array represents your maximum jump length at that position. 
Return the minimum number of jumps required to reach the last index. If it is not possible to reach the last index, return -1.
*/

/* Below is solution function*/

int Test::jump(vector<int> &A) {
    int n = A.size();
    
    vector<int> dp(n, 0);
    int reached = 0;
    for(int i = 0; i<n && reached < n-1; i++){
        if(i>reached){
            break;
        }
        if((i+A[i]) > reached){
            for(int j = reached+1; j<=i+A[i] && j<n; j++){
                dp[j]=dp[i]+1;
            }
            reached = i+A[i];
        }
    }
    return reached >= n-1 ? dp[n-1] : -1;
}

