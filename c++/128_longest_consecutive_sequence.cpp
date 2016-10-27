/*

128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Get all the unique values into a set
        unordered_set<int> set(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            // All the values visited are erased below
            if(set.find(nums[i]) == set.end())
                continue;
            // Find all the -1 consecutive values
            int cur = nums[i], len = 1;
            while(set.find(--cur) != set.end()) {
                len++;
                set.erase(cur);
            }
            cur = nums[i];
            // Find all the +1 consecutive values
            while(set.find(++cur) != set.end()) {
                len++;
                set.erase(cur);
            }
            result = max(result, len);
        }
        return result;
    }
};
