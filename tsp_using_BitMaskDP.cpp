#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n; // number of cities
vector<vector<int>> dist; // distance matrix
vector<vector<int>> dp;   // dp[mask][i] = min cost to visit all cities in 'mask' ending at i

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0]; // return to start city

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newCost);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    dist.assign(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    dp.assign(1 << n, vector<int>(n, -1));

    int result = tsp(1, 0); // start from city 0 with mask = 000...001
    cout << "\nMinimum cost to visit all cities and return: " << result << endl;

    return 0;
}
