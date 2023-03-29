class Solution {
public:
    int f(int i,int n,vector<int>& v,int time,vector<vector<int>>& dp){
        if(i==n){
           return v[i]*time; 
        }
        if(dp[i][time]!=-1) return dp[i][time];
        int take = 0;
        int nt_take = 0;
        take += v[i]*time + f(i+1,n,v,time+1,dp);
        nt_take += f(i+1,n,v,time,dp);
        return dp[i][time] = max(take , nt_take);
    }
    
    int maxSatisfaction(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        if(v[n-1]<=0) return 0;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,n-1,v , 1 , dp);
    }
};