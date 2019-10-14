#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll MaxPairwiseProductFast(const vector<int> &numbers)
{
    int max_index_1 = -1;
    int n = numbers.size();
    for (int i = 0;i<n;++i)
    {
        if ( (max_index_1 == -1 ) || (numbers[i] > numbers[max_index_1]))
            max_index_1 = i;
    }

    int max_index_2 = -1;
    for (int j = 0;j<n;++j)
    {
        if ((j != max_index_1) && ((max_index_2 == -1) || (numbers[j]>numbers[max_index_2])))
            max_index_2 = j;
    }

return  ((ll)(numbers[max_index_1]))*numbers[max_index_2];
}


int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout<<MaxPairwiseProductFast(numbers)<< "\n";
    return 0;
}
