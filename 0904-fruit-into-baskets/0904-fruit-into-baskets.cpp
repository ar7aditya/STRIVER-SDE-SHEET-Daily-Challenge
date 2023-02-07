class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        unordered_map<int,int> mp;
        int i;
        for(i=0;i<n;i++){
            if(mp.size()<2){
                mp[f[i]]++;
            }
            else{
                if(mp.find(f[i])!=mp.end()){
                    mp[f[i]]++;
                }
                else break;
            }
        }
        if(i==n) return n;
        int ans = i;
        int begin=0;
        
       while(i<n){
           if(begin<n){ 
               mp[f[begin]]--; 
               if(mp[f[begin]]==0)  mp.erase(f[begin]);
               begin++;
           } 
           if(mp.size()<2) 
           {
               mp[f[i]]++;i++;
               while(i<n && mp.find(f[i])!=mp.end()) {
                   mp[f[i]]++;
                    i++;    
               }
           }
           ans=max(ans , i-begin);
        }
        
        return ans;
    }
};