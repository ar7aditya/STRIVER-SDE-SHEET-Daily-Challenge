class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        map<int,int> mp;
        mp[0] = root->val;
        map<TreeNode*,TreeNode*> parent;
        while(!q.empty())
        {
            level++;
            int size = q.size();
            for(int i = 0;i < size ;i++)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left != NULL){
                    q.push(n->left);
                    mp[level] += n->left->val;
                }
                if(n->right != NULL){
                    q.push(n->right);
                    mp[level]+=n->right->val;
                }
            }
        } 
        queue<TreeNode*> queue;
        queue.push(root);
        level = 0;
        root->val = 0;
        while(!queue.empty())
        {
            level++;
            int size = queue.size();
            for(int i = 0;i< size ;i++)
            {
                TreeNode* n = queue.front();
                queue.pop();
                int left = 0;
                int right = 0;
                if(n->left != NULL ) left = n->left->val;
                if(n->right != NULL) right = n->right->val;
                if(n->left != NULL){
                    queue.push(n->left);
                    if(level==1) n->left->val = 0;
                    else n->left->val = mp[level]-left-right; 
                }
                if(n->right!= NULL){  
                    queue.push(n->right);
                    if(level==1) n->right->val = 0;
                    else n->right->val = mp[level]-left-right;
                }
            }
        }
        
         return root;
    }
};
