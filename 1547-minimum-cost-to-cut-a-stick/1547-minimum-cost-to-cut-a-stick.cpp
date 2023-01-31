class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        int s=cuts.size();
        vector<vector<int>> dp(s,vector<int> (s,0));
        for(int i=s-2;i>=1;i--){
            for(int j=i;j<=s-2;j++){
                 int mini=INT_MAX;
                for(int k=i ; k<=j ;k++){
                    int ans= cuts[j+1]- cuts[i-1]+dp[i][k-1] + dp[k+1][j];
                    mini = min(ans,mini);
                }
               dp[i][j] = mini;
            }
        }
       return dp[1][s-2];
    }
};