class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a1,a2;
        vector<int> v(2002,0);
        for(int i=0;i<nums1.size();i++){
            v[nums1[i]+1000] = 1;
        }
        for(int i=0;i<nums2.size();i++){
            if((v[nums2[i]+1000])==0) {
                v[nums2[i]+1000] = 2;
                a2.push_back(nums2[i]);
            }
            if((v[nums2[i]+1000])==1) v[nums2[i]+1000] = -1;
        }
        for(int i=0;i<2002;i++){
            if(v[i]==1) a1.push_back(i-1000);
        }
        return {a1,a2};
    }
};