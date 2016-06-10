/*

75. Sort Colors

Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

*/

class Solution {
	
public:
    void sortColors(vector<int>& nums) {
        int redInd = 0, blueInd = nums.size() - 1;
        for (int i = 0; i <= blueInd; i++) {
            while (nums[i] == 2 && i < blueInd)
                swap(nums[i], nums[blueInd--]);
            while (nums[i] == 0 && i > redInd)
                swap(nums[i],nums[redInd++]);

        }
    }
};
