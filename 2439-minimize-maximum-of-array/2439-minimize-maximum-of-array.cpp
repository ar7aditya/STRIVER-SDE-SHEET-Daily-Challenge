class Solution {
public:
      int minimizeArrayValue(vector<int>& A) {
        long sum = 0, res = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            long t = ((sum+i)/(i+1));
            res = max(res, t);
        }
        return res;
    }
};