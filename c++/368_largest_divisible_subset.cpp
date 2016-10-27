/*

368. Largest Divisible Subset

Given a set of distinct positive integers, 
find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]

*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        // Dynamic programming to track the sizes
        vector<int> dp(nums.size(), 0);
        // Vector to back track the indices belong to the subset
        vector<int> back_track(nums.size());
        
        int max = 0;    // Largest number of the subset
        int ind = 0;    // Beginning index of the subset
        
        // If go from left to right we need to reverse the result
        for(int i = nums.size() - 1; i >= 0; --i) 
        {
            // j == i guarantees to save at least 1 number
            for(int j = i; j < nums.size(); ++j)
            {
                // If divisible and the size is bigger
                if(nums[j] % nums[i] == 0 && dp[i] < 1 + dp[j])
                {
                    // Save the new size
                    dp[i] = 1 + dp[j];
                    // Back track the last index
                    back_track[i] = j;
                    
                    if(dp[i] > max)
                    {
                        // Set the new largest size
                        max = dp[i];
                        // Set the new beginning index
                        ind = i;
                    }
                }
            }
        }
        vector<int> result(max);
        for(int i = 0; i < max; ++i)
        {
            result[i] = nums[ind];
            ind = back_track[ind];
        }
        
        return result;
    }
};
