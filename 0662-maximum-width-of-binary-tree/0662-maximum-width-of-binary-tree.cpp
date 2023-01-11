class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 1));
        while (!q.empty()) {
            long long l = q.front().second, r = l; 
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
    if (node->left) q.push(pair<TreeNode*, int>(node->left, (long long)r * 2+1));
    if (node->right) q.push(pair<TreeNode*, int>(node->right, (long long)r * 2 + 2));
            }
            res = max(res, r - l + 1 );
        }
        return res;
    }
};
