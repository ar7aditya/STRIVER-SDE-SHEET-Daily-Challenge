class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.size();
         int n1 = p.size();
        if(n1>n) return ans;
        
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<n1;i++){
            mp1[p[i]]++;
            mp2[s[i]]++;
        }
        if(mp1==mp2) ans.push_back(0);
        
        int l=0;
        for(int r=n1;r<n;r++){
            if(mp2[s[l]]==1) mp2.erase(s[l]);
            else mp2[s[l]]--;
            l++;
            mp2[s[r]]++;
            if(mp1==mp2) ans.push_back(l);
        }
        
        return ans;
    }
};