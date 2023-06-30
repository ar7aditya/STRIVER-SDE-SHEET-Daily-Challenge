class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            int left = i + 1;
            int right = n - 1;
            int new_target = target - nums[i];
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == new_target) return {i + 1 , mid + 1};
                else if(nums[mid] < new_target){
                    left = mid + 1;
                }
                else right = mid - 1;
            } 
        }
        return {0 , 0};
    }
};