class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 1e6;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[grid.size()-1][grid[0].size()-1];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right = grid[i][j] +  f(i,j+1,grid,dp);
        int down = grid[i][j] + f(i+1,j,grid,dp);
        return dp[i][j] = min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(0,0,grid,dp);
    }
};