class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < nums1.size(); i++){
            v.push_back( {nums2[i] , nums1[i] });
        }
        sort(v.rbegin() , v.rend());
        priority_queue< int , vector<int> , greater<int> > pq;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < v.size(); i++){
            int eff = v[i].first;
            int val = v[i].second;
            sum += val;
            pq.push(val);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans = max( ans , sum * eff);
            }
        }
        return ans;
    }
};