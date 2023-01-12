class Solution {
public:
    int ans=0;
    int h(TreeNode* p){
        if(p==NULL) return 0;
        int lh=h(p->left);
        int rh=h(p->right);
        int k=max(lh+1,rh+1);
        ans=max(lh+rh,ans);
        return k;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        h(root);
        return ans;
    }
};