class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i] = ((nums[i]%k) + k) ;
            }
            nums[i] = nums[i] % k;
            mp[nums[i]]++;
        }
        int ans = 0;
        int req_val = 0;
        while(true){
            if(mp[req_val]>0){
                mp[req_val]--;
                ans ++;
            }
            else break;
            req_val = (req_val+1) % k;
        }
        return ans;
    }
};