#include <bits/stdc++.h>
using namespace std;

int get_fibonacci_last_digit_fast(int n) {

    if (n <= 1)
        return n;

    int first = 0, second = 1, curr;

    for (int i = 2; i <= n; ++i) {
        curr = (first + second) % 10;
        first = second;
        second = curr;
    }

    return curr;
}

int main() {

    int n;
    cin >> n;

    int last_digit = get_fibonacci_last_digit_fast(n);
    cout << last_digit << '\n';

    return 0;
}
