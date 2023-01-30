class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                     dp[n-1][m-1]=grid[n-1][m-1];
                     continue;
                }
                int right = 1e9;
                if(j<m-1) right= grid[i][j] +  dp[i][j+1];
                int down = 1e9;
                if(i<n-1) down = grid[i][j] + dp[i+1][j];
                dp[i][j] = min(right,down);
            }
        }
        return dp[0][0];
    }
};