class Solution {
public:
    int ans = 0;
    int f(int i,int n,vector<int>& p,int M,vector<int>& suffix,vector<vector<int>>& dp){
        if(i==n) return 0;
        if(n - i <= 2*M){
            return suffix[i];
        }
        if(dp[i][M]!=-1) return dp[i][M];
         int tans = 0;
            for(int x=1;x<=2*M;x++){
               tans = max(tans , suffix[i] - f(i+x,n,p,max(x,M),suffix,dp));
            }
        return dp[i][M] = tans;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n);
        suffix[n-1] = piles[n-1];
        for(int i= n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + piles[i];
        }
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,n,piles,1,suffix,dp);
        
    }
};