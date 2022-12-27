//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

bool validcolor(int c,int node,vector<vector<int>>& adj,vector<int>& color,vector<int>& vis){
    for(auto i : adj[node]){
        if(vis[i]==0) continue;
        if(color[i]==c) return false;
    }
    return true;
}

    bool f(int i,vector<vector<int>>& adj,vector<int>& vis, vector<int>& color,int m,int n){
        if(i==n) return true;
        vis[i]=1;
        for(int c=0;c<m;c++){
            if(validcolor(c,i,adj,color,vis)){
            color[i]=c;
                   if(f(i+1,adj,vis,color,m,n)) return true;
                   else color[i]=-1;
            }
          }
            return false;
        }

    bool graphColoring(bool graph[101][101], int m, int n) {
       vector<int> vis(n,0);
       vector<int> color(n,-1);
       vector<vector<int>> adj(n);
       
       for(int i=0;i<n;i++){
           for(int j=i;j<n;j++){
               if(graph[i][j]==1){
               adj[i].push_back(j);
               adj[j].push_back(i);
               }
           }
       }
      return f(0,adj,vis,color,m,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends