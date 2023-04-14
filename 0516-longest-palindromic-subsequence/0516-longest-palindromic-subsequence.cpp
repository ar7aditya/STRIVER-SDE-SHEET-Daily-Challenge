class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n=s1.size();
        vector<int> prev(n+1,0) , cur(n+1,0);
        string s2 = "";
        for(int i=n-1;i>=0;i--) 
        {
            s2.push_back(s1[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
              if(s1[i-1]==s2[j-1])  cur[j] = 1+ prev[j-1];
              else  cur[j]= max(prev[j],cur[j-1]);  
            }
             prev = cur;
        }
        return cur[n];
    }
};