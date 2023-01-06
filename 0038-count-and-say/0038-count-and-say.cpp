class Solution {
public:
    string countAndSay(int n,string s="1") {
        if(n==1) return s;
        int len=s.size();
        int i=0;
        string ans = "";
        while(i<len){
            int j=i;
            while(i<len && s[i]==s[j]) i++;
            ans+=to_string(i-j)+s[j];    
        }
        return countAndSay(n-1,ans);
    }
};

