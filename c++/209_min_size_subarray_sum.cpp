/*

209. Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, 
find the minimal length of a subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

*/

class Solution {

public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())   return 0;
        int min_len = INT_MAX;
        int left = 0;
        int sum = 0;
        for( int right = 0; right < nums.size(); right++ ){
            sum += nums[right];
            if (sum >= s) {
                while( sum -nums[left] >= s )
                    sum -= nums[left++];
                min_len = min(min_len, right - left + 1);
                // Can't do better than 1
                if (min_len == 1)
                    return 1;
            }
        }
        return min_len == INT_MAX? 0 : min_len;
    }
};
