class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        TreeNode* cur=root,*p=root;
        while(cur!=NULL){
            p=cur;
            if(cur->left!=NULL){
                p=cur->left;
              while(p->right!=NULL && p->right!=cur) p=p->right;
                if(p->right==cur) {
                    ans.push_back(cur->val);
                    p->right=NULL;
                    cur=cur->right;
                }
                else {
                    p->right=cur;
                    cur=cur->left;
                }
            }
            else{
               ans.push_back(cur->val);
               cur=cur->right; 
            }
        }
       
        return ans;
    }
};