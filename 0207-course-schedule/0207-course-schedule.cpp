class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        int a,b;
        for(int i=0;i<pre.size();i++){
            a=pre[i][0];
            b=pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;     
        }
        queue<int> q;
        int k=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {q.push(i);k++;}
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0) {q.push(i);k++;}
            }
        }
        return k==n;
    }
};