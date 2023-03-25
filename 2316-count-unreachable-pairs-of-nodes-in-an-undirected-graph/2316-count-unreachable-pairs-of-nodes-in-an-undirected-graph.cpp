class Solution {
public:
    
    long long dfs(int i,vector<int>& vis,vector<vector<int>>& adj,long long& count){
        vis[i] = 1;
        count++;
        for(int node : adj[i]){
            if(!vis[node]){
                dfs(node,vis,adj,count);
            }
        }
        return count;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long temp = 0;
                long long x = dfs(i,vis,adj,temp);
                ans += x*(n-x);
            }
        }
        return ans/2;
    }
};