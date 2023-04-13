class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> vis(1001,0);
        stack<int> st;
        int n = pushed.size();
        int push = 0;
        int pop = 0;
        while(push < n && pop < n){
            if(pushed[push] == popped[pop]){
                push++;
                pop++;
            }
            else if(!st.empty() && popped[pop] == st.top()){
                st.pop();
                pop++;
            }
            else if(!st.empty() && popped[pop] != st.top() && vis[popped[pop]]==1){
                return false;
            }
            else{
                st.push(pushed[push]);
                vis[pushed[push]] = 1;
                push++;
            } 
        } 
        while(!st.empty()){
            if(popped[pop] != st.top()){
                return false;
            }
            else {
                st.pop();
                pop++;
            }
        }
        return true;
    }
};