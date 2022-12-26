class Solution {
public:
    bool check(int row,int col,char number,vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++) {
           if(board[i][col] == number)  return false;
            if(board[row][i] == number) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==number)  return false;
       }
        return true;
    }
    
    bool f(int row,int col,vector<vector<char>>& board){
       if(row == board.size()) {
           return true;
       }
      
       int nrow = 0;
       int ncol = 0;
      
       if(col == board.size()-1) {
           nrow = row + 1;
           ncol = 0;
       } else {
           nrow = row;
           ncol = col + 1;
       }
      
       if(board[row][col] != '.') {
           if(f( nrow, ncol,board)) {
               return true;
           }
       } else {
           for(char i='1'; i<='9'; i++) {
               if(check(row, col, i,board)) {
                   board[row][col] =i;
                   if(f(nrow, ncol,board))
                       return true;
                   else
                        board[row][col] = '.';
               }
           }
       }
                     
       return false;

    }
        
    void solveSudoku(vector<vector<char>>& board) {
        f(0,0,board);
    }
};