class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        vector<string> ans(n);
        bool is_down=true;
        int row=0;
        for(int i=0;i<s.size();i++){
            ans[row].push_back(s[i]);
            if(is_down) row++;
            else row--;
            if(row==n) {
                row=n-2;
                is_down=false;
            }
            if(row==-1){
                row=1;
                is_down=true;
            }
        }
        string res="";
        for(int i=0;i<n;i++){
            res= res + ans[i];
        }
        return res;
    }
};