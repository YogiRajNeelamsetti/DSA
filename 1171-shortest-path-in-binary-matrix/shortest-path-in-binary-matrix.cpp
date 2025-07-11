class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // if(grid[0][0] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0] == 0) {
            q.push({1, {0, 0}});
            dist[0][0] = 1;
        }

        while(!q.empty()) {
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if(r == n - 1 && c == m - 1) return dis;

            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int nrow = r + i;
                    int ncol = c + j;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && dist[nrow][ncol] > dis + 1) {
                        dist[nrow][ncol] = dis + 1;
                        q.push({dis + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};