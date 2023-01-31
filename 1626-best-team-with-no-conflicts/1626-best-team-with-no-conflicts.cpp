class Solution {
public:
    int f(int i, vector<pair<int,int>>& v,int prev,vector<vector<int>>& dp){
        if(i==v.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1 || v[prev].second <=v[i].second ) take = v[i].second+f(i+1,v,i,dp);
        int nttk = f(i+1,v,prev,dp);
        return dp[i][prev+1] = max(take , nttk);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n= ages.size();
        vector<pair<int,int>> v;
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        for(int i=0;i<n;i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        return f(0,v,-1,dp);
    }
};