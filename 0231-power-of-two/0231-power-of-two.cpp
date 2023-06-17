class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == -2147483648) return false;
        int x = __builtin_popcount(n);
        if(x == 1) return true;
        return false;
    }
};