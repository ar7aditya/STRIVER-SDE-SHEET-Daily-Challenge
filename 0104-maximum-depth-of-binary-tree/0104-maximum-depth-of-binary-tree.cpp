/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* r){
        if(r==NULL) return 0;
        int lh = 1 + f(r->left);
        int rh = 1 + f(r->right);
        return max( lh , rh );
    }
    int maxDepth(TreeNode* root) {
       return f(root); 
    }
};