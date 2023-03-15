class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        bool pastNullTracker = false;
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
            TreeNode * front = q.front();
            q.pop();
                if(pastNullTracker){
                    if(front!=NULL) return false;
                }
                if(front==NULL) pastNullTracker = true;
                else {
                   q.push(front->left);
                   q.push(front->right);
                }
                
            }
        }
        
        return true;
    }
};