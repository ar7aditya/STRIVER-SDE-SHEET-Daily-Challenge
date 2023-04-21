class Solution {
public:
    int mod = 1e9+7;
     int dp[102][102][102];
    int f(int i,int n,int minProfit,vector<int>& group, vector<int>& profit,int            temp_profit){
        if(i==group.size()){
            if(temp_profit>=minProfit) return 1;
            return 0;
        }
        int inc =0 , exc = 0;
         if(dp[i][n][temp_profit]!=-1) return  dp[i][n][temp_profit];
if(n>=group[i]) inc =f(i+1,n-group[i],minProfit,group,profit,min(temp_profit+profit[i] , minProfit));
    exc = f(i+1,n,minProfit,group,profit,temp_profit);
        return  dp[i][n][temp_profit] = (inc  % mod + exc  % mod )%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>&           profit) {
        memset(dp,-1,sizeof(dp));
       return f(0,n,minProfit,group,profit,0); 
    }
};