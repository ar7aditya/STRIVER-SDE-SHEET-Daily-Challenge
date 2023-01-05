class Solution {
public:
    void kmp(string s,vector<int>& lps){
        int i=1,prevlen=0;
        while(i<s.size() && prevlen<s.size()){
            if(s[i]==s[prevlen]){
                lps[i]=prevlen+1;
                prevlen++;
                i++;
            }
            else if(prevlen){
               prevlen=lps[prevlen-1]; 
            }
            else{
                i++;
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        if(s.size()==1) return false;
        vector<int> lps(s.size(),0);
        kmp(s,lps); 
        return lps[len - 1] && len % (len - lps[len - 1]) == 0;
    }
};