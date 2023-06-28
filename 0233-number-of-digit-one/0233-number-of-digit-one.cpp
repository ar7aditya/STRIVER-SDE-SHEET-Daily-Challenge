class Solution {
public:
    int dp[10][2][1<<10];
    vector<int> num;
    int solve(int pos,int tight,int rep,long long count)
    {
        if(pos == num.size())
        {
            return count;
        }
        int &ans = dp[pos][tight][count];
        if(ans != -1) return ans;

        int k = 9;
        if(tight) k = num[pos];
        int res=0;
        for(int i=0;i<=k;i++)
        {
            int nt = (tight == 1 && i == k);
            if(i == 1){
                res += solve(pos+1,nt,rep,count+1);
            }
            else{
                res += solve(pos+1,nt,rep,count);
            }
        }
        ans = res;
        return res;
    }
    int countDigitOne(int N) {
         while(N){
            num.push_back(N%10);
            N/=10;
        }
        reverse(num.begin(),num.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,0);
    }
};