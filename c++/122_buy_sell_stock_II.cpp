/*

122. Best Time to Buy and Sell Stock II   

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        for (int i = 1; i < prices.size(); i++)
            maxPro += max(0, prices[i] - prices[i-1]);
        return maxPro;
    }
};
