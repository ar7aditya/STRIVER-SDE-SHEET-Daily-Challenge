class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int> next(m+1) ,cur(m+1);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
        if(s1[i]==s2[j])  cur[j]=1+next[j+1];
        else cur[j] = max( next[j] , cur[j+1] );
            }
            next=cur;
        }
        return cur[0];
    }
};