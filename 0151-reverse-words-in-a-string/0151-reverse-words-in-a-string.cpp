class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        int n = s.size();
        while(i < n){
            string temp = "";
            while(i < n && s[i] == ' ') i++;
            while(i < n && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(temp.size() > 0) words.push_back(temp);
        }
        string ans = "";
        int m = words.size();
        for(int i = m-1;i>=0;i--){
            ans += words[i];
            if(i != 0) ans += ' ';
        }
        return ans;
    }
};