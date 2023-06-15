class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<words.size();i++){
            int bit_mask = 0;
            for(char c : words[i]){
                int x = c-'a';
                bit_mask = ( bit_mask | (1<<x));
            }
            set<char> st;
            for(char c : words[i]){
                if(st.find(c) == st.end()){
                    mp[c].push_back(bit_mask);
                    st.insert(c);
                }
            }
        }
        int n = puzzles.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int puzzle_mask = 0;
            for(char c : puzzles[i]){
                int x = c - 'a';
                puzzle_mask = (puzzle_mask | (1<<x));
            }
            char first_char = puzzles[i][0];
            int count = 0;
            for(int word_mask : mp[first_char]){
                if( (puzzle_mask & word_mask) == word_mask ){
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};