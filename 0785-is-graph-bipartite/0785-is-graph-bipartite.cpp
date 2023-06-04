class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> color(n);
        vector<int> vis(n);
        queue<pair<int,int>> q;   // node color
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push({i,0});
                while(!q.empty()){
                    int node = q.front().first;
                    int col = q.front().second;
                    vis[node] = 1;
                    color[node] = col;
                    q.pop();
                    for(int next : adj[node]){
                        if(vis[next] == 1){
                            if(color[next] == col) return false;
                        }
                        else{
                            q.push({next , 1 - col});
                        }
                    }
                }
            }
        }
        return true;
    }
};