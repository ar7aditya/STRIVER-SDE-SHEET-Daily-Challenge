class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
         if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int low = 0;
        int high = matrix.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(matrix[mid][0] < t) low = mid + 1;
            else if(matrix[mid][0] > t) high = mid - 1;
            else return true;
        }
        int row = high;
        if(row >= 0){
            low = 0;
            high = matrix[row].size() - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(matrix[row][mid] < t) low = mid + 1;
                else if(matrix[row][mid] > t) high = mid - 1;
                else return true;
            }
        }
        return false;
    }
};