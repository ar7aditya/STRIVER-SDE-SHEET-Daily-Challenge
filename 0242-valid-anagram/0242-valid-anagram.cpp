class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
      unordered_map<char,int> mp;
        for(char i:s){
            mp[i]++;
        }
        for(char i:t){
            mp[i]--;
            if(mp[i]<0) return false;
        }
        return true;
    }
};