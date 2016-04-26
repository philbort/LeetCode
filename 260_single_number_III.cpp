/*

260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int n = 0;

        // First pass find out the XOR of the two distinct numbers
        for(int i = 0; i < nums.size(); i++)
            n ^= nums[i];

        // Save the result
        vector<int> result = {n, n};

        // The two numbers are different, so they must have at least one different bit
        // Find the right most bit "1", that would be the one of the bits those two number differ
        int diff = n&(n-1)^n;

        for(int i = 0; i < nums.size();i++)
        {
        	// Find the number with that bit = 1
            if(nums[i]&diff)
            {
                result[0] ^= nums[i];
            }
            // Find the number with that bit = 0
            else
            {
                result[1] ^= nums[i];
            }
        }
        return result;
    }
};