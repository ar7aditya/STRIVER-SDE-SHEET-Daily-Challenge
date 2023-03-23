class Solution {
public:
    void dfs(int i,vector<bool>& vis,vector<vector<int>>& adj){
        vis[i] = true;
        for(auto node : adj[i]){
            if(!vis[node]){
                dfs(node,vis,adj);
            }
        }
        return ;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(n>size+1) return -1;
        vector<vector<int>> adj(n);
         for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int ans = 0;
        vector<bool> vis(n, false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans - 1;
    }
};
// BFS
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //     vis[i] = 1;
        //     q.push(i);
        //     while(!q.empty()){
        //         int cur = q.front();
        //         q.pop();
        //         for(auto i : adj[cur]){
        //             if(!vis[i]) {
        //                 vis[i] = 1;
        //                 q.push(i);
        //             }
        //         }
        //     }
        //         ans++;
        //     }
        // }
        