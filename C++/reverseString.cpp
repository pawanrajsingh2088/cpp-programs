#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }

private:
    void helper(vector<char>& s, int left, int right) {
        if (left >= right) return;

        // Swap characters
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Recursive call
        helper(s, left + 1, right - 1);
    }
};
