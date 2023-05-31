class Solution {
public:
    long long int dp[101][101][2]; //idx, M, turn
    int rec(vector<int>&piles, int i, int M, int turn){
        if(i == piles.size())
            return 0;
        if(dp[i][M][turn] != -1)
            return dp[i][M][turn];
        if (turn == 0){
            int ret = 0;
            int currScore = 0;
            for(int x = 1; x <= 2*M; x++){
                if (i + x - 1 == piles.size()) break;
                currScore += piles[i + x - 1];
                ret = max(ret, currScore + rec(piles, i + x, max(M, x), 1));
            }
            return dp[i][M][turn] = ret;
        } else {
            int ret = INT_MAX;
            for(int x = 1; x <= 2*M; x++){
                if (i + x - 1 == piles.size()) break;
                ret = min(ret, rec(piles, i + x, max(M, x), 0));
            }
            return dp[i][M][turn] = ret;
        }
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        return rec(piles, 0, 1, 0);
    }
};