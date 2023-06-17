class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        while(n != 0){
            int rsbm = (n & -n);
            n -= rsbm;
            x++;
        }
        return x;
    }
};