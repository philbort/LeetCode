/*

121. Best Time to Buy and Sell Stock 

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPro = 0;
        for (int i = 0; i < prices.size(); i++) {
            
            // The order of the following two commands doesn't matter
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};

/*
    // Time: O(n)
    // Space: O(1)
    // Same as the maximum sub-array question
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int current_max = 0, final_max = 0;
        
        for (int i = 0; i < n-1; i++)
        {
            // current sum along the path
            current_max = max(current_max+prices[i+1] - prices[i],0);
            // maximum sum
            final_max = max(current_max, final_max);
        }
        return final_max;
    }
*/
