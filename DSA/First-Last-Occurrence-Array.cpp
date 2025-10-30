#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> find(vector<int> &nums, int x)
    {
        int first = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
        if (first == nums.size() || nums[first] != x)
        {
            return {-1, -1};
        }
        return {first, last - 1};
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;
    vector<int> answer = s.find(nums, x);
    for (auto val : answer)
    {
        cout << val << " ";
    }
    return 0;
}