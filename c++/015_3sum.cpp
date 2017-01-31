
/*

15. 3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

class Solution {

public:
    // Time: O(nlogn)
    // Space: O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        if(nums.empty())    return result;

        sort(nums.begin(), nums.end());
        
        // -2 to have two more values on the right side
        for (int first = 0; first < nums.size() - 2; first++)
        {
            /* Second and third are both bigger than 
               or equal to the first one. If the first
               one is positive, then three positive 
               can't make a zero.
            */
            if (nums[first] > 0)
                break;
                
            int target = -nums[first];
            int second = first + 1;
            int third = nums.size() - 1;

            while( second < third)
            {
                // Same thing as before
                if (nums[first] + nums[second] > 0)
                    break;
                int sum = nums[second] + nums[third];
                // Too small, move forwad the second one
                if (sum < target)
                    second++;
                // Too big, move back the third one
                else if (sum > target)
                    third--;
                // Save the result
                else
                {
                    vector<int> triplet(3,0);
                    triplet[0] = nums[first];
                    triplet[1] = nums[second];
                    triplet[2] = nums[third];
                    result.push_back(triplet);
                    // skip the same values for second
                    while(second<third && nums[second] == triplet[1])
                        second++;
                    // skip the same values for third
                    while(second<third && nums[third] == triplet[2])
                        third--;
                }
            }
            /* skip the same values for first,have to move the first 
               till we couldn't find a second and a third
               think as S = {0,0,0,0,0,0,0,0}
            */ 
            while (first < nums.size() - 1 && 
                   nums[first] == nums[first+1])
                first++;
        }
        return result;
    }
};
