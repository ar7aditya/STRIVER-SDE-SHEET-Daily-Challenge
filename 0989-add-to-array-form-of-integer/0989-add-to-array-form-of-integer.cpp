class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> k2;
        while(k>0){
            int rem = k%10;
            k2.push_back(rem);
            k=k/10;
        }
        int n = nums.size();
        int m = k2.size();
        reverse(nums.begin(),nums.end());
        
        int i=0,j=0;
        int carry=0;
        while(i<n || j<m ){
            int val = carry;
            if( i<n ) val += nums[i];
            if( j<m ) val += k2[j];
            if(val<=9) {
                if(i<n) nums[i] = val;
                if(j<m) k2[j] = val;
                carry = 0;
            }
            else{
                int rem = val%10;
                if(i<n) nums[i] = rem;
                if(j<m) k2[j] = rem;
                carry = val/10;
            }
            i++;
            j++;
        }
        if(carry==1) {
            if(m>n) k2.push_back(1);
            else nums.push_back(1);
        }
        
        if(m>n) {
            reverse(k2.begin(),k2.end());
            return k2;
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};