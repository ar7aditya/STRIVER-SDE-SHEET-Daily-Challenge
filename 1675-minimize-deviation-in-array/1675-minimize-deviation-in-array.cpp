class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini = INT_MAX;
        for(int i : nums){
            if(i%2!=0) i = i*2;
            pq.push(i);
            mini = min( mini , i);
        }
        int ans = INT_MAX;
        while(pq.top()%2==0){
            int max_element = pq.top();
            pq.pop();
            ans = min ( ans , max_element - mini );
            pq.push(max_element / 2);
            mini = min( mini , max_element / 2);
        }
        return min( ans , pq.top() - mini);
    }
};