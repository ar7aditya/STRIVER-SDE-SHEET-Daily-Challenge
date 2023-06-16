class Solution {
public:
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> prefix_xor(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum ^ nums[i];
            prefix_xor[i] = sum;
        }
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            int total_xor = prefix_xor[q[i][1]];
            int left_xor = 0;
            if(q[i][0] != 0) left_xor = prefix_xor[q[i][0] - 1];
            ans.push_back(total_xor ^ left_xor);
        }
        return ans;
    }
};