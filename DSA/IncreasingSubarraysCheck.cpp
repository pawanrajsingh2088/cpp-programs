class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i <= n - 2 * k; i++) {
            bool f = true, s = true;

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    f = false;
                    break;
                }
            }

            if (f) {
                for (int j = i + k; j < i + (2 * k) - 1; j++) {
                    if (nums[j] >= nums[j + 1]) {
                        s = false;
                        break;
                    }
                }

                if (s) {
                    return true;
                }
            }
        }

        return false;
    }
};
