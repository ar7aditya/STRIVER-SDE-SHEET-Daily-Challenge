class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int k=0;
        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) pq.push({i,j});
                 if(grid[i][j]==1) k++;
            }
        }
        if(k==0) return 0;
         if(k!=0 && pq.empty()) return -1; 
        int ans=0;
        while(!pq.empty()){
            int s=pq.size();
            for(int z=0;z<s;z++){
                int i=pq.front().first;
                int j=pq.front().second;
                pq.pop(); 
        if(j<m-1) { if(grid[i][j+1]==1) {grid[i][j+1]=2; pq.push({i,j+1});k--;}}
        if(j>0)   { if(grid[i][j-1]==1) {grid[i][j-1]=2; pq.push({i,j-1});k--;}}
        if(i<n-1) { if(grid[i+1][j]==1) {grid[i+1][j]=2; pq.push({i+1,j});k--;}}
        if(i>0)   { if(grid[i-1][j]==1) {grid[i-1][j]=2; pq.push({i-1,j});k--;}}
            } 
            if(!pq.empty()) ans++;
        }
        if(k==0) return ans;
        return -1;
    }
};