class Solution {
public:
       bool f(TreeNode* root,long mini,long maxi){
        if(root==NULL) return true;
        if(root->val<=mini || root->val>=maxi ) return false;
 return f(root->left,mini,root->val) && f(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
       return f(root,LONG_MIN, LONG_MAX);
    }
};
