class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i=0;i<p.size();i++){
            int u = p[i][1];
            int v = p[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> vis(n);
        queue<int> q;
        
        int k = 0;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                k++;
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int node : adj[cur]){
                indegree[node]--;
                if(indegree[node] == 0 && vis[node] == 0)  {
                    q.push(node);
                    k++;
                    vis[node] = 1;
                }
            }
        }
        return k == n;
    }
};