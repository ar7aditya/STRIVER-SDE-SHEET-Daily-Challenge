class Solution {
public:
    void dfs(int i,int& len, vector<int>& vis,vector<vector<int>>& adj){
        vis[i] = 1;
        len++;
        for(int& node : adj[i]){
            if(!vis[node]){
                dfs(node,len,vis,adj);
            }
            else return;
        }
        return ;
    }
    int longestCycle(vector<int>& edges) {
       int n = edges.size();
       vector<int> indegree(n);
       vector<vector<int>> adj(n); 
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) {
                adj[i].push_back(edges[i]);
                indegree[edges[i]]++;
            }
        }
        vector<int> vis(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){ 
                q.push(i);
                vis[i] = 1;
            }
        }
        int k = q.size();
        while(!q.empty()){
            int cur_node = q.front();
            q.pop();
            for(int i : adj[cur_node]){
                indegree[i]--;
                if(indegree[i]==0) {
                    q.push(i);
                    vis[i] = 1;
                    k++;
                }
            }
        }
        if(k==n) return -1; 
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int temp = 0;
                dfs(i,temp,vis,adj);
                ans = max(ans , temp);
            }
        }
        return ans;
    }
};