class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        unordered_map<char,int> mp={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
        if(mp[s[0]]<0) return false;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0)  st.push(mp[s[i]]);
            else{
                if(st.empty()) return false;
                int x=st.top();
                int y=mp[s[i]];
                if(x+y!=0) return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};