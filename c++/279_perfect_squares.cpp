/*

279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

*/

class Solution {
	
public:
    /* Static dynamic programming, make the dp vector static
       so we can use it over and over again without recalculating
    */
    int numSquares(int n) {
        if (n < 1)  return 0;
        static vector<int> dp({0});
        while(dp.size() <= n) {
            int m = dp.size();
            int currentCnt = INT_MAX;
            for (int i = 1; i*i <= m; i++)
                currentCnt = min(currentCnt,dp[m-i*i]+1);
            dp.push_back(currentCnt);
        }
        return dp[n];
    }
};

/* Dynamic programming, pretty much the same
   as the coin change problem:

    int numSquares(int n) {
        if (n < 1)  return 0;
        vector<int> dp(n+1,n);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i],dp[i-j*j]+1);
        }
        return dp.back();
    }
*/
