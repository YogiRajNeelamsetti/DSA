class Solution {
public:
    int f(vector<int> &prices, int ind, int buy, int n, vector<vector<int>> &dp) {
        if(ind == n) {
            return 0;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy) {
            profit = max(-prices[ind] + f(prices, ind + 1, 0, n, dp), 0 + f(prices, ind + 1, 1, n, dp));
        } else {
            profit = max(prices[ind] + f(prices, ind + 1, 1, n, dp), 0 + f(prices, ind + 1, 0, n, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2), curr(2);

        ahead[0] = ahead[1] = 0;

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy < 2; buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                } else {
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }

                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
    }
};