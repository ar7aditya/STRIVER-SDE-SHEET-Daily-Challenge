class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<4) return ans;
        
        sort(nums.begin(),nums.end());
        
        long long sum=0; 
        for(int i=0;i<n;i++){
             if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
             if(j > i + 1 && nums[j] == nums[j-1]) continue;
            long long starget= (long long)target - (long long)nums[i] - (long long)nums[j];
            int l=j+1,r=n-1;
            while(l<r){
                sum = (long long)nums[l] + (long long)nums[r];
                if(sum==starget){
                      ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(sum<starget){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        }
        return ans;
    }  
    
};