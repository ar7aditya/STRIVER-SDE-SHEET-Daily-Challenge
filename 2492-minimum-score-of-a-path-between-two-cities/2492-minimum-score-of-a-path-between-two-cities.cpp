class Solution {
public:
    unordered_map<int,int> nodes;
    void f(int i,vector<vector<pair<int,int>>>& adj,vector<int>& vis){
        vis[i] = 1;
        nodes[i] = 1;
        for(auto next : adj[i]){
            int next_des = next.first;
            int next_dist = next.second;
            if(!vis[next_des]){
            f(next_des,adj,vis);
            }
        }
        return ;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<roads.size();i++){
            int x = roads[i][0];
            int y = roads[i][1];
            int dist = roads[i][2];
            adj[x].push_back({y,dist});
            adj[y].push_back({x,dist});
        }
        vector<int> vis(n+1,0);
        f(1,adj,vis);
        int ans = INT_MAX;
        
        for(int i=0;i<roads.size();i++){
            int x = roads[i][0];
            int y = roads[i][1];
            int dist = roads[i][2];
            if(nodes.count(x)>0 || nodes.count(y)>0){
                ans = min( ans , dist);
            }
        }
        return ans;
    }
};