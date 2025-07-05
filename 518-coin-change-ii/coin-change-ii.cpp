class Solution {
public:
    const int MOD = 1e9 + 7;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1, 0));

        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) dp[0][t] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                uint64_t notTake = dp[i - 1][t];
                uint64_t take = 0;

                if(coins[i] <= t) take = dp[i][t - coins[i]];

                dp[i][t] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};