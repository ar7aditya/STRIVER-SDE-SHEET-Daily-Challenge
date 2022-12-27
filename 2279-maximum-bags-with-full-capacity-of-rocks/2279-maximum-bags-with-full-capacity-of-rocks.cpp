class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int> rem(n);
        for(int i=0;i<n;i++){
            rem[i]=capacity[i]-rocks[i];
        }
        sort(rem.begin(),rem.end());
        int ans=0,i=0;
        while(additionalRocks>=0 && i<n){
            additionalRocks-=rem[i];
            if(additionalRocks>=0) ans++;
            i++;
        }
        return ans;
    }
};