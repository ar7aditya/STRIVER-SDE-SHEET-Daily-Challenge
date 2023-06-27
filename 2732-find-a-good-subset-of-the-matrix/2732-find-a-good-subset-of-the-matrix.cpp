class Solution {
public:
    int create_number(vector<int>& v){
        int n = v.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += ((1<<i) * v[i]);
        }
        return ans;
    }
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // checking single row
        for(int i=0;i<m;i++){
            int c = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 ) c++;
            }
            if(c == n) return {i};
        }
        // making grid a single column grid -->  m x 1
        vector<int> v(m);
        for(int i=0;i<m;i++){
            v[i] = create_number(grid[i]);
        }
        // checking two row
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if( (v[i] & v[j]) == 0 ) return {i,j};
            }
        }
        return {};
    }
};