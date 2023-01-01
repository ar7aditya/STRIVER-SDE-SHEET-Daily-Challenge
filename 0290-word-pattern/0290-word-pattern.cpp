class Solution {
public:
    bool wordPattern(string pattern, string s) {
      unordered_map<char,string> mp;
         unordered_map<string,char> mp_s;
        int n=pattern.size();
        vector<string> v;
        istringstream ss(s);
        string word; 
    while (ss >> word)
    {
        v.push_back(word);
    }
        if(v.size()!=n) return false;
        
        for(int i=0;i<n;i++){
            if(mp.count(pattern[i])!=0){
                if(mp[pattern[i]]!=v[i]) return false;
            }
            if(mp_s.count(v[i])!=0){
                if(mp_s[v[i]]!=pattern[i]) return false;
            }
           else{ 
               mp[pattern[i]]=v[i];
               mp_s[v[i]]=pattern[i];
           }
        }
        return true;
    }
};