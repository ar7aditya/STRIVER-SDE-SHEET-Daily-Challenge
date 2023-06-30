class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        int ml=1;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        for(int i=0;i<n;i++){
            int c=1;
            if(st.find(nums[i]-1)==st.end()){
                while(st.find(nums[i]+c)!=st.end()) c++;
            }
            ml=max(c,ml);
        }
        return ml;
    }
};