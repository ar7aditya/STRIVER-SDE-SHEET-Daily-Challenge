class Solution {
public:
    int f(int i,vector<int>& cost,vector<int>& time ,int walls, vector<vector<int>>& dp){
        if(walls <= 0) return 0;
        if(i >= cost.size()) return 1e9;
        if(dp[i][walls] != -1) return dp[i][walls];
        int pick = cost[i] + f(i+1,cost,time,walls - time[i] - 1,dp); 
        int not_pick = 0 + f(i+1,cost,time,walls,dp);
        return dp[i][walls] = min(pick ,not_pick );
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return f(0,cost,time,n,dp);  
    }
};