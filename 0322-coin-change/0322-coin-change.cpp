class Solution {
public:    
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        
        //base cond
        for(int a=0;a<=amount;a++){
           if(a%coins[0]==0) dp[0][a] = a/coins[0];
            else dp[0][a] =INT_MAX;
        }
        
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                long long exc=dp[i-1][a];
                long long inc=1e9;
                if(a>=coins[i]) inc=1+dp[i][a-coins[i]];
                dp[i][a]=min(exc,inc);  
            }
        }
        if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
    }
};