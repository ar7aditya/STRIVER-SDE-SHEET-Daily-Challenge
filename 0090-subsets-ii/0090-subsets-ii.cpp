class Solution {
public:
    set<vector<int>> ans;
    void f(int i,vector<int>& nums,vector<int> temp){
        if(i==0){
            ans.insert(temp);
            temp.push_back(nums[i]);
             ans.insert(temp);
            return;
        }
        f(i-1,nums,temp);
        temp.push_back(nums[i]);
        f(i-1,nums,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        f(n-1,nums,{});
        for(auto i:ans) res.push_back(i);
        return res;
    }
};