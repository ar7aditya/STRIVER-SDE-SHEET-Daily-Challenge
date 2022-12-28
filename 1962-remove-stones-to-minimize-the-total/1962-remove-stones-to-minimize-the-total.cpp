class Solution {
public:
    int minStoneSum(vector<int>& piles, int k){
        priority_queue< int,vector<int> , greater<int> > pq;
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
            ans+=piles[i];
            if(pq.size()>k) pq.pop();
        }
         priority_queue<int> pq2;
        while(!pq.empty()){
            pq2.push(pq.top());
            pq.pop();
        }
        for(int i=0;i<k;i++){
            int m=pq2.top()/2;
            ans-=m;
            double p=pq2.top()/2.0;
            pq2.pop();
            pq2.push(ceil(p)); 
        }
        return ans;
    }
};
 