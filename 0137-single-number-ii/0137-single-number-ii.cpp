class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        long ans;
        int x, t;
        ans=0;
        long long p = 1;
        for(int i=0;i<32;i++)
        {
            t=0;
            for(int j=0;j<n;j++)
            {
                if( (nums[j] & (1<<i)) != 0){
                    t++;
                }
            }
            t=t%3; 
            ans = ans + t * p;
            p = p * 2;
        }
        return ans;
        
    }
};