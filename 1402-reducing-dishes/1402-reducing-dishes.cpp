class Solution {
public:    
    int maxSatisfaction(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        if(v[n-1]<=0) return 0;
        int cur_sum = 0;
        int cummulative_sum = 0;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            cur_sum += cummulative_sum + v[i];
            cummulative_sum += v[i];
            ans = max( ans , cur_sum);
        }
        return ans;
    }
};