class Solution {
public:
            vector<vector<int>> res;
    void f(int i,int n,int t,vector<int>& c,vector<int> temp){
       if(t==0){res.push_back(temp);return;}
        if(t<0) return;
        for(int idx=i;idx<n;idx++){
            if( idx!=i && c[idx]==c[idx-1]) continue;
         temp.push_back(c[idx]);
         f(idx+1,n,t-c[idx],c,temp);
         temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(0,candidates.size(),target,candidates,{});
        return res;
    }
};