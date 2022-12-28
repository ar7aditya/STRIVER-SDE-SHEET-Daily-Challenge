class Solution {
public:
    int minStoneSum(vector<int>& piles, int k){
        priority_queue<int> pq;
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
            ans+=piles[i];
        }
        for(int i=0;i<k;i++){
            double p=pq.top()/2.0;
            int m=pq.top()-ceil(p);
            ans-=m;
            pq.pop();
            pq.push(ceil(p));      
        }
        return ans;
    }
};