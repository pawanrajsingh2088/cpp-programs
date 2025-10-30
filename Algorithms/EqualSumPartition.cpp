#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if (totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;
    int n = nums.size();

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums)
    {
        for (int j = target; j >= num; --j)
        {
            if (dp[j - num])
                dp[j] = true;
        }
    }

    return dp[target];
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (canPartition(arr))
        cout << "Yes, the array can be partitioned into two subsets with equal sum" << endl;
    else
        cout << "No, it cannot be partitioned into two subsets with equal sum" << endl;

    return 0;
}
