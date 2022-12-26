class Solution {
public:
    vector<vector<int>> mark(int row,int col,vector<vector<int>> vis){
        int n=vis.size();
        for(int j=0;j<n;j++) vis[row][j]=1;
        for(int j=0;j<n;j++) vis[j][col]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==row || j==col) continue;
                if(abs(i-row)==abs(j-col))
                    vis[i][j]=1;
            }
        }
        return vis;
    }
    
    void f(int i,int n, vector<vector<int>> vis,vector<vector<string>>& ans,vector<string> temp){
        if(i==n) {
            ans.push_back(temp);
            return;
        }
        for(int k=0;k<n;k++){
            if(vis[i][k]==1) continue;
            string s="";
            s.insert(0, n-1, '.');
            s.insert(k, "Q");
            temp.push_back(s);
            f(i+1,n,mark(i,k,vis),ans,temp);
            temp.pop_back();
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<string> temp;
        f(0,n,vis,ans,temp);
        return ans;
    }
};
