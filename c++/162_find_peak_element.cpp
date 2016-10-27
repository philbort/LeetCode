/*

162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

*/

class Solution {

public:

    int findPeakElement(vector<int>& nums) {
    	
        // basically a binary search
        int len = nums.size();
        if ( len < 1 ) return 0;
        int left = 0, right = len - 1;
        while (left < right)
        {
            int mid = left + (right - left)/2;
            /* go to the bigger side since it 
               will for sure has a peak. If
               numbers keep going up from mid+1,
               the last value will be a peak.
               If any number goes down from mid+1,
               then for sure we have a peak between
               mid and the value which goes down
            */
            if (nums[mid] < nums[mid+1] )
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
