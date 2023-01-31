class Solution {
public:
    unordered_set<string> mp;
    bool f(int st,string s,vector<int>& dp){
        if(dp[st]!=-1) return dp[st];
        for(int i=st;i<s.size();i++){
            string pre=s.substr(st,i-st);
            string suffix=s.substr(i);
            if( mp.find(pre)!=mp.end() && (mp.find(suffix)!=mp.end() || f(i,s,dp)) ) {
                dp[st]=1;
                return true;
            }
        }
        dp[st]=0;
        return dp[st];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
         for(int i=0;i<wordDict.size();i++){
           mp.insert(wordDict[i]);
       }
        vector<int> dp(1001,-1);
       if(mp.find(s)!=mp.end()) return true;
       if( f(0,s,dp) ) return 1;
       return 0;
    }
};