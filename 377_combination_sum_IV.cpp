/*

377. Combination Sum IV

Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Use dynamic programming
        vector<int> dp(target+1, 0);
        // There is only one way for "0", an empty set
        dp[0] = 1;
        /* Use the example:
           nums = [1, 2, 3]
           target = 4
           we have:
            dp:  0, 1, 2, 3, 4
         value:  1, 1, 2, 4, 7
         
         To find the combo for 4, we need to find how many
         different ways we can represent 4 given the values
         1, 2, 3. so dp[4] = dp[1] + dp[2] + dp[3] = 7
        */
        for(int i = 1; i < target+1; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i >= nums[j])
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }

};
