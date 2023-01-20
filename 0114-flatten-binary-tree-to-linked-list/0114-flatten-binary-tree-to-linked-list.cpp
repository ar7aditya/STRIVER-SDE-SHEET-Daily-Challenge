class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* t=root;
        while(root){
            if(root->left) {
                t=root->left;
                while(t->right) t=t->right;
                t->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
        return;
    }
};