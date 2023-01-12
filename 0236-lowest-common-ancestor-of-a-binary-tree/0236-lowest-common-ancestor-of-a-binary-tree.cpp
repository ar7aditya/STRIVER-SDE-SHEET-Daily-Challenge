class Solution {
public:
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        if(root==NULL) return NULL;
        TreeNode* l=f(root->left,p,q);
        TreeNode* r=f(root->right,p,q);
        if(l && r) return root;
        if(l && !r) return l;
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};