/*

153. Find Minimum in Rotated Sorted Array   

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/

class Solution {

public:

    int findMin(vector<int>& nums) {

        int size = nums.size();
        int left = 0, right = size -1;
        
        while(left < right)
        {
            if( nums[left] <= nums[right] )
                return nums[left];
                
            int mid = left + (right - left)/2;
            
            if(nums[mid] >= nums[left] && nums[mid] >= nums[right])
                left = mid + 1;
            else if(nums[mid] <= nums[left] && nums[mid] <= nums[right])
                right = mid;
        }
        return nums[left];
    }
};