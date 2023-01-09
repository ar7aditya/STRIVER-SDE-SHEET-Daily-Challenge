class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
     TreeNode* t=root;
        while(root!=NULL){
            if(root->left!=NULL){
                t=root->left;
                while(t->right!=NULL && t->right!=root) t=t->right;
                if(t->right==root){
                    t->right=NULL;
                    root=root->right;
                }
                else {
                    t->right=root;
                     ans.push_back(root->val);
                    root=root->left;
                     }
            }
            else{
                ans.push_back(root->val);
                 root=root->right;
            }
        }
        return ans;
    }
};