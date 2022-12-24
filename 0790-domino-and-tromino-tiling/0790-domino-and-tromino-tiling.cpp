class Solution {
public:
    const int mod=1e9+7;
    long long f(int i,int n, bool pgap,vector<vector<int>>& dp){
        if(i>n) return 0;
        if(i==n) return !pgap;
        if(dp[i][pgap]!=-1) return dp[i][pgap];
        if(!pgap)
return dp[i][pgap]=(f(i+1,n,false,dp) + 2*f(i+2,n,true,dp) + f(i+2,n,false,dp)) % mod;
        return dp[i][pgap]= (f(i+1,n,false,dp)+f(i+1,n,true,dp)) % mod;
    }
    int numTilings(int n) {
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return f(0,n,false,dp);
    }
};