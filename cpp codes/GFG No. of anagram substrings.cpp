//GFG

#include<bits/stdc++.h>
#define ll long long
#define lli long long int
#define ull unsigned long long
#define li long int
using namespace std;

int main()
{
    vector <int> v(26,0);
    string txt,pat;
    cin>>txt>>pat;
    int n=pat.length();
    for(int i=0;i<n;i++)
    {
        v[pat[i]-'a']++;
    }
    vector <int> temp(26,0);
    int counting =0;
    for(int i=0;i<n;i++)
    {
        temp[txt[i]-'a']++;
    }
    if(v==temp)
        counting++;
    for(int i=n;i<txt.length();i++)
    {
        temp[txt[i]-'a']++;
        temp[txt[i-n]-'a']--;
        if(v==temp)
            counting++;

    }
    cout<<counting<<endl;

}

