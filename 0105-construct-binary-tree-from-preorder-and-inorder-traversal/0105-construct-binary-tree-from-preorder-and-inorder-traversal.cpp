
class Solution {
public:
    TreeNode* f(vector<int>& pre,int prebegin,int preend, vector<int>& in,int inbegin,int inend,unordered_map<int,int>& mp){
        if(prebegin>preend || inbegin>inend) return NULL;
        TreeNode* root=new TreeNode(pre[prebegin]);
        int inroot=mp[root->val];
        int leftnums=inroot-inbegin;
        root->left=f(pre,prebegin+1,prebegin+leftnums,in,inbegin,inroot-1,mp);
        root->right=f(pre,prebegin+leftnums+1,preend,in,inroot+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
       unordered_map<int,int> mp;
        int n=pre.size();
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        return f(pre,0,n-1,in,0,n-1,mp);
    }
};