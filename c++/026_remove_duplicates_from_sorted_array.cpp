/*

26. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.

*/

class Solution {
    
public:
    // Time: O(n)
    // Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) 
            return size;
        int cnt = 1;
        for (int i = 1; i < size; i++)
        {
            if( nums[i] != nums[cnt-1])
                nums[cnt++] = nums[i];
        }
        return cnt;
    }
};
