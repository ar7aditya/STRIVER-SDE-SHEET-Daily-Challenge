class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            int n = strs[i].size();
            string temp = "";
            for(int j=0;j<n;j++){
                if(strs[i][j] == ans[j] ) temp.push_back(ans[j]);
                else break;
            }
            ans = temp;
            if(ans == "") return "";
        }
        return ans;
    }
};