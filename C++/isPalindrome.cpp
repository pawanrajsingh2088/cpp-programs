class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (but not 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;
        
        // Reverse half of the number
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Compare the original half and the reversed half
        return (x == reversed || x == reversed / 10);
    }
};
