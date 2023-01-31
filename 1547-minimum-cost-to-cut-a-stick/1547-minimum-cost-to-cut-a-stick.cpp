class Solution {
public:
    long long f(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long mini=INT_MAX;
        for(int k=i ; k<=j ;k++){
            long long ans= cuts[j+1]- cuts[i-1] +  f(i,k-1,cuts,dp) +
                f(k+1,j,cuts,dp);
            mini = min(ans,mini);
        }
        return  dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        int s=cuts.size();
        vector<vector<int>> dp(s,vector<int> (s,-1));
        int last_cut=cuts.size();
       return f(1,cuts.size()-2,cuts,dp); 
    }
};