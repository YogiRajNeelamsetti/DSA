class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(string &s, int n, int i, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;

        for(int j = i; j < n; j++) {
            if(isPalindrome(s, i, j)) {
                int cost = 1 + f(s, n, j + 1, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }
    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for(int j = i; j < n; j++) {
                if(isPalindrome(s, i, j)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};