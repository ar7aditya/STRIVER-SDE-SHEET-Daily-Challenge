class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        bool one_in_s=false;
        bool one_in_t=false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1') one_in_s=true;
             if(t[i]=='1') one_in_t=true;
        }
        return one_in_s==one_in_t;
    }
};