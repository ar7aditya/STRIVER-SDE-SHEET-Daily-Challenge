class Solution {
public:
    int solve(int i,int n,vector<int>& pp,vector<int>& total_count,int                           seg,vector<vector<int>>& dp){
        if(i==n) return 0;
        if(dp[i][seg]!=-1) return dp[i][seg];
        if(seg<=1){
            return dp[i][seg] =                                     max(total_count[i]+solve(i+total_count[i],n,pp,total_count,seg+1,dp)  ,
            solve(i+1,n,pp,total_count,seg,dp));
        }
        return 0;
    }
    int maximizeWin(vector<int>& pp, int k) {
        int n = pp.size();
        vector<int> total_count(n);
        int l=0,r=0;
        if(k >= pp[n-1]) return n;
        while(r<n){
            while(r<n && pp[r] - pp[l] <=k ) r++;
            total_count[l] = r - l;
            l++;
        }
        while(l<n){
             total_count[l] = n - l;
             l++;
        }
        vector<vector<int>> dp(n,vector<int> (3,-1));
        return solve(0,n,pp,total_count,0,dp);
    }
};