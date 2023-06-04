class Solution {
public:
     bool dfs(int i,int col,vector<int>& color,vector<vector<int>>& graph){
        color[i] = 1 - col;
        for(int node : graph[i]){
            if(color[node] != -1){
                if(color[node] == color[i]) return false;
            }
            else{
                if(!dfs(node,color[i],color,graph)) return false;
            }
        }
         return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<graph.size();i++){
           if(color[i]==-1){
               if(!dfs(i,0,color,graph)) return false;
           }
        }   
        return true;
    }
};