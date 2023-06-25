class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1;
        int n = nums.size();
        int i = 0;
        while(i<n && nums[i] == 0){
            i++;
        }
        if(i == n) return 0;
        int count = 0;
        while(i < n){
            if(nums[i] == 1){
                ans = (ans * (count + 1)) % mod;
                count = 0;
            }
            else{
                count++;
            }
            i++;
        }
        return ans;
    }
};