#include<bits/stdc++.h>
using namespace std;

long long get_pisano_period_length(long long m) {
    long long F1 = 0, F2 = 1, F = F1 + F2;
    for (int i = 0; i < m * m; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
        if (F1 == 0 && F2 == 1) return i + 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {

    long long remainder = n % get_pisano_period_length(m);
    long long F1 = 0, F2 = 1, F = remainder;

    for (int i = 1; i < remainder; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
    return F % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_fast(n, m) << '\n';
    return 0;
}
