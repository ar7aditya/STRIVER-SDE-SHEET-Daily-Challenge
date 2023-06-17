class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        int x = 0;
        while(n != 0){
            int rsbm = (n & -n);
            n -= rsbm;
            x++;
        }
        if(x == 1) return true;
        return false;
    }
};