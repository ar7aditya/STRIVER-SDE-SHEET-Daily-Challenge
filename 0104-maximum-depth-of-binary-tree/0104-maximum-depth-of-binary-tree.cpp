class Solution {
public:
    int h(TreeNode* p){
        if(p==NULL) return 0;
        int lh=h(p->left);
        int rh=h(p->right);
        return lh>rh?lh+1:rh+1;
    }
    int maxDepth(TreeNode* root) {
        return h(root);
    }
};