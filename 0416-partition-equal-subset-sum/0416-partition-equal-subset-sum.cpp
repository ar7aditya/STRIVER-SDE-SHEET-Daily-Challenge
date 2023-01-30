class Solution {
public:
    bool f(int i,long long tar,vector<int>& nums,vector<vector<int>>& dp){
        if(tar==0 || nums[i]==tar) return true;
        if(i==0){
            if(tar==nums[0]) return true;
            return false;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];
        bool ntpck = f(i-1,tar,nums,dp);
        bool pck =false;
        if(nums[i] < tar) pck = f(i-1,tar-nums[i],nums,dp);
        return dp[i][tar] = pck||ntpck;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        long long target = sum/2;
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return f(n-1,target,nums,dp);
    }
};