#include <bits/stdc++.h>
using namespace std;

int knapsack(const vector<int>& values, const vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    values[i - 1] + dp[i - 1][w - weights[i - 1]]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
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

    int maxValue = knapsack(values, weights, capacity);
    cout << "Maximum value that can be obtained = " << maxValue << endl;

    return 0;
}
