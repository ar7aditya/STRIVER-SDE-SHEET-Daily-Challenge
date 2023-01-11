class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        TreeNode* t=NULL;
        while(!q.empty()){
            t=q.front().first;
            int line=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            mp[line][level].insert(t->val);
            if(t->left) q.push({t->left,{line-1,level+1}});
            if(t->right) q.push({t->right,{line+1,level+1}});
        }
         for (auto p : mp) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};