class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(nums[l] + nums[r] != target){
            if(nums[l] + nums[r] < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {l + 1 , r + 1};
    }
};