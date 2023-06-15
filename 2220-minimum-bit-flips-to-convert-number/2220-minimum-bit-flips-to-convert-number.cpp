class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = (start ^ goal);
        int count = 0;
        while(x != 0){
            int rsbm = (x & -x);
            x -= rsbm;
            count++;
        }
        return count;
    }
};
   