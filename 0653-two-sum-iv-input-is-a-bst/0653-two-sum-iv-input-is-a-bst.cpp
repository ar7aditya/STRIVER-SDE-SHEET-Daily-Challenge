class Solution {
public:
    void f(TreeNode* p,vector<int>& v){
        if(p==NULL) return;
        f(p->left,v);
        v.push_back(p->val);
        f(p->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        f(root,v);
        int n=v.size();
        int l=0,r=n-1;
        while(l<r){
           if(v[l]+v[r]==k) return true;
            if(v[l]+v[r]>k) r--;
            else l++;
        }
        return false;
    }
};