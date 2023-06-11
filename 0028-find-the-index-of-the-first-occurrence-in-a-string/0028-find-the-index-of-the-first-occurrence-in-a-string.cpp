class Solution {
public:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
    
    int strStr(string s, string p) {
        if(p.size() == 0) return 0;
        vector<int> lps = kmpProcess(p);
        int j = 0;
        int i = 0;
        while(i < s.size()){
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