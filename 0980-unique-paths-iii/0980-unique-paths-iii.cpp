class Solution {
public:
    int f(int i,int j,int count,int lasti,int lastj,int m,int n,vector<vector<int>>& grid,vector<vector<int>> vis){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1 || vis[i][j]==1) return 0;
        if(i==lasti && j==lastj){
            count--;
            if(count==0) return 1;
            return 0;
        }
        vis[i][j]=1;
        int a=f(i+1,j,count-1,lasti,lastj,m,n,grid,vis);
        int b=f(i-1,j,count-1,lasti,lastj,m,n,grid,vis);
        int c=f(i,j+1,count-1,lasti,lastj,m,n,grid,vis);
        int d=f(i,j-1,count-1,lasti,lastj,m,n,grid,vis);
        vis[i][j]=0;
        return (a+b+c+d);
        
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int strow,stcol,endrow,endcol;
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  strow=i  ;stcol=j;
                }
                if(grid[i][j]==2){
                  endrow=i  ;endcol=j;
                }
                if(grid[i][j]!=-1){
                  k++;
                }
            }
        }
        
        return f(strow,stcol,k,endrow,endcol,m,n,grid,vis);
    }
};