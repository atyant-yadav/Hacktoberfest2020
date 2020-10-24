#include <iostream>

using namespace std;


int st[1001],n;

int valid(int k)
{
    for(int i = 1 ; i < k ; i++)
        if(st[i] == st[k])
            return 0;
    return 1;
}

void afisare(int k)
{
    int i;
    for(i = 1 ; i <= k ; i++)
        cout << st[i] << " ";
    cout << endl;
}

void bk(int k)
{
    for(int i = 1 ; i <= n ; i++)
    {
        st[k] = i;
        if(valid(k))
            if(k == n)
                afisare(k);
            else bk(k+1);
    }
}

int main()
{
    cin >> n;
    bk(1);
}
