class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1);
        vector<int>out(n+1);
        for(vector<int> & t : trust){
            int u = t[0];
            int v = t[1];
            out[u]++;
            in[v]++;
        }
        
        for(int i = 1 ; i <= n ; i++){
            if(out[i]==0 && in[i] == n - 1) return i;
        }
        
        return -1;
    }
};