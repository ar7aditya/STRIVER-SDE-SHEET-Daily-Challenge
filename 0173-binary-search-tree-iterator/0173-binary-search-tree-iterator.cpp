class BSTIterator {
public:
    TreeNode* p=NULL,*cur=NULL;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        p=root;
       while(p!=NULL){
           st.push(p);
           p=p->left;
       }
    }
    
    int next() {
       cur=st.top();
        st.pop();
        p=cur;
        if(p->right) {
           p=p->right;
           while(p!=NULL){
           st.push(p);
           p=p->left;
         }
        }
        return cur->val;
    }
    
    bool hasNext() {
         return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */