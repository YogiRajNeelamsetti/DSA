class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            int price = prices[i] - buy;

            profit = max(profit, price);

            buy = min(buy, prices[i]);
            
        }

        return profit;
    }
};