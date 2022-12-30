class Solution {
public:
  void f(int node,int n,vector<vector<int>>& graph,vector<vector<int>>&     res,vector<int> temp){
        if(node==n){
            temp.push_back(n);
            res.push_back(temp);
            return;
        }
      temp.push_back(node);
      for(int i:graph[node]){
          f(i,n,graph,res,temp);
      }
      
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n=graph.size();
        f(0,n-1,graph,res,{});
        return res;
    }
};