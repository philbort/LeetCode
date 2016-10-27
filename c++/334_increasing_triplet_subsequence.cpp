/*

334. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

*/

class Solution {

public:

    bool increasingTriplet(vector<int>& nums) {
    	
        /* Keep updating the small and mid values,
           if we find a value bigger than both of them
           we have an increasing triplet
       */
        int small = INT_MAX, mid = INT_MAX;
        for (int x: nums) {
            if (x <= small)
                small = x;
            else if ( x <= mid)
                mid = x;
            else
                return true;
        }
        return false;
    }
};
