class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int best_profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int today_profit = prices[i] - min_price;

            if (today_profit > best_profit) {
                best_profit = today_profit;
            }

            if (prices[i] < min_price) {
                min_price = prices[i];
            }
        }
     return best_profit;
    }
};