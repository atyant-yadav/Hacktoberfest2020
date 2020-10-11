#include<iostream>
#include<cmath>
using namespace std;

bool Is_Prime(int num)
{
    if(num == 1) return false;
    bool flag = true;
    for(int i=2;i<=sqrt(num);i++)
        if(num%i==0)
            {
                flag = false;
                return flag;
            }
    return flag;
}

int main()
{
    int T;
    cin >> T;
    int first, second;
    while(T--)
    {
        cin >> first >> second;
        for(int i=first; i<=second; i++)
            if(Is_Prime(i))
                cout << i << endl;
    }
    return 0;
}