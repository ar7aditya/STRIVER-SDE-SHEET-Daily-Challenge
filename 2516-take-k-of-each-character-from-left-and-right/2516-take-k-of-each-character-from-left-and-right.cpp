class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k*3>s.size()) return -1;
        int n=s.size();
        int ca=0,cb=0,cc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') ca++;
            else if(s[i]=='b') cb++;
            else cc++;
        }
        if(ca<k || cb<k || cc<k) return -1;
        int i=n-1,j=n-1,ans=INT_MAX;
        while(i>=0){
            if(s[i]=='a') ca--;
            else if(s[i]=='b') cb--;
            else cc--;
            while(ca<k || cb<k || cc<k){
                if(s[j]=='a') ca++;
                else if(s[j]=='b') cb++;
                else cc++;
                j--;
            }
            ans=min(ans,i+n-1-j);
            i--;
        }
        return ans;
    }
};