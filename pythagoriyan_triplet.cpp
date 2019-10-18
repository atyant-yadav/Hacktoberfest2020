#include<iostream>
using namespace std;
int main()
{
    int n,i,a,b,c,k,r,t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        arr[i]*=arr[i];
    }
    
     sort(arr,arr+n);
        int temp=0,first,second;
        for(i=n-1;i>=2;i--){
             first = 0;
             second = i-1;
                while(first<second && temp==0){
                        if((arr[second]+arr[first])==arr[i]){
                            temp=1;
                            cout<<"Yes"<<endl;
                            break;
                        }
                        else if((arr[second]+arr[first])<arr[i])
                            first++;
                        else if((arr[second]+arr[first])>arr[i])  
                            second--;
            }
        }
        if(temp==0)
            cout<<"No"<<endl;
    
}
}
