class Solution {
public:
    void fill_lps(vector<int>& lps,string p){
        int n = p.size();
        int len = 0;
        int i = 1;
        while( i < n){
            if(p[i] == p[len]){
                lps[i++] = ++len;
            }
            else if(len){
                len = lps[len-1];
            }
            else{
                lps[i++] = 0;
            }
        }
    }
    
    int strStr(string s, string p) {
        if(p.size() == 0) return 0;
        
        vector<int> lps(p.size(),0);
        fill_lps(lps,p);
        
        int j = 0;
        int i = 0;
        while(i < s.size()  && j < p.size()){
            if(s[i] == p[j]){
                i++;
                j++;
            }
            if(j == p.size()) return i - j;
            if(i < s.size() && s[i] != p[j]){
                j ? j = lps[j-1] : i++;
            }
        }
        return -1;
    }
};