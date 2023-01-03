class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return 0;
        int l=strs[0].size();
        int c=0;
        for(int i=0;i<l;i++){
            for(int j=1;j<n;j++){
                if(strs[j][i]<strs[j-1][i]) {c++;break;}
            }
        }
        return c;
    }
};