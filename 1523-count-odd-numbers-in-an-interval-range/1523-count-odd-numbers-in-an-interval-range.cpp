class Solution {
public:
    int countOdds(int low, int high) {
        int odd_high = (high+1)/2;
        int odd_low = (low+1)/2;
        int ans = odd_high - odd_low  ;
        if(low%2!=0) ans+=1;
        return ans;
    }
};