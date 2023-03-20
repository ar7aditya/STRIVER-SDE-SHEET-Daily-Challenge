class Solution {
public:
    set<vector<int>> st;
    int f(int i,int n,vector<int>& nums,unordered_map<int,int>& temp,int k){
        if(i==n) {
             bool found=false;
            for(auto& x:temp){
                if(x.second>0){
                    found=true;
                    break;
                }
            }
            if(found)
            return 1;
            return 0;
        } 
        int take =0;
        int not_take = 0;
            if(!temp[nums[i]-k]) {
                temp[nums[i]]++;
               take = f(i+1,n,nums,temp,k);
                temp[nums[i]]--;
            }
        not_take = f(i+1,n,nums,temp,k);
        return take + not_take;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,int> temp;
        return f(0,n,nums,temp,k);  
    }
};