#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = values.size();
    vector<int> dp(capacity + 1, 0);

    for (int w = 0; w <= capacity; ++w) {
        for (int i = 0; i < n; ++i) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }

    return dp[capacity];
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int maxValue = unboundedKnapsack(capacity, weights, values);

    cout << "Maximum value that can be obtained = " << maxValue << endl;

    return 0;
}
