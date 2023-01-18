class Solution {
public:
    TreeNode* f(TreeNode* root, int val){
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        if(val>root->val) return f(root->right,val);
        return f(root->left,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return f(root,val);
    }
};