class Solution {
public:
    int f(int i,int walls,vector<int>& cost,vector<int>& time, vector<vector<int>>& dp){
        if(walls <= 0) return 0;
        if(i < 0 ) return 1e9;
        if(dp[i][walls] != -1) return dp[i][walls];
        int pick = cost[i] + f(i-1,walls - time[i] - 1,cost,time,dp); 
        int not_pick = 0 + f(i-1,walls,cost,time,dp);
        return dp[i][walls] = min(pick ,not_pick );
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return f(n-1,n,cost,time,dp);  
    }
};