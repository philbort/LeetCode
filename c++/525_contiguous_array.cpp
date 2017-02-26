/*

525. Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/


// See https://discuss.leetcode.com/topic/80056/python-o-n-solution-with-visual-explanation
class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int sum = 0, res = 0;
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if(map.find(sum) != map.end())
                res = max(res, i - map[sum]);
            else
                map[sum] = i;
        }
        return res;
    }
};
