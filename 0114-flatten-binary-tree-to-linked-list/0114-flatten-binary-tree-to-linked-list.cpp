class Solution {
public:
    void f(TreeNode* root,TreeNode*& prev){
        if(root==NULL) return;
        f(root->right,prev);
        f(root->left,prev);
        root->right=prev;
        root->left=NULL;
        prev=root;
        return;
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode*prev=NULL;
        f(root,prev);
            return;
    }
};