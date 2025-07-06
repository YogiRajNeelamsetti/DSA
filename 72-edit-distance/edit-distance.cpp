class Solution {
public:
    int f(string &s1, string &s2, vector<vector<int>> &dp, int i, int j) {
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = f(s1, s2, dp, i - 1, j - 1);
        } else {
            return dp[i][j] = min({
                1 + f(s1, s2, dp, i, j - 1),
                1 + f(s1, s2, dp, i - 1, j),
                1 + f(s1, s2, dp, i - 1, j - 1)
            });
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++) {
            curr[0] = i;
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = min({
                        1 + prev[j],
                        1 + curr[j - 1],
                        1 + prev[j - 1]
                    });
                }
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};