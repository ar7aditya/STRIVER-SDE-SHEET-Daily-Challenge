class Solution {
public:
    int strStr(string s, string p) {
        int i = 0;
        int j;
        int n = s.size();
        while(i < n){
            if(s[i] == p[0]){
                j = i;
                int k = 0;
                while(k < n && k < p.size()){
                    if(s[j] == p[k]) {
                        k++;
                        j++;
                    }
                    else {
                        break;
                    }
                }
                if(k == p.size()) return i;
            }
            i++;
        }
        return -1;
    }
};