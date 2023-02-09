class Solution {
public:
    long long f(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        long long ans=INT_MAX;
        for(int k=1; k<=nums[i];k++){
            ans = min(ans,1 + f(i+k,n,nums,dp));
        }
       return dp[i] = ans ;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> dp(n,-1);
         return f(0,nums.size()-1,nums,dp);
    }
};
