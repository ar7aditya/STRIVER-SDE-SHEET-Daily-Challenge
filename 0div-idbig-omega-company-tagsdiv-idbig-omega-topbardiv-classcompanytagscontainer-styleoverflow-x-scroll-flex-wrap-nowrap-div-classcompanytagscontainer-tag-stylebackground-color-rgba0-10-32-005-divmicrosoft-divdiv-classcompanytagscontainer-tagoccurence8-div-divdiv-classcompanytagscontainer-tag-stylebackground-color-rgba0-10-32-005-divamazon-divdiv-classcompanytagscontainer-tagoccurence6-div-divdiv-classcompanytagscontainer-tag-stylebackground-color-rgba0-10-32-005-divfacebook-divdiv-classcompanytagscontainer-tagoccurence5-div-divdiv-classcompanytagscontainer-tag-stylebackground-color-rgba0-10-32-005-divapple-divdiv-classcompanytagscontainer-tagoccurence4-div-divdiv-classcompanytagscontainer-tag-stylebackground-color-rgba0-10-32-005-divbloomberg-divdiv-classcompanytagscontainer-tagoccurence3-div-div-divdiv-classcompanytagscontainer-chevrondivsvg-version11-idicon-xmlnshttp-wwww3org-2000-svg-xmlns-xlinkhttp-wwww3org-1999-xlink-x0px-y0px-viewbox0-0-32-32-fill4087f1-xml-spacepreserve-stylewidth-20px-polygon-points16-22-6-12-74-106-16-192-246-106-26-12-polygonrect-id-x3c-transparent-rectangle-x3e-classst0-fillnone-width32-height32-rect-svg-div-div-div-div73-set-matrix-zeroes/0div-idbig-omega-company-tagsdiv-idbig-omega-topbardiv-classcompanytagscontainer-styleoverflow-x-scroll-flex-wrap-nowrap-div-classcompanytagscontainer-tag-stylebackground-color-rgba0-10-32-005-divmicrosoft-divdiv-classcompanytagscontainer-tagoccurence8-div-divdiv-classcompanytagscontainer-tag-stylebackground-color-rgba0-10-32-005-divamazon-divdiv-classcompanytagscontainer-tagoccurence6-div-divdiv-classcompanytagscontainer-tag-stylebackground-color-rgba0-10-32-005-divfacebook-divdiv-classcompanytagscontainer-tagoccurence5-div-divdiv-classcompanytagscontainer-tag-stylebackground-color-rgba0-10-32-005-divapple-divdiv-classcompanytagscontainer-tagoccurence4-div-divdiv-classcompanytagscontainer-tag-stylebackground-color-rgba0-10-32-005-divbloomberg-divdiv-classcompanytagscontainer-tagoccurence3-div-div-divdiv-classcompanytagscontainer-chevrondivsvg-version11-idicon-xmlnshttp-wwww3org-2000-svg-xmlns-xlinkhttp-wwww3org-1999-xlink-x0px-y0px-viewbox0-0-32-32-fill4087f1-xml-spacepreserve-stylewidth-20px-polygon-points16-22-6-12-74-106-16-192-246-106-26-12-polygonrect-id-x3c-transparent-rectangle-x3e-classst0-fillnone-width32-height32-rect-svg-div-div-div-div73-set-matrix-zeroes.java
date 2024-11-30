class Solution {
    public void setZeroes(int[][] matrix) {
        int firstRow = 0;
        int firstCol = 0;
        int no_of_rows = matrix.length;
        int no_of_cols = matrix[0].length;
        // i represents row
        // j represents col
        for(int j = 0; j < no_of_cols; j++){
            if(matrix[0][j] == 0) firstRow = 1;
        }
        for(int i = 0; i < no_of_rows; i++){
            if(matrix[i][0] == 0) firstCol = 1;
        }
        for(int i = 1; i < no_of_rows; i++){
            for(int j = 1; j < no_of_cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < no_of_rows; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < no_of_cols; j++){
                    matrix[i][j] = 0;
            }
            }
        }
        for(int j = 1; j < no_of_cols; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < no_of_rows; i++){
                    matrix[i][j] = 0;
            }
            }
        }
        if(firstRow == 1){
            for(int i = 0; i < no_of_cols; i++){
                    matrix[0][i] = 0;
            }
        }
        if(firstCol == 1){
            for(int i = 0; i < no_of_rows; i++){
                    matrix[i][0] = 0;
            }
        }
        return;
    }
}