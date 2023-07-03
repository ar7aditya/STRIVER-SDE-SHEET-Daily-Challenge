class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int j = 0;
        while(j < n){
            while(j < n && nums[j] == nums[cur]) j++;
            if(j != n) nums[cur + 1] = nums[j];
            cur++;
        }
        return cur;
    }
};