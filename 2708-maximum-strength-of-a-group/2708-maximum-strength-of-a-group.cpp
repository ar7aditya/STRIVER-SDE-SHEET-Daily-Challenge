class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = 1;
        int n = nums.size();
        if(n==1) return nums[0];
        int i = 0;
        while(i<n && nums[i]<0) i++;
        int neg = i;
        if(nums[n-1]==0 && neg==1) return 0;
        if(nums[0]==0 && nums[n-1]==0) return 0;
        if(neg%2==0){
            int k = 0;
            while(k<neg){
                ans = ans * nums[k];
                k++;
            }
        }
        else{
            int k = 0;
            while(k<neg-1){
                ans = ans * nums[k];
                k++;
            }
        }

        while(i<n && nums[i]==0) i++;

        int pos = i;
        while(pos < n){
            ans = ans * nums[pos];
            pos++;
        }
            return ans;
    }
};