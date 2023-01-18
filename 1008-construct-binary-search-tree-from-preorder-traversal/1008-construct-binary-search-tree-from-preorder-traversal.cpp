class Solution {
public:
    TreeNode* f(vector<int>& preorder,int preBegin,int preEnd,vector<int>& inorder,int inBegin,int inEnd,unordered_map<int,int>& mp){
        if(preBegin>preEnd || inBegin>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preBegin]);
        int inroot=mp[root->val];
        int numsleft=inroot-inBegin;
        root->left=f(preorder,preBegin+1,preBegin+numsleft,inorder,inBegin,inroot-1,mp);
        root->right=f(preorder,preBegin+numsleft+1,preEnd,inorder,inroot+1,inEnd,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& inorder) {
        int n=inorder.size();
        vector<int> pre=inorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        return f(pre,0,n-1,inorder,0,n-1,mp);
    }
};