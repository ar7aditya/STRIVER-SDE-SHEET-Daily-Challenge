class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int cnt=0;
        vector<int> zero(n+1,0),ones(n+1,0);
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'){
                cnt++;
            }
            zero[i]=cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                cnt++;
            }
            ones[i]=cnt;
        }
        long long ans =INT_MAX;
        for(int i=0;i<=n;i++){
            long long  z= zero[i]+ones[i];
            ans=min(ans,z);
        }
        return ans;
    }
};