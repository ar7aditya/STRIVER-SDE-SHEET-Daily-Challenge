class Solution {
public:
    void f(int i,int n,vector<int> nums,vector<int> temp,set<vector<int>>& res)
    {
       if(i==n){
           if(temp.size()==0) return;
           if(temp.size()>=2) res.insert(temp);
           if(temp.back()<=nums[i]) {
               temp.push_back(nums[i]);     
               res.insert(temp);
           }
           return;
       }
        f(i+1,n,nums,temp,res);// not pick
        if(temp.size()==0) {
            temp.push_back(nums[i]);
            f(i+1,n,nums,temp,res);
            temp.pop_back();
        }
        else if(temp.back()<=nums[i]) {
               temp.push_back(nums[i]);
                f(i+1,n,nums,temp,res);
                temp.pop_back();
           }
        
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       set<vector<int>> res;
        vector<vector<int>> ans;
        f(0,nums.size()-1,nums,{},res);
        for(auto i:res) ans.push_back(i);
        return ans;
    }
};