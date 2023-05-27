long long maximumOr(int* nums, int n, int k){
    long long pre[n];
    long long suf[n];
        
        pre[0] = nums[0];
        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1] | nums[i];
        }
        
        suf[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            suf[i] = suf[i+1] | nums[i];
        }
        
        long long res = pre[n-1];
        for(int i=0; i<n; i++) {
            long long p = (i == 0) ? 0 : pre[i-1];
            long long s = (i == n-1) ? 0 : suf[i+1];
            long long mor = (long long)nums[i]<<k | (p | s);
            res = fmax(res, mor);
        }
        
        return res;
}