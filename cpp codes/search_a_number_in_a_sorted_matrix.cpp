#include <bits/stdc++.h>
using namespace std;
//By shwetank_verma
int search(int n,vector<vector<int> > a,int k){
    int l=0;
    int r=n-1;
    int min=a[0][0];

 if(n==0)
    return -1;
if(k<min)
    return -1;
int max=a[n-1][n-1];
if(k>max)
    return -1;

while(l<n&&r>=0){
    if (a[l][r] == k) {
            cout << "Found at "<< l << " " << r<<endl;
            return 1;
        }
        if (a[l][r] > k)
            r--;
        else
            l++;
    }


    return 0;
}
int main(){
    int n;
    cin>>n;

    vector<vector<int> > a( n , vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                int e;
        cin>>e;
            a[i][j]=e;
        }
    }
    int k;
    cin>>k;

    int ans=search(n,a,k);
    if(ans!=1)
        cout<<"NOT Found"<<endl;
    return 0;
}

