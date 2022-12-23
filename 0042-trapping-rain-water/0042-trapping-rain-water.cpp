class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
       vector<int> lmax(n) , rmax(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0) lmax[i]=h[i];
            else{
                lmax[i]=max(lmax[i-1],h[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1) rmax[i]=h[i];
            else{
                rmax[i]=max(rmax[i+1],h[i]);
            }
        }
        for(int i=0;i<n;i++){
          ans+=min(lmax[i],rmax[i]) - h[i];  
        }
        return ans;
    }
};