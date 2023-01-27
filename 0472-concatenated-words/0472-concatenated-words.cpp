class Solution {
public:
    set<string> mp;
        
    bool f(string s){
        for(int i=1;i<s.size();i++){
        string suffix=s.substr(i);
           if(mp.find(s.substr(0,i))!=mp.end() && (mp.find(suffix)!=mp.end() ||                         (f(suffix)))){
        return true;
        }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        for(int i=0;i<n;i++){
            mp.insert(words[i]);
        }
        for(auto it : mp){
            if(f(it)){
                res.push_back(it);
            }
        }
        return res;
    }
};