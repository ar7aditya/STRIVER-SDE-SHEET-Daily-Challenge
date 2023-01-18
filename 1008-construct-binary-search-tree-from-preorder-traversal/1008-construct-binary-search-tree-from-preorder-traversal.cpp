class Solution {
public:
    TreeNode* insertNode(TreeNode* p,int val){
        if(p->left==NULL && p->val>val) return p->left=new TreeNode(val);
        if(p->right==NULL && p->val<val) return p->right=new TreeNode(val);
        if(val<p->val)return insertNode(p->left,val);
        return insertNode(p->right,val);
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n=pre.size();
        TreeNode* root=new TreeNode(pre[0]);
        TreeNode* p=NULL;
        for(int i=1;i<n;i++){
            insertNode(root,pre[i]);
        }
        return root;
    }
};