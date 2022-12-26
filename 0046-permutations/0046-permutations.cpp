class Solution {
public:
     vector<vector<int>> ans;
    void f(int i,int n,vector<int> nums,vector<int> temp,vector<int> vis){
        if(temp.size()==n) {ans.push_back(temp);return;}
        for(int k=0;k<n;k++){
            if(vis[k]==1) continue;
            temp.push_back(nums[k]);
            vis[k]=1;
            f(i,n,nums,temp,vis);
            vis[k]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n+1);
        f(0,n,nums,{},vis);
        return ans;
    }
};