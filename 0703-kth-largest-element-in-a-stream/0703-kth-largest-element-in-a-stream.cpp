class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int w;
    KthLargest(int k, vector<int>& nums) {
        w=k;
        for(int i:nums){
            pq.push(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>w) pq.pop();
        return pq.top();
    }
};
