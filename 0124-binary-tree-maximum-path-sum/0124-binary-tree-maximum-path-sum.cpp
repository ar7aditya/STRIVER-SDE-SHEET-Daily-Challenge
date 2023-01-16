class Solution {
public:
    int ans=INT_MIN;
    int f(TreeNode* root){
        if(root==NULL) return 0;
if(root->left==NULL && root->right==NULL){ans=max(ans,root->val); return root->val;}
        int l=0,r=0;
        l=f(root->left);
        r=f(root->right);
        if(l<0) l=0;
        if(r<0) r=0;
        ans=max(ans,l+r+root->val);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        ans=root->val;
        f(root);
        return ans;
    }
};