class Solution {
public:
    vector<int> ans;
    void f(int i,vector<int>& people,int req_skill,vector<int>& cur_sol,int cmask,vector<vector<int>>& dp){
        if(i == people.size() || cmask == (1<<req_skill)-1){
            if(cmask == (1<<req_skill)-1 ){
                if(ans.size() == 0 || ans.size() > cur_sol.size()){
                    ans = cur_sol;
                }
            }
            return;
        }
        if(dp[i][cmask] != -1){
            if(dp[i][cmask] <= cur_sol.size() ) return ;
        }
        f(i+1,people,req_skill,cur_sol,cmask,dp);
        if(cmask != (cmask | people[i]) && ( ans.size()==0 || cur_sol.size()+1 < ans.size()) ){
            cur_sol.push_back(i);
            f(i+1,people,req_skill,cur_sol,(cmask | people[i]),dp);
            cur_sol.pop_back();
        }
        dp[i][cmask] = (cur_sol.size() != 0) ? cur_sol.size() : -1;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& rs, vector<vector<string>>& p) {
        int n = p.size();
        int m = rs.size();
        // unordered_map<string,int> mp;
        // for(int i=0;i<rs.size();i++){
        //     mp[rs[i]] = i;
        // }
        vector<int>pep_skill;
        for(int i=0;i<n;i++)
       {
           int skill=0;
           for(int j=0;j<p[i].size();j++)
           {
               for(int k=0;k<m;k++)
               {
                  if(p[i][j]==rs[k])
                  {
                      skill=skill | (1<<k);  
                  }
               }
           }
           pep_skill.push_back(skill);

       }
        vector<int> cur_sol;
        int target=pow(2,m); 
        vector<vector<int>> dp(n, vector<int>(target, -1));
        f(0,pep_skill,m,cur_sol,0,dp);
        return ans;
    }
};