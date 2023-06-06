class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(arr[i] > maxi) maxi = arr[i];
            if(arr[i] < mini) mini = arr[i];
            mp[arr[i]]++;
        }
        double d = (maxi - mini)/(double)(n-1);
        if(d == 0) return true;
        if(d > floor(d)) return false;
        int cur = mini+d;
        for(int i=1;i<n;i++){
            if(mp.find(cur) == mp.end() || mp[cur] > 1) return false;
            cur += d;
        }
        return true;
    }
};