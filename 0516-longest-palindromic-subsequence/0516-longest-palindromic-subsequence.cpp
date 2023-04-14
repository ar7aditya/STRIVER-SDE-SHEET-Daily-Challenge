class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n=s1.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        string s2 = "";
        for(int i=n-1;i>=0;i--) 
        {
            s2.push_back(s1[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
              if(s1[i-1]==s2[j-1])  dp[i][j] = 1+ dp[i-1][j-1];
              else  dp[i][j]= max(dp[i-1][j],dp[i][j-1]);  
            }
        }
        return dp[n][n];
    }
};