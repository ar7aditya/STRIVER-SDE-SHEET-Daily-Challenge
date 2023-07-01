class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.push_back( {efficiency[i] , speed[i] });
        }
        sort(v.rbegin() , v.rend());
        priority_queue< int , vector<int> , greater<int> > pq;
        long sum = 0;
        long ans = 0;
        for(int i = 0; i < n; i++){
            int eff = v[i].first;
            int val = v[i].second;
            sum += val;
            pq.push(val);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() <= k){
                ans = max( ans , sum * eff ) ;
            }
        }
        return (ans) % mod;
    }
};