class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        // storing 0 for every row and col in first row & col
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //process except the first row and col
        for (int i = 1; i < m; i++) { 
           for (int j = 1; j < n; j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        //handle the first column
        if (isZeroCol) { 
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        //handle the first row
        if (isZeroRow) { 
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
    }
};