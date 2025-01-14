class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;

        for(int i = 0; i < prices.size(); i++) {

            int price = prices[i] - buy;

            if(profit < price) {
                profit = price;
            }

            if(prices[i] < buy) {
                buy = prices[i];
            }

        }

        return profit;
    }
};