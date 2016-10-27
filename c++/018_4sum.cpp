/*

18. 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/

class Solution {

public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        int size = nums.size();
        if (size < 4)
            return result;
            
        sort(nums.begin(), nums.end());

        for (int first = 0; first < size-3; first++)
        {
            // If the sum of the four smallest values already too big, break
            if (nums[first] + nums[first+1] + nums[first+2] + nums[first+3] > target)
                break;
            // If the sum of the three biggest and the first valus still too small,
            // move forward the first
            if (nums[first] + nums[size-1] + nums[size-2] + nums[size-3] < target)
                continue;
                
            for( int second = first +1; second < size-2; second++)
            {
                // same as above (those are the keys to reduce time complexity)
                if (nums[first] + nums[second] + nums[second+1] + nums[second+2] > target)
                    break;
                if (nums[first] + nums[second] + nums[size-1] + nums[size-2] < target)
                    continue;
                
                int curTarget = target - nums[first] - nums[second];
                int third = second + 1;
                int forth = size - 1;
                
                while( third < forth )
                {
                    if (nums[third] + nums[forth] == curTarget)
                    {
                        vector<int> curSum(4,0);
                        curSum[0] = nums[first];
                        curSum[1] = nums[second];
                        curSum[2] = nums[third];
                        curSum[3] = nums[forth];
                        result.push_back(curSum);
                        while(nums[third] == curSum[2])
                            third++;
                        while(nums[forth] == curSum[3])
                            forth--;
                    }
                    else if (nums[third]+nums[forth] < curTarget)
                        third++;
                    else
                        forth--;
                }
                while(second < size-1 && nums[second] == nums[second+1])
                    second++;
            }
            while( first < size-2 && nums[first] == nums[first+1])
                first++;
            
        }
        return result;
    }
};
