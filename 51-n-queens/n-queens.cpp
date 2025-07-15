class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string> &board) {
        int r = row, c = col;

        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r--, c--;
        }

        r = row, c = col;

        while(c >= 0) {
            if(board[r][c] == 'Q') return false;
            c--;
        }

        c = col;

        while(r < n && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r++, c--;
        }

        return true;
    }
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s = "";

        for(int i = 0; i < n; i++) {
            s += '.';
        }
        vector<string> board(n, s);
        vector<vector<string>> ans;

        solve(0, n, board, ans);

        return ans;
    }
};