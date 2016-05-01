/*

53. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_sum_so_far = nums[0];
        int current_sum_so_far = nums[0];

        for (int i = 1; i < nums.size(); i++)

        {
        	/* Current compare to nums[i], not 0.
        	 * different from the buy/sell stock question
			   because here we have to choose a number,
			   but you don't have to buy any stock.
			   Here result can be smaller than 0, with 
			   stock the answer is never smaller than 0.
			 */
            current_sum_so_far = max(current_sum_so_far+nums[i],nums[i]);

            max_sum_so_far = max(current_sum_so_far, max_sum_so_far);
        }
        return max_sum_so_far;
    }
};
