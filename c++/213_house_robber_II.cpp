/*

213. House Robber II

Note: This is an extension of House Robber.

After robbing those houses on that street, 
the thief has found himself a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)  return (n? nums[0] : 0);
        /* Either rob the first but not the last one, or
           not rob the first one but the last one.
           So we can do from 0 to n-2 and from 1 to n-1,
           and find which one is bigger
        */
        return max( robRange(nums,0,n-2), robRange(nums,1,n-1) );
    }

private:
    int robRange(vector<int>& nums, int first, int last) {
        int withCurrent = 0;
        int withoutCurrent = 0;
        for (int i = first; i <= last; i++) {
            int tmp = withoutCurrent + nums[i];
            withoutCurrent = max(withCurrent, withoutCurrent);
            withCurrent = tmp;
        }
        return max(withoutCurrent, withCurrent); 
    }
};
