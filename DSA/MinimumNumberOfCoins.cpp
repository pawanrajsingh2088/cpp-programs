#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    const int INF = 1e9; 
    vector<int> dp(amount + 1, INF);
    dp[0] = 0; 

    for (int coin : coins) {
        for (int x = coin; x <= amount; x++) {
            dp[x] = min(dp[x], dp[x - coin] + 1);
        }
    }

    return (dp[amount] == INF) ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);

    if (result == -1)
        cout << "It is not possible to make the amount with given coins"<<endl;
    else
        cout << "Minimum number of coins required: " << result << endl;

    return 0;
}
