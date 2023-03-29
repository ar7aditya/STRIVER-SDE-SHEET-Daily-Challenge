class Solution {
public:
    string removeStars(string s) {
        int k = 0;
        int n = s.size();
        string temp = "";
        int i=n-1;
        while(i>=0){
             if(s[i]=='*'){
                if(i>0 && s[i-1]!='*'){
                    i--;
                }
                else{
                    k++;
                }
            }
            else{
                if(k>0) {
                    k--;
                }
                else {
                    temp.push_back(s[i]);
                }
            }
            i--;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};