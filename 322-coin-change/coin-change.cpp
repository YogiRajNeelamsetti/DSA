class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, - 1));

        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = INT_MAX;
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                int notTake = 0 + dp[i - 1][t];
                int take = 1e9;

                if(coins[i] <= t) take = 1 + dp[i][t - coins[i]];

                dp[i][t] = min(take, notTake);
            }
        }

        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }
};