class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        int ans = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(pq.empty()) return x;
            int y = pq.top();
            pq.pop();
            pq.push(x-y);
        }
        return 0;
    }
};