class Solution {
public:
    TreeNode* f(vector<int>& in,int inbegin,int inend, vector<int>& post,int postbegin,int postend, unordered_map<int,int>& mp){
        if(inbegin>inend || postbegin>postend) return NULL;
        TreeNode* root=new TreeNode(post[postend]);
        int inroot=mp[root->val];
        int numsleft=inroot-inbegin;
        root->left=f(in,inbegin,inroot-1,post,postbegin,postbegin+numsleft-1,mp);
        root->right=f(in,inroot+1,inend,post,postbegin+numsleft,postend-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int> mp;
        int n=post.size();
        for(int i=0;i<n;i++) mp[in[i]]=i;
        return f(in,0,n-1,post,0,n-1,mp);
    }
};