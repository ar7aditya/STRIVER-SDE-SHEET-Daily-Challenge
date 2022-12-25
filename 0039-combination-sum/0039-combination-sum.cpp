class Solution {
public:
    vector<vector<int>> ans;
    void f(int i,int t,vector<int>& c,vector<int> temp){
        if(t==0) {ans.push_back(temp);return;}
        if(i<0){
            return;
        }
        f(i-1,t,c,temp);
        temp.push_back(c[i]);
        if(t>=c[i]) f(i,t-c[i],c,temp);
        temp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
      f(n-1,target,candidates,{});
        return ans;
    }
};