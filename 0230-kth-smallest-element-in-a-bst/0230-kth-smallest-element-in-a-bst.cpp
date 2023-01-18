class Solution {
public:
    void inorder(TreeNode* r,vector<int>& v,int k){
        if(r==NULL || v.size()==k) return;
        inorder(r->left,v,k);
        v.push_back(r->val);
        inorder(r->right,v,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v,k);
        return v[k-1];
    }
};