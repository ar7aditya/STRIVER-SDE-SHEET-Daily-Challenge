class Solution {
public:
    bool dfs(int node ,vector<int>& vis,vector<int>& dfsvis,vector<vector<int>>& adj){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(int i : adj[node]){
            if(dfsvis[i] != 0) return true;
            else{
                 if(vis[i] == 0){
                     if(dfs(i,vis,dfsvis,adj)) return true;
                 }
            }
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
            int u = p[i][1];
            int v = p[i][0];
            adj[u].push_back(v);
        }
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,dfsvis,adj)) return false;
            }
        }
        
        return true;
    }
};