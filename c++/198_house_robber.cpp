/*

198. House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that 
adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {

public:
	
    int rob(vector<int>& nums) {
        if (nums.empty())   return 0;
        int n = nums.size();
        int withCurrent = 0;
        int withoutCurrent = 0;
        for (int i = 0; i < n; i++) {
            // Look the below solution to understand here
            int tmp = withoutCurrent + nums[i];
            withoutCurrent = max(withCurrent, withoutCurrent);
            withCurrent = tmp;
        }
        return max(withoutCurrent, withCurrent);
    }
};

/*  First solution, bad space complexity
    Do not need to save the past "w/o current"
    
    int rob(vector<int>& nums) {
        if (nums.empty())   return 0;
        int n = nums.size();
        vector<int> withCurrent(n);
        vector<int> withoutCurrent(n);
        withCurrent[0] = nums[0];
        withoutCurrent[0] = 0;
        for (int i = 1; i < n; i++) {
            withCurrent[i] = withoutCurrent[i-1] + nums[i];
            withoutCurrent[i] = max(withCurrent[i-1], withoutCurrent[i-1]);
        }
        return max(withoutCurrent[n-1], withCurrent[n-1]);
    }
    
*/

/*  cleaner one

    int rob(vector<int>& nums) { 
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
*/
