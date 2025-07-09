class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int ini, int color, vector<int> &drow, vector<int> &dcol, int n, int m) {
        ans[row][col] = color;

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != color && image[nrow][ncol] == ini) {
                dfs(nrow, ncol, image, ans, ini, color, drow, dcol, n, m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            ans[row][col] = color;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != color && image[nrow][ncol] == ini) {
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;
    }
};