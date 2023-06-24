class Solution {
public:
     int dp[1000][26][26] = {};
    int solve(int i ,char begin , char end , vector<string>& words){
        
        if(i >= words.size()) return 0;
        if( dp[i][begin-'a'][end-'a'] != 0) return dp[i][begin-'a'][end-'a'];
        int case1 = 0;
        int case2 = 0;
        
        if(begin == words[i].back()){ 
            case1 = words[i].size() - 1 + solve(i+1,words[i][0] , end , words);
        }
        else{
            case1 = words[i].size() + solve(i+1,words[i][0] , end, words);
        }

        if(end == words[i][0]){ 
            case2 = words[i].size() - 1 + solve(i+1, begin, words[i].back() , words);
        }
        else{
            case2 = words[i].size() + solve(i+1, begin, words[i].back() ,words);
        }
        return dp[i][begin-'a'][end-'a'] =  min(case1,case2);
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        if(words.size() == 1) return words[0].size();
        return words[0].size() + solve(1 ,words[0][0] , words[0].back() , words);
    }
};