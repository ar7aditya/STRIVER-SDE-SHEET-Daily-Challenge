class Solution {
public:
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,1e9));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int walls = 1;walls <=n ;walls++){
                int not_pick = dp[i-1][walls];
                int pick = cost[i-1] + dp[i-1][max(walls - 1 - time[i-1], 0)];
                dp[i][walls] = min(pick ,not_pick );
            }
        }
        return dp[n][n];
    }
};


