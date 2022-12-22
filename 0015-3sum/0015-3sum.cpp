class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
         set<vector<int>> ans;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int l,r;
        for(int i=0;i<n;i++){
            l=i+1,r=n-1;
            while(l<r){
                 if(i>0&&nums[i]==nums[i-1]) break;
                if(nums[i]+nums[l]+nums[r]>0) r--;
                else if(nums[i]+nums[l]+nums[r]<0) l++;
                else{
                      ans.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                
            }
        }
        for(auto i: ans) res.push_back(i);
        return res;
    }
};