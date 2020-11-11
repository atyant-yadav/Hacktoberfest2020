#include <bits/stdc++.h>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

    double value = 0.0;

    int n = values.size();
    vector<pair<double, int> > unitValue;

    for (int i = 0; i < n; ++i) {
        double currUnitVal = static_cast<double>(values[i]) / weights[i];
        unitValue.emplace_back(make_pair(currUnitVal, i));
    }

    sort(unitValue.rbegin(), unitValue.rend());

    for (int i = 0; i < n; ++i) {

        int amt = min(weights[unitValue[i].second], capacity);
        capacity -= amt;

        value += (amt * unitValue[i].first);

        if (capacity == 0)
            break;
    }

    return value;
}

int main() {

    int n, W;
    cin >> n >> W;

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i < n; ++i) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(W, weights, values);
    cout.precision(10);
    cout << optimal_value << '\n';

    return 0;
}
