class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
       if(root->val==val) return root;
        TreeNode* cur=root;
        while(cur){
            if(cur->val==val) return cur;
            if(cur->val>val) cur=cur->left;
            else cur=cur->right;
        }
        return NULL;
    }
};