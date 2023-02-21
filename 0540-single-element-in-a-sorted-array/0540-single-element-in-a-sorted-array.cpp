class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        if(lo==hi) return nums[0];
        while(lo<hi){
          int mid = (lo+hi)/2;
          if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2==1 && nums[mid]==nums[mid-1])){
              lo = mid + 1;
          }
          else if( (mid==0 ||nums[mid]!=nums[mid-1]) && (mid==nums.size()-1 || nums[mid]!=nums[mid+1])) return nums[mid];
          else hi = mid - 1;
        }
        return nums[lo];
    }
};