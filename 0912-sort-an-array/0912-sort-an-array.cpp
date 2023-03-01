class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i : nums){
            pq.push(i);
        }
        int i=nums.size()-1;
        while(!pq.empty()){
            nums[i--]=pq.top();
            pq.pop();
        }
        return nums;
    }
};