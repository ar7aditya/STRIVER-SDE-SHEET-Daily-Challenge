class Solution {
public:
    bool check(int row,int col,int number,vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++) {
           if(board[i][col] == (char)(number+'0')) {
               return false;
           }
       }
       for(int j=0; j<board.size(); j++) {
           if(board[row][j] == (char)(number+'0')) {
               return false;
           }
       }
       int sr = 3 * (row/3);
       int sc = 3 * (col/3);
      
       for(int i=sr; i<sr+3; i++) {
           for(int j=sc; j<sc+3; j++) {
               if(board[i][j] == (char)(number+'0')) {
                   return false;
               }
           }
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
           for(int i=1; i<=9; i++) {
               if(check(row, col, i,board)) {
                   board[row][col] = (char)(i+'0');
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