
/* Below is the dnf sort have O(n) time complexity
    lo = lower
    hi = higher
    mid = middle

    DNF sort is based on the analogy of dutch national flag
    and works for 3 distinct numbers only but it is an efficient and faster
    way to sort the input stream of three numbers.

    It calculates the median

    how it's works

    In three number let's say we have 0 , 1, 2 and made a two pointers means that 1 is automatically get stored if we place the 0 and 2 to the correct position


 */

#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define ff first
#define ss second
#define inf 9e18
#define pii pair<int, int>
#define setp(x) fixed << showpoint << setprecision(x)
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;
void dnf(vector<int> &a)
{
    int lo, hi, mid;
    lo = mid = 0;
    hi = a.size() - 1;
    while (mid < hi)
    {
        if (a[mid] == 0)
        {
            swap(a[mid], a[lo]);
            lo++;
            mid++;
        }

        else if (a[mid] == 1)
            mid++;

        else if (a[mid] == 2)
        {
            swap(a[mid], a[hi]);
            hi--;
        }
    }
}
int32_t main()
{

    fastio

        int n;
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dnf(v);
    for (int i : v)
        cout << i << " ";
    return 0;
}
