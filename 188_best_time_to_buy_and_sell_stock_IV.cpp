/*

188. Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    // Time: O(k*n)
    // Space: O(n)
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2 || k < 1)  return 0;
        
        // If we are allowed to trade enough times ...
        if(k >= n/2) {
            int allPro = 0;
            for(int i = 1; i < n; i++)
                allPro += max(0, prices[i] - prices[i-1]);
            return allPro;
        }
        
        // DP
        int buy[k], sell[k];
        for (int i = 0; i < k; i++) {
            buy[i] = INT_MIN;
            sell[i] = 0;
        }
        for (int i = 0; i < n; i++ ) {
            for (int j = 0; j < k; j++) {
                buy[j] = max(buy[j], (!j? 0 : sell[j-1]) - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k-1];
    }
};
