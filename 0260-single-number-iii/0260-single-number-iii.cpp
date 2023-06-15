class Solution {
public:

    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>res{};
        int bucket1{}, bucket2{};
        long long int xr{};
        
        for(int i{}; i<n; ++i) 
            xr = xr ^ nums[i];
        int mask = xr & (-xr);
        for(int i{}; i<n; ++i){
            
            if(mask & nums[i])
                bucket1 ^= nums[i];
            
            else
                bucket2 ^= nums[i];
        }
        res.push_back(bucket1);
        res.push_back(bucket2);
        
        return res;
    }
};