class Solution {
public:
    long long ans = 0;
    void f(int i,long long cur_st,int n,vector<int>& nums){
        if(i==n){
            ans = max(ans , cur_st);
            return;
        }
        f(i+1,cur_st,n,nums); f(i+1,cur_st*nums[i],n,nums);
        return ;
    }
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] < 0 && nums[1]==0 && nums[n-1]==0) return 0;
        if(nums[0]==0 && nums[n-1]==0) return 0;
        f(0,1,n,nums);
        return ans;
    }
};