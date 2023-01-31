class Solution {
public:
   int dp[10002][102];
    int f(int flor,int egg){
        if(egg==1) return flor;
        if(flor<=1) return flor;
        if( dp[flor][egg]!=-1) return  dp[flor][egg];
        int ans=INT_MAX;
        int l=1,h=flor;
                while(l<=h)
        {
            int mid=(l+h)/2;
            int left=f(mid-1,egg-1);  
            int right=f(flor-mid,egg) ;  
            int temp=1+max(left,right);        
            if(left<right){               
              l=mid+1;                     
            }
            else                            
            {    
                h=mid-1;
            }
            ans=min(ans,temp);              
        }
        return dp[flor][egg] =  ans;
    }
    int superEggDrop(int k, int n) {
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=-1;
            }
        }
        return f(n,k);
    }
};