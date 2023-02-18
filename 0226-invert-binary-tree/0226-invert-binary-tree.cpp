
class Solution {
public:
    void pre(TreeNode * root){
        if(root==NULL) return ;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        pre(root->left);
        pre(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
       pre(root); 
        return root;
    }
};