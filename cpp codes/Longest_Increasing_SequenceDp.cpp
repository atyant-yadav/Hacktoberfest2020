#include<iostream>
using namespace std;

//Longest increasing sequence by Bottom Up Dynamic Programming
int lis(int a[],int n){
	int dp[n]={1},maxi=1;
	for(int i=1;i<n;i++){
	  int j=i-1,val=1;
	  while(j>=0){
       if(a[j]<a[i]){
			   val=max(val,dp[j]+1);
		    }
			  j--;
	  }
	  dp[i]=val;
		maxi=max(maxi,dp[i]);
	}
	return maxi;
}

int main() {
	int n;  cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];

  //length of Longest Common sequence
    cout<<lis(a,n);
	return 0;
}
