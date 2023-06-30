class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int cur_ans = 0;
        int i = 0;
        while(i < s.size() && mp.find(s[i]) == mp.end()){
            mp[s[i]]++;
            cur_ans++;
            i++;
        }
        int ans = cur_ans;
        int j = i;
        i = 0;
        for(; j < s.size(); j++){
            char x = s[j];
            if(mp.find(x) != mp.end()){
                while(i < s.size() && mp.find(x) != mp.end()){
                    mp[s[i]]--;
                    mp.erase(s[i]);
                    i++;
                    cur_ans--;
                }
            }
            cur_ans++;
            mp[x]++;
            ans = max(ans , cur_ans);
        }
        return ans;
    }
};