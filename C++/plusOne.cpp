class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;  // No carry needed
            }
            digits[i] = 0;  // Set to 0 and carry 1 to the next digit
        }

        // If all digits were 9, we need an extra digit at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
