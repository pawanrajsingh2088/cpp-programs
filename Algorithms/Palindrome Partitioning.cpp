#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int minCuts(string &s, int i, int j, vector<vector<int>> &dp) {
    if (i >= j || isPalindrome(s, i, j))
        return 0;  

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        if (isPalindrome(s, i, k)) { 
            int right = minCuts(s, k + 1, j, dp);
            ans = min(ans, 1 + right);
        }
    }

    return dp[i][j] = ans;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Minimum number of cuts needed for palindrome partitioning: "
         << minCuts(s, 0, n - 1, dp) << endl;

    return 0;
}
