class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<int,int>> q;
        // vector<int> r = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 };
        // vector<int> c = {-1 , 0 , 1 , -1 , 1 , -1,  0 , 1 };
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1,             -1},{-1, 1}};
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(x == n-1 && y == n-1 )  return grid[x][y];
            for(auto direction : directions){
            int nx = x + direction[0];
            int ny = y + direction[1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                q.push(make_pair(nx,ny));
                grid[nx][ny] = grid[x][y] + 1;
            }
        }
            q.pop();  
        }
        return -1;;
    }
};