/*

35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

class Solution {

public:
    // Time: O(logn)
    // Space: O(1)
    int searchInsert(vector<int>& nums, int target) {
        
        // Binary search
        int left = 0, right = nums.size(), mid = 0;
        while (left < right)
        {
            mid = left + (right - left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return right;
    }
};
