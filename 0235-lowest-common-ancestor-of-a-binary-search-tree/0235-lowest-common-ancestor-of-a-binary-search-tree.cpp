
class Solution {
public:
    TreeNode* f(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==p || root==q) return root;
        if(root->val>p->val && root->val>q->val) return f(root->left,p,q);
        if(root->val<p->val && root->val<q->val) return f(root->right,p,q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return f(root,p,q); 
    }
};