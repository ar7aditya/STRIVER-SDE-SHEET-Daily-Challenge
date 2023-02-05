class Solution {
public:
    bool f(int i ,int j,vector<vector<int>>& grid){
        if(grid[i][j]==0) return false;
        if( i==0 && j==0 ){ 
            return true;
        }
        grid[i][j]=0;
        if(j>0 && f(i,j-1,grid) ) return true;
        if(i>0 && f(i-1,j,grid) ) return true;;
        return false;
        
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m=grid.size() ;
        int n=grid[0].size();
        bool is_connected = f(m-1,n-1,grid);
        if(!is_connected) return true;
        
        grid[0][0]=1;
        grid[m-1][n-1]=1;
        is_connected = f(m-1,n-1,grid);
         if(!is_connected) return true;
         return false;
        
    }
};