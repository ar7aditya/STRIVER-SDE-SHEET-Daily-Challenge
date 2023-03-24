class Solution {
public:
    int f(int i,vector<int>& vis,vector<vector<int>>& adj){
        vis[i] = 1;
        auto change = 0;
        for(int node : adj[i]){
            if(!vis[abs(node)])
             change += f(abs(node),vis,adj) + (node>0);
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto &i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        return f(0,vis,adj);
            
    }
};