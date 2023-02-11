class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==n*n || q.empty()) return -1;
        int ans = 0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [ i , j ] = q.front();
                q.pop();
                if(i>0 && grid[i-1][j]==0) {
                    grid[i-1][j]= 1;
                    q.push({i-1,j});
                } 
                if(j>0 && grid[i][j-1]==0) {
                    grid[i][j-1]= 1;
                    q.push({i,j-1});
                }
                if(i<n-1 && grid[i+1][j]==0) {
                    grid[i+1][j]= 1;
                    q.push({i+1,j});
                }
                if(j<n-1 && grid[i][j+1]==0) {
                    grid[i][j+1]= 1;
                    q.push({i,j+1});
                }
            }
            ans++;
        }
        return ans-1;
    }
};