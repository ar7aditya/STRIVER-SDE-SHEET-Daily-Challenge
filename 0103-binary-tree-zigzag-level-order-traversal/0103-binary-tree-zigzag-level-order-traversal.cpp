class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        bool flag=false;
        while(root && !q.empty()){
            stack<int> st;  
            int n=q.size();
             vector<int> m(n);
            for(int i=0;i<n;i++){
                 TreeNode* cur=q.front();
                q.pop();
            if(!flag){
                 m[i]=cur->val;
            }
                else{
                   m[n-1-i]=cur->val;   
                }
                if(cur->left!=NULL) q.push(cur->left);
                 if(cur->right!=NULL) q.push(cur->right);
            }
            res.push_back(m);
            flag=!flag;
        }
        return res;
    }
};