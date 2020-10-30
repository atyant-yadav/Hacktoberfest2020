#include<bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2){

	int n=s1.size(),m=s2.size();

	int a[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(i==0 || j==0)            a[i][j]=0;
            else if(s1[i-1]==s2[j-1])   a[i][j]=a[i-1][j-1]+1;
            else                        a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    
    printf("Length of LCS is %d\n",a[n-1][m-1]);
}

int main(){
        
    string s1="Hacktober2020fest";
    string s2="Hack2020github";
    
    lcs(s1,s2);
    
    return 0;
}
