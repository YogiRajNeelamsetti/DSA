class Solution {
public:
    const int MOD = 1e9 + 7;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1;

        for(long long coin : coins) {
            for(long long t = coin; t <= amount; t++) {
                dp[t] = dp[t] + dp[t - coin];
            }
        }

        return dp[amount];
    }
};