/*

33. Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

class Solution {

public:
	
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if(target == nums[mid])
                return mid;
            /* At MOST one of the left and right
               arrays is NOT sorted
            */
            // If left is sorted
            if(nums[left] <= nums[mid])
            {
                // If target is within left, search left
                if(target >= nums[left] &&
                   target < nums[mid])
                    right = mid - 1;
                // If not, search right
                else
                    left = mid + 1;
            }
            // If right is sorted
            else
            {
                // If target is within right, search left
                if(target > nums[mid] &&
                   target <= nums[right])
                    left = mid + 1;
                // If not, search left
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
