class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
           if(target==nums[mid]) return mid;
            if(nums[mid]>=nums[lo]) {
                if(nums[lo]<=target && nums[mid]>= target) hi=mid-1;
                 else lo=mid+1;
            }
            else{
                 if(nums[mid]<=target && nums[hi]>= target)  lo=mid+1;
                 else  hi=mid-1;
            }
        }
       return -1;
    }
};