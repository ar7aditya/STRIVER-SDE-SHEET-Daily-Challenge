class Solution {
public:
    priority_queue<int> mh;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        if(root->left) kthSmallest(root->left,k);
        mh.push(root->val);
        if(mh.size()>k) mh.pop();
        if(root->right) kthSmallest(root->right,k);
        return mh.top();
    }
};