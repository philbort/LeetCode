/*

154. Find Minimum in Rotated Sorted Array II 

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

*/

class Solution {
public:
    /* Same as binary search in rotated array,
       we just have to make sure that one of 
       left and right arrays is sorted.
       So get rid of the duplicates from one
       side. Here we choose right
    */
    int findMin(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1;
        // Get rid of the duplicates from left
        while(left < right && nums[left] == nums[right])
            left++;
        // Binary search
        while(left < right)
        {
            if( nums[left] <= nums[right] )
                return nums[left];
                
            int mid = left + (right - left)/2;
            
            if(nums[mid] >= nums[left] && nums[mid] >= nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
