class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int n=tasks.size();
        set<int> s;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
            s.insert(tasks[i]);
        }
        set<int> ::iterator itr;
     for (itr = s.begin(); itr != s.end(); itr++) {
        if(mp[*itr]<2) return -1;
        ans+=(mp[*itr]/3);
         if(mp[*itr]%3!=0) ans++;
     }
        return ans;
    }
};