class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        int n=nums2.size();
       for(int i=0;i<nums1.size();i++){
           int j=mp[nums1[i]];
           int k=0;
           for(k=j+1;k<n;k++){
               if(nums2[k]>nums1[i]) break;
           }
           if(k==n) ans.push_back(-1);
           else ans.push_back(nums2[k]);
       } 
        return ans;
    }
};