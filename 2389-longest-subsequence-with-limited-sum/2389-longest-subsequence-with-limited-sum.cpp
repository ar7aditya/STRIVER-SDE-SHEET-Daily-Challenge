class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int m=queries.size();
        int n=nums.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int j=0,tsum=0;
            while(tsum<=queries[i] && j<n) {
                tsum+=nums[j];
                j++;
            }
            if(j==n && tsum<=queries[i]) ans[i]=n;
            else ans[i]=j-1;
        }
        return ans;
    }
};