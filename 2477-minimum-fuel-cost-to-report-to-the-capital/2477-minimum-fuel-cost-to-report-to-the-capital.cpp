class Solution {
public:
    long long ans = 0;
    int dfs(int i , vector<vector<int>>& adj , int seats , vector<int>& vis){
        vis[i] = 1;
        long long count = 0;
        for(auto node : adj[i]){
            if(!vis[node]){
                count += dfs(node,adj,seats,vis);
            }
        }
        count += (long long)1;
        long long x = ((count+seats-(long long)1)/seats);
        if(i!=0) ans += x;
        return count;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ans = 0;
        int n = roads.size();
        if(n==0) return 0;
        
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            int x = roads[i][0];
            int y = roads[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> vis(n+1,0);
        dfs(0,adj,seats,vis);
        return ans;
    }
};