class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        int i=0;
        while(i<n){
            while(path[i]=='/') i++;
            string temp = "";
            while(i<n && path[i]!='/'){
                temp += path[i];
                i++;
            }
            if(temp != "" && temp != ".") st.push(temp);
        }
        string ans = "/";
        stack<string> st1;
        int k=0;
        while(!st.empty()){
            cout<<st.top()<<" ";
            if(st.top()==".."){
                 k++;
                st.pop();
            }
            else if(k>0) {
                k--;
                st.pop();
            }
            else{
                // 
                st1.push(st.top());
                st.pop();
            } 
        }
        if(st1.empty()) return ans;
        while(!st1.empty()){
            ans += st1.top() + '/';
            st1.pop();
        }
        ans.pop_back();
        return ans;
    }
};