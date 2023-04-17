class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int maxi = 0;
       int n = candies.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi , candies[i]);
        }
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
            if(extraCandies + candies[i] >= maxi){
                v[i] = true;
            }
        }
        return v;
    }
};