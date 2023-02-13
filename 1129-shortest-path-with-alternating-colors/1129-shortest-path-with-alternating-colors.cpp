class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		vector<vector<pair<int,int>>> graph(n);
        for(auto edge: red_edges)
            graph[edge[0]].emplace_back(edge[1],0);  
        for(auto edge: blue_edges)
            graph[edge[0]].emplace_back(edge[1],1); 
        vector<int> dist(n,-1); 
        
     queue<vector<int>> q;
         q.emplace(vector<int>{0,0,-1});
        
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            int node = cur[0];
            int step = cur[1];
            int prevCol = cur[2];
            dist[node] = dist[node] != -1 ? dist[node] : step;
            
            for(auto &adj : graph[node]) {
                int nextNode = adj.first;
                int color =  adj.second;
                if(prevCol != color && nextNode != -1) {
                    q.emplace(vector<int>{nextNode, step + 1, color});
                    adj.first = -1;
                }
            }
        }
        
        return dist;
    }
};
