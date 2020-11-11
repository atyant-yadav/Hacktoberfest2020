#include<iostream>
#include<climits>
using namespace std;

int main() {
	int n;  cin>>n; int a[n],pre[n];
	cin>>a[0];
  pre[0]=a[0];  int ans=a[0],result=0;
  
  // building prefix XOR array
	for(int i=1;i<n;i++){
	  cin>>a[i];
    ans=ans^a[i];
	  pre[i]=ans;
	  if(result<ans)
	  result=ans;
	}
   int l;
    for(int i=0;i<n;i++){
		  for(int j=i+1;j<n;j++){
          l=pre[i]^pre[j];
		      if(l>result){
			      result=l;
		      }
		  }
	  }
    
    //printing xor of the subarray whose xor of all elements in subarray is maximum over all subarrays
	cout<<result;
	return 0;
}
