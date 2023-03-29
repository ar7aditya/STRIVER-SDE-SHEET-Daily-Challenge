class Solution {
public:
    string removeStars(string s) {
//       string temp="";
//         stack<char> st;
//         for(char i : s){
//             st.push(i);
//         }
//         while(!st.empty()){
//             char z = st.top();
//             st.pop();
//             if(z!='*'){
//                 temp.push_back(z);
//             }
//             else{
//                 if(!st.empty()){
//                     if(st.top()!='*'){
//                         st.pop();
//                     }
                    
//                 }
//             }
//         }
//         reverse(temp.begin(),temp.end());
//         return temp;
        stack<char> stack;
        for(char& ch : s){
            if(ch == '*' ){
                stack.pop();
            }else{
                stack.push(ch);
            }
        }
        string ans;
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};