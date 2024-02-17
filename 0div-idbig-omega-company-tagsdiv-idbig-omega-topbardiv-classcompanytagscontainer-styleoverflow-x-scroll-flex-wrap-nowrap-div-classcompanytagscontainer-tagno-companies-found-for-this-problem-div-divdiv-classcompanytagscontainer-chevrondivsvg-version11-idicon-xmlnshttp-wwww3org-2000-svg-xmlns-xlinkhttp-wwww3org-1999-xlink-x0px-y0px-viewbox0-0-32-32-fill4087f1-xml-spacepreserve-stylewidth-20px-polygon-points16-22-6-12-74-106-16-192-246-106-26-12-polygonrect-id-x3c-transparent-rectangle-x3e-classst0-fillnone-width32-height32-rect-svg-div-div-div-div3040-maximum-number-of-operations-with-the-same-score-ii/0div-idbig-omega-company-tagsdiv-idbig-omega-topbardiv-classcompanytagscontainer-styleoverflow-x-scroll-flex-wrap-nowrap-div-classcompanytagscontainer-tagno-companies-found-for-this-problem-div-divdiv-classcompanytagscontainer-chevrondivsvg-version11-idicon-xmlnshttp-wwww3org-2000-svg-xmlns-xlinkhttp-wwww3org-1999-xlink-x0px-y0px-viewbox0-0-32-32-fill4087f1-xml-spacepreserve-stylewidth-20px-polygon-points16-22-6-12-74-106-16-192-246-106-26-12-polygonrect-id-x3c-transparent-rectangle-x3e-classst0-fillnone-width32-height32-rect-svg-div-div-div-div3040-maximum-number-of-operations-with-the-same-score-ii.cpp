class Solution {
public:
    int dfs(int i, int j, vector<int>& nums, int cas, vector<vector<int>>& dp){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int main_ss = 0 , main_se = 0 , main_ee = 0;
        if(nums[i] + nums[i+1] == cas){
            main_ss = 1 + dfs(i+2,j,nums,cas,dp);
        }
        if(nums[i] + nums[j] == cas){
            main_se = 1 + dfs(i+1,j-1,nums,cas,dp);
        }
        if(nums[j] + nums[j-1] == cas){
            main_ee = 1 + dfs(i,j-2,nums,cas,dp);
        }
        return dp[i][j] = max(main_ss , max(main_se, main_ee));
    }
    int maxOperations(vector<int>& nums) {
       int n = nums.size();
        if(n < 4) return 1;
        int case1 = nums[0] + nums[1];
        int case2 = nums[0] + nums[n-1];
        int case3 = nums[n-2] + nums[n-1];
        
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp3(n+1,vector<int>(n+1,-1));
        
        int ans1 = dfs(2, n-1, nums, case1, dp1);
        int ans2 = dfs(1, n-2, nums, case2, dp2);
        int ans3 = dfs(0, n-3, nums, case3, dp3);
        return max(ans1 , max(ans2, ans3)) + 1;
    }
};