class Solution {
public:
    int dp[30][401][2];
    int MOD = 1e9 + 7;
    int get_digit_sum(string n){
        int sum = 0;
        for(char i : n){
            sum += (i - '0');
        }
        return sum;
    }
    
    int getCount(int i,string num,int min_sum, int max_sum,int tight,int curSum){
        if(i == num.size()){
            if(curSum >= min_sum && curSum <= max_sum) return 1;
            return 0;
        }
        if(dp[i][curSum][tight] != -1) return dp[i][curSum][tight];
        int ans = 0;
        int end = (tight == 1) ? num[i]-'0' : 9;
        for(int cur = 0;cur<=end;cur++){
            int new_tight = (tight == 1 && cur == end) ? 1 : 0;
            ans += getCount(i+1,num,min_sum,max_sum,new_tight,curSum+cur);
            ans = ans % MOD;
        }
        return dp[i][curSum][tight] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        
        memset(dp, -1, sizeof(dp));
        int ans = getCount(0,num2,min_sum,max_sum,1,0);
        
        memset(dp, -1, sizeof(dp));
        ans -= getCount(0,num1,min_sum,max_sum,1,0);
        
        int temp = get_digit_sum(num1);
        if(temp >= min_sum && temp <= max_sum){
            ans++;
        }
        ans %= MOD;
        return (ans + MOD) % MOD;
    }
};