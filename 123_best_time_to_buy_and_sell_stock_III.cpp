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
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (int i = 0; i < n; i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
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
