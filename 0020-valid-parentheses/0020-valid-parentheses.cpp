class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp;
        mp['[']=']';
        mp['{']='}';
        mp['(']=')';
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(s[i]==mp[st.top()]) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};