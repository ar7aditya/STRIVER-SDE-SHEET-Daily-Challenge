class Solution {
public:

    void flatten(TreeNode* root) {
       TreeNode* cur=root,*p=NULL;
        while(cur){
            if(cur->left){
                p=cur->left;
                while(p->right) p=p->right;
                p->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
                cur=cur->right;
        }
        return;
    }
};