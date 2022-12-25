class Solution {
public:
    int isPalindrome(string S){
        for (int i = 0; i < S.length() / 2; i++) {
            if (S[i] != S[S.length() - i - 1]) {
                return 0;
            }
        }
        return 1;
    }
    
    void f(int i,string s,vector<string>& temp,vector<vector<string>>& ans){
        if(i == s.size()) {
            ans.push_back(temp);
            return;
        }
        for(int k=i;k<s.size();k++){
            string r = s.substr(i, k-i+1);
             if(isPalindrome(r)) {
                temp.push_back(r);
                f(k+1,s,temp,ans);
                 temp.pop_back();
                
           }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string> > ans;
        vector<string> path;
        f(0,s,path,ans); 
        return ans;
    }
};
