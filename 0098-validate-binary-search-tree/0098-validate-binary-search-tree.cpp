class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* r){
        if(r==NULL) return;
        inorder(r->left);
        v.push_back(r->val);
        inorder(r->right);
    }
    bool isValidBST(TreeNode* root) {
       inorder(root); 
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1]) return false;
        }
        return true;
    }
};