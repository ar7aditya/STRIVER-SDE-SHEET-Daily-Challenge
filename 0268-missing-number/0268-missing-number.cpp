class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        long long sum = 0;
        while(i <= n){
            sum ^= i;
            i++;
        }
        long long res = 0;
        for(int i=0;i<n;i++){
            res ^= nums[i];
        }
        return sum ^ res;
    }
};