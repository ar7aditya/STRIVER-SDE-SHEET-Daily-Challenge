class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        if(i<0 || i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='0'||vis[i][j]==1)                return;
        vis[i][j]=1;
        grid[i][j]='0';
        dfs(i-1,j,vis,grid);
        dfs(i+1,j,vis,grid);
        dfs(i,j-1,vis,grid);
        dfs(i,j+1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    k++;
                }
            }
        }
        return k;
    }
};