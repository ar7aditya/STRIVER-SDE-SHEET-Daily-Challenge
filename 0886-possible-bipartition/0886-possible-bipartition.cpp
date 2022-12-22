class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> color(n+1,-1);
        vector<int> adj[n+1];
        for(auto p:dislikes){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        for(int node=1;node<=n;node++){
            if(color[node]==-1){
                
                if(cycle(node,adj,color)){
                    return false; 
                }
            }
        }
        return true;
    }
    bool cycle(int node,vector<int> adj[], vector<int> &color){
        if(color[node]==-1){
            color[node]=1;
        }
        for(int child:adj[node]){
            if(color[child]==-1){
                color[child]=1-color[node];
                if(cycle(child,adj,color)){
                    return true; 
                }
            }
            else if(color[child]==color[node]){
                return true;
            }
        }
        return false;
    }
};