class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size(), lbl = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> vis(n*n+1,-1);
        queue<int> q;
        q.push(1);
        int steps=0;
        while (!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++){
            int curr = q.front();
            q.pop();
            if(curr==n*n) return steps;
            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (vis[destination] == -1) {
                    vis[destination] = 1;
                    q.push(destination);
                    if(destination==n*n) return steps+1;
                }
            }
          }
             steps++;
        }
        return -1;
    }
};