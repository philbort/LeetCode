/*

123. Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    // Time: O(n)
    // Space O(1)   
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)   return 0;
        // Buy has to start as INT_MIN, otherwise we never buy
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (int i = 0; i < n; i++) {
            // The below solution uses two states (cur and next)
            // technically makes more sense.
            // Here we check sell1 right after buy1, but we aren't
            // supposed to buy and sell in the same day.
            // However, if you buy and sell at the same day, you 
            // basically do nothing and it shouldn't impact the 
            // result.
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        // Only return sell2 (not sell1) because sell2 is up to 2 sells
        // and it already included the first sell from dynamic programming
        return sell2;
    }
};

/* Initial solution:

   Time: O(n)
   Space: O(1)
   
   int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)   return 0;
        int dp[2][4] = { INT_MIN, 0, INT_MIN, 0 };
        int cur = 0, next = 1;
        for (int i = 0; i < prices.size(); i++) {
            dp[next][0] = max(dp[cur][0], -prices[i]);
            dp[next][1] = max(dp[cur][1], dp[cur][0] + prices[i]);
            dp[next][2] = max(dp[cur][2], dp[cur][1] - prices[i]);
            dp[next][3] = max(dp[cur][3], dp[cur][2] + prices[i]);
            swap(next, cur);
        }
        return max(dp[cur][1], dp[cur][3]);
    }
    
*/
