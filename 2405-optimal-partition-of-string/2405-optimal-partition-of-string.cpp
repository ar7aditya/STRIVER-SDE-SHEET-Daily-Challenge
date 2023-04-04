class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if( mp[s[i]]>0 ){
                mp.clear();
                ans++;
            }
            mp[s[i]]++;
        }
        return ans + 1;
    }
};