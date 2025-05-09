class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n) {
        int r = row, c = col;

        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row, c = col;

        while(c >= 0) {
            if(board[r][c] == 'Q') return false;
            c--;
        }

        r = row, c = col;

        while(r < n && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }

    void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col) {

        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(ans, board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n);

        for(int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<vector<string>> ans;
        solve(ans, board, n, 0);

        return ans;
    }
};