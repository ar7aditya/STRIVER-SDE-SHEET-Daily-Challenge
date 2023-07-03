class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int left = 0 , right = n - 1;
        int left_max = 0 , right_max = 0;
        int ans = 0;
        while(left <= right){
            if(h[left] <= h[right]){
                if(left_max <= h[left]){
                    left_max = h[left];
                }
                else{
                    ans += (left_max - h[left]);
                }
                left++;
            }
            else{
                if(right_max <= h[right]){
                    right_max = h[right];
                }
                else{
                    ans += (right_max - h[right]);
                }
                right--;
            }
        }
        return ans;
    }
};