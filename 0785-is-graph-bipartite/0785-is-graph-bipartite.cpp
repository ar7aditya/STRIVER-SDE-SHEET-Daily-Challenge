class Solution {
public:
    bool dfs(int node,int par,vector<int>& vis,vector<vector<int>>& graph){
        vis[0]=0;
            for(int i : graph[node]){
                if(vis[i]==-1){
                    vis[i]=1-vis[node];
                    if(!dfs(i,node,vis,graph)) return false;
                }
                else if(i!=par){
                  if(vis[node]==vis[i]) return false;  
                }
            }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
      
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
           if(color[i]==-1){
               if(!dfs(i,-1,color,graph)) return false;
           }
        }   
        return true;
    }
};