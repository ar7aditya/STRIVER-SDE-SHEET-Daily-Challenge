class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<26;i++){
            mp[order[i]]=i+1;
        }
        int n=words.size();
        if(n==1) return true;
        for(int i=0;i<n-1;i++){
            int j=0;
            int size1=words[i].size();
            int size2=words[i+1].size();
            while(j<size1 && j<size2 && words[i][j]==words[i+1][j]) j++;
            if(j==size1) continue;
            if(j==size2) return false;
            if(mp[words[i][j]]< mp[words[i+1][j]]) continue;
            else return false;
        }
        return true;
    }
};