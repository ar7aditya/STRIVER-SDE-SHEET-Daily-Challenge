// class Solution {
// public:
//     int f(int i,int j,vector<vector<int>>& piles, int k){
//         if(k==0) return 0;
//         if(i==piles.size()) return 0;
//         if(j==piles[i].size()) return 0;
//         int pick = 0;
//         int ntpick = 0;
//         pick += piles[i][j] + f(i,j+1,piles,k-1);
//         ntpick += f(i+1,j,piles,k);
//         return max(pick , ntpick);
//     }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         return f(0,0,piles,k);
//     }
// };
class Solution
{
    public:
        int maxValueOfCoins(vector<vector < int>> &p, int k)
        {
            int n = p.size();
            vector<vector < int>> dp(n + 1, vector<int> (k + 1, -1));
            return solve(0, dp, p, k);
        }
 int solve(int index, vector<vector < int>> &dp, vector< vector< int>> &p, int k)
        {
            if (index >= p.size())
                return 0;
            int maxi = 0, sum = 0;
            if (dp[index][k] != -1)
                return dp[index][k];
            maxi = max(maxi, solve(index + 1, dp, p, k));
            for (int i = 0; i < p[index].size(); i++)
            {
                sum += p[index][i];
                if (k - (i + 1) >= 0)
                    maxi = max(maxi, sum + solve(index + 1, dp, p, k - (i + 1)));
            }
            return dp[index][k] = maxi;	
        }
};