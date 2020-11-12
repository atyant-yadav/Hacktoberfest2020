#include <iostream>
using namespace std;

int main() {
	int t,n,s;
	cin>>t; //t=number of test cases.

	while(t--)
	{
	    int b=0;
	    int sum=0;
	    int flag=1;
	    cin>>n>>s;// s=given sum .....n=size of array
	    int a[n];
	    int i,j;
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	   
	    for(i=0;i<n;i++)
	    {
	      sum=sum+a[i];
	        
	        while(sum>s)
	        {  
	            sum=sum-a[b];// sliding the elements if sum exceeds the given sum.
	            b++;
	        }
	       
	       
	           
	        if(sum==s)
	            
	        {
				      flag=0;
	            cout<<b+1<<" "<<i+1<<"\n"; //prints the first and last index of the subarray
	            break;
	        }
	        
	        
	   
	    }
	    if(flag==1)
	    {
	        cout<<"-1"<<"\n";// no such subarray exists..
	    }
	    
	}
	return 0;
}
