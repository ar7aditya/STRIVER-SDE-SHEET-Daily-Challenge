class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()<n-1) return -1;
       unordered_map<int,int> mp;
        for(int i=1;i<=n;i++){
            mp[i]=0;
        }
       int a,b;
        for(int i=0;i<trust.size();i++){
           a=trust[i][0];
            b=trust[i][1];
            if(mp.find(a)!=mp.end()) mp.erase(a);
            if(mp.find(b)!=mp.end()) mp[b]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            int ans=itr->first;
            int trusti=itr->second;
            if(trusti==n-1) return ans;
        }
        return -1;
    }
};