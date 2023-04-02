class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long        success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int left = 0;
            int right = m-1;
            long long x = (long long)potions[right]*(long long)spells[i];
            long long y = (long long)potions[left]*(long long)spells[i];
            if(x < success) continue;
            if(y >= success){
                ans[i] = m;
                continue;
            }
                while(left < right){
                    int mid = (left + right)/2;
                    long long z = (long long)potions[mid]*(long long)spells[i];
                    if(z < success){
                        left = mid + 1;
                    }
                    else {
                        right = mid ;
                    }
                }
            ans[i] = m - right;
        }
        return ans;
    }
};