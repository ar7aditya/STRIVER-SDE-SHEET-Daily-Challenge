class Solution {
public:
    int f(int i,int n,vector<int>& p,int isbuy,vector<vector<int>>& dp){
        if(i>n) return 0;
        if(i==n){
            if(isbuy) return 0;
            return p[i];
        }
        if(dp[i][isbuy]!=-1) return dp[i][isbuy];
        if(isbuy){
            return dp[i][isbuy]= max(p[i]*-1 + f(i+1,n,p,0,dp),f(i+1,n,p,1,dp));
        }
        else 
            return  dp[i][isbuy]=  max(p[i] + f(i+2,n,p,1,dp),f(i+1,n,p,0,dp));
    }
    int maxProfit(vector<int>& p) {
        vector<vector<int>> dp(p.size() ,vector<int> (2,-1));
        return f(0,p.size()-1,p,1,dp);
    }
};