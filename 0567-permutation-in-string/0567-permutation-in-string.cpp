class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        unordered_map<char,int> mp1,mp2;
        for(char i : s1){
            mp1[i]++;
        }
        for(int i=0;i<n1;i++){
            mp2[s2[i]]++;
        }
         if(mp1==mp2) return true;
        int k=0;
        for(int i=n1;i<n2;i++){
            if(mp2[s2[k]]==1) mp2.erase(s2[k]);
            else{
                mp2[s2[k]]--;
            }
            mp2[s2[i]]++;
            if(mp1==mp2) return true;
            k++;
        }
        return false;
    }
};