/*

322. Coin Change

You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

*/

class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount || coins.empty())
            return 0;
        /* Since coins are postive integers, the biggest valid 
           result is amount (i.e., only coins are 1s).
           So initialize all the results to amount+1.
        */
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        /* This if faster than the more straightforward loop
           below since it excludes several unnecessary loops
        */
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return  dp[amount] > amount ? -1 : dp[amount] ;
    }
};

/*      original loop:

        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
*/
