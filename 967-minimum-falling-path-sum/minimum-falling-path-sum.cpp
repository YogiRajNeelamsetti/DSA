class Solution {
public:
    // int recursion(vector<vector<int>>& matrix, int n, int m, int i, int j, vector<vector<int>> &dp) {
    //     if(j < 0 || j > m - 1) return 1e9;
    //     if(i == 0) return matrix[0][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = matrix[i][j] + recursion(matrix, n, m, i - 1, j, dp);
    //     int left = matrix[i][j] + recursion(matrix, n, m, i - 1, j - 1, dp);
    //     int right = matrix[i][j] + recursion(matrix, n, m, i - 1, j + 1, dp);

    //     return dp[i][j] = min({up, left, right});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m);

        for(int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++) {
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++) {
                int up = matrix[i][j];
                int left = matrix[i][j];
                int right = matrix[i][j];
                up += prev[j];
                if(j > 0) left += prev[j - 1];
                else left += 1e9;

                if(j < m - 1) right += prev[j + 1];
                else right += 1e9;

                curr[j] = min({up, left, right});
            }
            prev = curr;
        }

        int maxi = INT_MAX;

        for(int j = 0; j < m; j++) {
            maxi = min(maxi, prev[j]);
        }

        return maxi;
    }
};