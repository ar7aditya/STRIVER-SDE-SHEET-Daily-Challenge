class Solution {
public:
    bool ans=true;
    int h(TreeNode* p){
        if(p==NULL) return 0;
        int lh=h(p->left);
        int rh=h(p->right);
        if(abs(lh-rh)>1) {
            ans=false;
            return max(lh+1,rh+1);
        }
        return max(lh+1,rh+1);
    }
    bool isBalanced(TreeNode* root) {
         h(root);
        return ans;
    }
};