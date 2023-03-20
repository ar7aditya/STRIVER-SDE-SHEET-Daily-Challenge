class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(size==1){
            if(flowerbed[0]==1 && n==1) return false;
            if(flowerbed[0]==0 && n==1) return true;
            if(flowerbed[0]==1 && n==0) return true;
        }
        int ans = 0;
        int l = 0;
        int r = size-1;
        while(l<size && flowerbed[l]!=1 ) l++;
       
        if(l==size) {
            ans += (l+1)/2;
            if(ans>=n) return true;
            return false;
        }
        else  ans += l/2;
        
        while(r<size && flowerbed[r]!=1 ) r--;
        ans += (size-1-r)/2;
        while(l<r){
            while(flowerbed[l]!=0) l++;
            int j=l;
            while(flowerbed[l]!=1) l++;
            int no_of_0 = l-j;
            ans += (no_of_0-1)/2;
        }
        if(ans>=n) return true;
        return false;
    }
};