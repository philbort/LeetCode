/*

34. Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

class Solution {
	
public:
    // Time: O(logn)
    // Space: O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result(2, -1);
        int mid;
        // Search for the left bound
        while (left <= right) {
            mid = left + (right - left)/2;
            if(nums[mid] >= target) {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if(nums[left] != target)
            return result;
            
        // Search for the right bound
        result[0] =  left;
        right = nums.size() - 1;
        while(left <= right) {
            mid = left + (right - left)/2;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        result[1] = right;
        
        return result;
    }
};
