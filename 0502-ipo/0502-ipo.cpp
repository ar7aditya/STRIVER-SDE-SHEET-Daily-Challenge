class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)     {
       vector<pair<int,int>> min_cap;
        int n = capital.size();
        for(int i=0;i<n;i++){
            min_cap.push_back({capital[i],profits[i]});
        }
        sort(min_cap.begin(),min_cap.end());
        priority_queue<int> pq;
        int i = 0; // pointer
        while(k--){
            while(i<n && w>=min_cap[i].first){
                pq.push(min_cap[i].second);
                i++;
            }
            if(pq.empty()) return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};