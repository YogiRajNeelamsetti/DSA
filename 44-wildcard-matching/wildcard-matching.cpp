class Solution {
public:
    // bool f(string &s, string &p, vector<vector<bool>> &dp, int i, int j) {
    //     if(i < 0 && j < 0)
    //         return true;
    //     if(i < 0 && j >= 0) {
    //         for(int jj = 0; jj <= j; jj++) {
    //             if(p[jj] != '*') 
    //                 return false;
    //         }
    //         return true;
    //     }
    //     if(j < 0 && i >= 0) 
    //         return false;

    //     if(s[i] == p[j] || p[j] == '?') 
    //         return dp[i][j] = f(s, p, dp, i - 1, j - 1);
        
    //     if(p[j] == '*')
    //         return dp[i][j] = f(s, p, dp, i - 1, j) | f(s, p, dp, i, j - 1);
        
    //     return dp[i][j] = false;
    // }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;

        for(int j = 1; j <= m; j++) {
            bool flag = true;
            for(int jj = 1; jj <= j; jj++) {
                if(p[jj - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1; i <= n; i++) {
            // curr[0] = false;
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }

                else if(p[j - 1] == '*') {
                    curr[j] = prev[j] | curr[j - 1];
                }

                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};