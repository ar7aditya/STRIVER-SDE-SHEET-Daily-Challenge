class Solution {
public:
    void dfs(int i,vector<int>& vis,vector<vector<int>>& rooms){
        vis[i] = 1;
        for(int j : rooms[i]){
            if(vis[j] != 1){
                dfs(j,vis,rooms);
            }
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(0,vis,rooms);
        
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};