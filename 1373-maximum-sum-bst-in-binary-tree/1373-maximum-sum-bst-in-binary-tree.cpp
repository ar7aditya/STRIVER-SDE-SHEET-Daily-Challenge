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
    class InfoNode{
        public:
        int maxim;
        int minim;
        bool isBst;
        int sum;
    };
    int maxSum ;
    InfoNode maxSumBSTHelper(TreeNode * root){
        if(root== NULL){
            return {INT_MIN , INT_MAX , true , 0};
        }
        
        if(root->left == NULL && root->right == NULL){
            InfoNode base;
            base.maxim = root->val;
            base.minim = root->val;
            base.isBst = true;
            base.sum = root->val;
            maxSum = max(maxSum , base.sum);
            return base;
        }
        
        InfoNode leftNode = maxSumBSTHelper(root->left);
        InfoNode rightNode = maxSumBSTHelper(root->right);
        InfoNode base;
        
        if(leftNode.isBst && rightNode.isBst && leftNode.maxim < root->val && rightNode.minim > root->val){
            base.maxim = max(root->val , max(leftNode.maxim , rightNode.maxim));
            base.minim = min(root->val , min(leftNode.minim , rightNode.minim));
            base.isBst = true;
            base.sum= root->val + leftNode.sum + rightNode.sum;
            maxSum = max(maxSum , base.sum);
            return base;
        }
        base.isBst = false;
        base.maxim = max(root->val , max(leftNode.maxim , rightNode.maxim));
        base.minim = min(root->val , min(leftNode.minim , rightNode.minim));
        base.sum= root->val + leftNode.sum + rightNode.sum;
        return base;
        
    }
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        maxSumBSTHelper(root);
        return maxSum;
    }
};