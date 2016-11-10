/*

453. Minimum Moves to Equal Array Elements  

Given a non-empty integer array of size n, 
find the minimum number of moves required to make all array elements equal, 
where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int minMoves(vector<int>& nums) {
        int sum = 0, min_num = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            min_num = min(nums[i], min_num);
        }
        return sum - min_num * n;
    }
};
