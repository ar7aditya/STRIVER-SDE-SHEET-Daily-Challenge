class Solution {
public:
    int dp[100001][2];
    int maxSubArray(vector<int>& nums) { 
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0, false);
    }
    int solve(vector<int>& A, int i, bool mustPick) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;       
        if(dp[i][mustPick] != -1) return dp[i][mustPick];
        if(mustPick)
            return dp[i][mustPick] = max(0, A[i] + solve(A, i+1, true));   
        return dp[i][mustPick] = max(solve(A, i+1, false), A[i] + solve(A, i+1, true));   
    }
};