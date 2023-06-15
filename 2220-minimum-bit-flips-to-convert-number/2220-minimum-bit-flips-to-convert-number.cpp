class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = (start ^ goal);
        int count = 0;
        for(int i=0;i<32;i++){
            if( ((x>>i) & 1) == 1){
                count++;
            }
        }
        return count;
    }
};
   