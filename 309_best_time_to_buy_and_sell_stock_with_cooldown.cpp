/*

309. Best Time to Buy and Sell Stock with Cooldown

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

*/



/* Four states are used for the dp: 
buy, sell, coolDown and noOp, 
where noOp happens between buy and sell, 
coolDown happens between sell and buy.

It is actually much more straight forward if you use O(n) space.

buy[i] -- buy stock i

sell[i] -- sell stock i

noOp[i] -- no operation for stock i, but have one stock at hand

coolDown[i] -- no operation for stock i, and have no stock at hand.

Then the update works as:
buy[i] = coolDown[i-1]-prices[i], 
coolDown[i] = max(coolDown[i-1], sell[i-1]), 
noOp[i] = max[noOp[i-1], buy[i-1]]], and
sell[i] = max(noOp[i-1], buy[i-1]) + prices[i].

The constant space solution readily follows this since current states for price i only depends on previous states for price i-1.
*/

class Solution {

public:

    int maxProfit(vector<int>& prices) {
    
        int buy = INT_MIN, noOp = INT_MIN;
        int coolDown = 0, sell = 0;
    
        for (int p : prices) {
            noOp = max(noOp, buy);
            buy = coolDown - p;
            coolDown = max(coolDown, sell);
            sell = noOp + p;
        }
        return max(coolDown, sell);
    }
};
