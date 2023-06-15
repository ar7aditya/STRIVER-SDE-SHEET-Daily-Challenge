class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = (start ^ goal);
        int count = 0;
        for(int i=0;i<32;i++){
            if( ((1<<i) & x) >= 1){
                count++;
            }
        }
        return count;
    }
};
   