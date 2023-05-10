class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n));
        int k=1;
        int left = 0 , right = n-1 , top = 0 , bottom = n-1;
        while(left<=right && top<=bottom){
           for(int i=left ;i<=right;i++){
                matrix[top][i] = k++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                matrix[i][right] = k++;
            }
            right--;
            for(int i=right ; i>= left ;i--){
               matrix[bottom][i] = k++;
            }
            bottom--;
            for(int i=bottom ;i>=top ; i--){
                matrix[i][left] = k++;
            }
            left++;
        }
         vector<vector<int>> ans(n);
        int i = 0;
        while(i<n){
            for(int j=0;j<n;j++){
                ans[i].push_back(matrix[i][j]);
            }
            i++;
        }
        return ans;
    }
};