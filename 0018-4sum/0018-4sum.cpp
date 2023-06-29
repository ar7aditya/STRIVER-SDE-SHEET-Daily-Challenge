class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
         set<vector<int>> v;
        if(n<4) return ans;
        
        sort(nums.begin(),nums.end());
        
        long long sum=0; 
        for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long starget= (long long)target - (long long)nums[i] - (long long)nums[j];
            int l=j+1,r=n-1;
            while(l<r){
                sum = (long long)nums[l] + (long long)nums[r];
                if(sum==starget){
                     v.insert({nums[i],nums[j],nums[l],nums[r]});
                    l++;
                    r--;
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
        for(auto m:v){
                ans.push_back(m);
            }
        return ans;
    }  
    
};