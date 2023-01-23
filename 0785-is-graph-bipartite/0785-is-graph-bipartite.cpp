class Solution {
public:
    bool bfs(int node,vector<int>& vis,vector<vector<int>>& graph){
        queue<pair<int,int>> q;
        q.push({node,0});
        vis[0]=0;
        while(!q.empty()){
            int par=q.front().first;
            int par_color=q.front().second;
            q.pop();
            for(int i : graph[par]){
                if(vis[i]==-1){
                    vis[i]=1-par_color;
                    q.push({i,vis[i]});
                }
                else if(i!=par){
                  if(par_color==vis[i]) return false;  
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
      
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
           if(color[i]==-1){
               if(!bfs(i,color,graph)) return false;
           }
        }   
        return true;
    }
};