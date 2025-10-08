#include <iostream>
using namespace std;

int findFloor(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int answer = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target)
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;
    cout << findFloor(nums, x) << endl;
    return 0;
}