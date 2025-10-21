class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (unsigned)(a & b);  // Step 1: calculate carry
            a = a ^ b;                           // Step 2: sum without carry
            b = (int)(carry << 1);               // Step 3: move carry to left
        }
        return a;
    }
};
