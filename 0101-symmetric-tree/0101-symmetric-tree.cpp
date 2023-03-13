class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return f(root->left,root->right);
    }
    
    bool f(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL)  return true;   
        else if(p == NULL || q == NULL) return false; 
        else if(p->val!=q->val)  return false; 
        return f(p->left,q->right) && f(p->right,q->left); 
    }
};