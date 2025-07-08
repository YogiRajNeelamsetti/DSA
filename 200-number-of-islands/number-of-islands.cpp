class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({i, j});

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<int> di = {-1, 0, 1, 0};
            vector<int> dj = {0, -1, 0, 1};
            for(int k = 0; k < 4; k++) {
                int nrow = row + di[k];
                int ncol = col + dj[k];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    islands++;
                    bfs(grid, vis, i, j);
                    
                }
            }
        }

        return islands;
    }
};