class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(char i : magazine){
            mp[i]++;
        }
        for(char i : ransomNote){
            if(mp.find(i) == mp.end()) return false;
            mp[i]--;
            if(mp[i] == 0) mp.erase(i);
        }
        return true;
    }
};