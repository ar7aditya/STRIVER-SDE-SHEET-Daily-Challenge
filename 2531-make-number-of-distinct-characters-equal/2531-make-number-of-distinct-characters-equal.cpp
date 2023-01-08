class Solution {
public:
    
    void removemp(unordered_map<char,int>&mp, char c){  
        mp[c]--;
        if(mp[c]==0) mp.erase(c); 
    }
    
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> mp1, mp2;
        
        for(char w1: word1) mp1[w1]++; 
        for(char w2: word2) mp2[w2]++; 

        for(char c1='a'; c1<='z'; c1++){
            for(char c2='a'; c2<='z'; c2++){
                if(mp1.count(c1)==0 || mp2.count(c2)==0) continue; 
                
                removemp(mp1, c1);
                mp1[c2]++;
                
                removemp(mp2, c2);
                mp2[c1]++;
                
                if(mp1.size()==mp2.size()) return true;  
                
                mp1[c1]++;
                removemp(mp1, c2);
                
                mp2[c2]++;
                removemp(mp2, c1);
                
            }
        }
        
        return false;
    }
};