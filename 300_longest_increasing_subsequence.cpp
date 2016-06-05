/*

300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

*/


class Solution {
public:
    // O(n^2) solution
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())   return 0;
        vector<int> dp(nums.size());
        int result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }

};

/* WTF O(nlogn) solution
http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (int num : nums) {
            if (num > ends.back()) ends.push_back(num);
            else {
                int l = 0, r = ends.size() - 1;
                while (l < r) {
                    int m = l + (r - l) / 2;
                    if (ends[m] < num) l = m + 1;
                    else r = m;
                }
                ends[r] = num;
            }
        }
        return ends.size();
    }

*/
