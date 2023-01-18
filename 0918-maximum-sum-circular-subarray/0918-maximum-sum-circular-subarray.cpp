class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int max_sum=INT_MIN;
        int cur_max_sum=0;
        int cur_min_sum=0;
        int total_sum=0;
        int min_sum=0;
        for(int i=0;i<n;i++){
            cur_max_sum+=nums[i];
            total_sum+=nums[i];
            cur_min_sum+=nums[i];
            min_sum=min(min_sum,cur_min_sum);
            max_sum=max(max_sum,cur_max_sum);
            if(cur_max_sum<0) cur_max_sum=0;
            if(cur_min_sum>0) cur_min_sum=0;
        }
        if(min_sum==total_sum) return max_sum;
        return max(max_sum,total_sum-min_sum);
    }
};