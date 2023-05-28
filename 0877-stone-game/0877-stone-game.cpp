class Solution {
public:
    int f(int i,int j,int turn,vector<int>& piles,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(turn){
            int first = piles[i] + f(i+1,j,0,piles,dp);
            int last = piles[i] + f(i,j-1,0,piles,dp);
            return dp[i][j] = max(first , last);
        }
        else{
            int first = piles[i] + f(i+1,j,1,piles,dp);
            int last = piles[i] + f(i,j-1,1,piles,dp);
            return dp[i][j] = min(first , last);
        }
        return 0;
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int alice_score = f(0,n-1,1,piles,dp); 
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += piles[i];
        }
        int bob_score = sum - alice_score;
        return alice_score > bob_score;
    }
};