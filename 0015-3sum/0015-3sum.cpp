class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n < 3) return {};
        vector<vector<int>> res;
        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int l = i + 1;
            int r = n - 1;
            while(l < r){
            int sum = nums[l] + nums[r];
			if(sum > target)
				r--;
			else if(sum < target)
				l++;
			else{
				res.push_back({nums[i],nums[l],nums[r]});
				l++;
			}

			while(l > i+1 && l < r && nums[l-1] == nums[l]) l++;
			while(r < n-1 && l < r && nums[r] == nums[r+1]) r--;
            }
        }
        return res;
    }
};