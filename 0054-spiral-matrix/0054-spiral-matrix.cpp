class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int max_row = matrix.size();
        int max_col = matrix[0].size();
        int row = 0;
        int col = 0;
        int min_row = 1;
        int min_col = 0;
        vector<int> ans;
        int k = max_row * max_col;
        while(min_row<=max_row && min_col<=max_col){
            if(k==0) return ans;
            if(min_col==max_col && min_row==max_row && min_row==min_col) return ans;
            while(col<max_col){
                ans.push_back(matrix[row][col]);
                k--;
                col++;
            }
            if(k==0) return ans;
            ans.pop_back();
            k++;
            col--;
            max_col--;
            while(row<max_row){
               ans.push_back(matrix[row][col]);
                k--;
                row++;
            }
            if(k==0) return ans;
            ans.pop_back();
            k++;
            row--;
            max_row--;
            while(col>=min_col){
                ans.push_back(matrix[row][col]);
                k--;
                col--;
            }
            if(k==0) return ans;
            ans.pop_back();
            k++;
            col++;
            min_col++;
            while(row>=min_row){
               ans.push_back(matrix[row][col]);
                k--;
               row--;
            }
            if(k==0) return ans;
            ans.pop_back();
            k++;
            row++;
            min_row++;
        }
        return ans;
    }
};