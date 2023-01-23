class Solution {
public:
   bool iscycle(vector<int> adj[],vector<int> &vis,int id,vector<int>& dfs_vis){
       vis[id]=1;
       dfs_vis[id]=1;
       for(int i:adj[id]){
           if(dfs_vis[i]!=0) return true;
           else {
               if(vis[i]==0){
                if(iscycle(adj,vis,i,dfs_vis)) return true;
           }
           }
       }
       dfs_vis[id]=0;
       return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> per_vis(n,0);
         vector<int> dfs_vis(n,0);
        
        for(int i=0;i<n;i++){
            if(per_vis[i]==0){
            if(iscycle(adj,per_vis,i,dfs_vis))
                return false;
            }
        }
        return true;
    }

};