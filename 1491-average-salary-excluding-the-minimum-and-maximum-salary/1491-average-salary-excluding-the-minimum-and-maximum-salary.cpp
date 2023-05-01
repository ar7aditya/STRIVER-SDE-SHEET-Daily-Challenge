class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX;
        int maxi = 0;
        int n = salary.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            mini = min( mini , salary[i]);
            maxi = max( maxi , salary[i]);
            sum += salary[i];
        }
        sum = sum - mini - maxi;
        return double(sum/double(n-2));
    }
};