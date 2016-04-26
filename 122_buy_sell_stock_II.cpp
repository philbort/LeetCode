/*

122. Best Time to Buy and Sell Stock II   

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {

public:

    int maxProfit(vector<int>& prices) {

        int res = 0, n = prices.size();

        // Simply add all the positive differences together
        for (int i = 0; i < n-1; i++)
            res += max(0, prices[i+1] - prices[i]);
        
        return res;
    }
};