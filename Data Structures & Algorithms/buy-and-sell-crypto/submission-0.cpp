class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int ans = 0;
        for(int sell = 0;sell < prices.size();sell++) {
            int profit = prices[sell] - prices[buy];
            ans = max(ans, profit);
            if(prices[sell] < prices[buy]) {
                buy = sell;
            }
        }
        return ans;
    }
};
