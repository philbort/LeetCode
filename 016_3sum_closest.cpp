/*

16. 3Sum Closest 

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {

public:

    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int result = nums[0] + nums[1] + nums[2];
        
        for (int first = 0; first < nums.size() - 2; first++)
        {
            int second = first + 1;
            int third = nums.size() - 1;
            while( second < third )
            {
                int sum = nums[first] + nums[second] + nums[third];
                // Update the closest 
                if (abs(target - sum) < abs(target - result))
                    result = sum;
                // if too big, move back the third
                if (sum > target)
                    third--;
                // if too small, move forward the second
                else if (sum < target)
                    second++;
                // if equal, cannot do better, return the value
                else
                    return sum;
            }
            /* skip the same values for third,have to move the first 
               till we couldn't find a second and a third
               think as S = {0,0,0,0,0,0,0,0}
            */
            while (first < nums.size() - 1 && nums[first] == nums[first+1])
                first++;
        }
       return result; 
    }
};
