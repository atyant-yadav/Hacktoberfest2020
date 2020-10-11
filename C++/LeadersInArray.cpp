#include<bits/stdc++.h>
using namespace std;

int main()
 {
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
       
       vector<int> v;
       
       int maxV = INT_MIN;
       for(int i=n-1;i>=0;i--)
       {
        
          if(a[i]>=maxV)
          {
              maxV = a[i];
              v.push_back(maxV);
          }
       }   
       
       reverse(v.begin(),v.end());
       //maxV = a[n-1];
       //v.push_back(maxV);
      
       
       for(int i=0;i<v.size();i++)
            cout<< v[i] << " ";
        cout<<endl;
    }
	return 0;
}
