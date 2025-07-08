class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int tran = 2 * k - 1; tran >= 0; tran--) {
                if(tran % 2 == 0) {
                    dp[i][tran] = max(-prices[i] + dp[i + 1][tran + 1], 0 + dp[i + 1][tran]);
                } else {
                    dp[i][tran] = max(prices[i] + dp[i + 1][tran + 1], 0 + dp[i + 1][tran]);
                }
            }
        }

        return dp[0][0];
    }
};