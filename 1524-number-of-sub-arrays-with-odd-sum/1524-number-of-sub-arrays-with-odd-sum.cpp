class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0;
        long long sum = 0;
        int odd_count = 0;
        int even_count = 1;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum % 2 != 0){
                ans = (ans + even_count) % mod;
                odd_count++;
            }
            else{
                ans = (ans + odd_count) % mod;
                even_count++;
            }
        }
        return ans;
    }
};