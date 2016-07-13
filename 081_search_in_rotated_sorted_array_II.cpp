/*

81. Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

*/

class Solution {
public:
    /* We are good as soon as we don't have duplicates
       on both sides. Duplicates on one side is fine
       since it is still sorted.
       So the key here is to get rid of the duplicates
       which are on both sides
    */
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        // Remove the duplicates on the left side
        while(left < right && nums[left] == nums[right])
                left++;
                
        // Same as the one without duplicate
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if(target == nums[mid])
                return true;
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
        return false;
    }
};
