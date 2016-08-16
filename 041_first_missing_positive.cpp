/*

41. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Swap the values to the correct indices
        for(int i = 0; i < nums.size(); i++) {
            // Have to do while loop here in order to reach every one of the values
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i] )
                swap(nums[i], nums[nums[i] -1]);
        }
        // Find the first missing positive
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1)
                return i+1;
        }
        // Otherwise return the size plus as it is the next value
        return nums.size() + 1;
    }
};
