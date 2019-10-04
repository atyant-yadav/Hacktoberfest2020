using namespace std;
#include<bits/stdc++.h>
int main()
{
    string str;
    cin>>str;
    int size1=str.size();
    int maxl=1;
    int start=0;
    int low,high;
    for(int i=1;i<size1;i++)
    {
        low=i-1;
        high=i;
        while(low>=0&&high<size1&&str[low]==str[high])
        {
            if(high-low+1>maxl)
            {
                maxl=high-low+1;
                start=low;
            }
            --low;
            ++high;
        }
        low=i-1;
        high=i+1;
        while(low>=0&&high<size1&&str[low]==str[high])
        {
            if(high-low+1>maxl)
            {
                maxl=high-low+1;
                start=low;
            }
            --low;
            ++high;
        }
    }
    for(int i=start;i<=start+maxl-1;i++)
    {
        cout<<str[i];
    }
    return 0;
}