class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> res;
        stack<TreeNode*> st;
        TreeNode* t=root;
        while(t!=NULL || !st.empty()){
            if(t!=NULL){
                res.push_back(t->val);
                st.push(t);
                t=t->left;
            }
            else{
                if(st.empty()) break;
                t=st.top();
                st.pop();
                t=t->right;
            }
        }
        return res;
    }
};