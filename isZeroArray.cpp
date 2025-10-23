class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> df(n + 1, 0);

        for (const auto& query : queries) {
            int s = query[0];
            int e = query[1];

            df[s]--;

            if (e + 1 < n) {
                df[e + 1]++;
            }
        }

        int f = 0;

        for (int i = 0; i < n; i++) {
            f += df[i];
            if (nums[i] + f > 0) {
                return false;
            }
        }

        return true;
    }
};
