class Solution {
public:
    typedef pair<int, int> pairs;
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int t1 = nums[i];
                while(t1 >= 10){
                    t1 = t1 / 10;
                }
                int t2 = nums[j]%10;
                if(__gcd(t1,t2) == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};