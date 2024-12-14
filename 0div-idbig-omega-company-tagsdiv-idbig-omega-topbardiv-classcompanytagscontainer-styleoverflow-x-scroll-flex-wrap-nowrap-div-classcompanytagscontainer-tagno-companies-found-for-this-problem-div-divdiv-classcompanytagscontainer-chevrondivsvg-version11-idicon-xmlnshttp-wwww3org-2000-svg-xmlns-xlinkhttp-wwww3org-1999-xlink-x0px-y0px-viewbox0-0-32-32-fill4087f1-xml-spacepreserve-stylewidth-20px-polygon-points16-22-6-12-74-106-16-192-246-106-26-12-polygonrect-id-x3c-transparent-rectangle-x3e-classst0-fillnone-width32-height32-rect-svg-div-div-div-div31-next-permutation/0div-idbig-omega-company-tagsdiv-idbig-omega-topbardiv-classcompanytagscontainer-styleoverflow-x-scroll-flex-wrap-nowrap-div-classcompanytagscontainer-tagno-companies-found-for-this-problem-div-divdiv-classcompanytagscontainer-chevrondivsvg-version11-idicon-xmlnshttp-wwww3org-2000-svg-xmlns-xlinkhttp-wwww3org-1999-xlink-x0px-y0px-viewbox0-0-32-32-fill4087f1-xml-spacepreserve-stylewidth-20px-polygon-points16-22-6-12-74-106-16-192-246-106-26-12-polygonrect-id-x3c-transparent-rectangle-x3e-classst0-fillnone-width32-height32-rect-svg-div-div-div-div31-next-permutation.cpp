class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool greatest = true;
        int breakPoint = 0;
        for(int i = n-1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                greatest = false;
                breakPoint = i;
                break;
            }
        }
        if(greatest){
            reverse(nums.begin(), nums.end());
            return;
        }
        int swap_element = nums[breakPoint-1];
        int index_to_replace = 0;
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > swap_element){
                index_to_replace = i;
                break;
            }
        }
        iter_swap(nums.begin() + index_to_replace, nums.begin() + breakPoint-1);
        sort(nums.begin() + breakPoint, nums.end());
        return;
    }
};