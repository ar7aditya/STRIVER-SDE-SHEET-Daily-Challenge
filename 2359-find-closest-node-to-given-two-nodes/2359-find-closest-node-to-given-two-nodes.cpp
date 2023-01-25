class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& distance, vector<bool>& visited){
        visited[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 && visited[neighbor] == false) {
            distance[neighbor] = distance[node] + 1;
            dfs(neighbor, edges, distance, visited);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,1e6);
        vector<int> dist2(n,1e6);
         vector<bool> visited1(n, false), visited2(n, false);
        dfs(node1,edges,dist1,visited1);
        dfs(node2,edges,dist2,visited2);
         int ans = -1;
        int minDist = INT_MAX;
        for(int i=0;i<n;i++){
           if(visited1[i] == true && visited2[i] == true && minDist >                                       max(dist1[i], dist2[i])){
                minDist = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};