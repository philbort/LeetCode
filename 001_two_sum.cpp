/*

1. Two Sum 

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
    
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash;
        
        for( int i = 0; i < nums.size(); ++i )
        {
            int find_number = target - nums[i];
            
            if( hash.find(find_number) != hash.end() )
                return {hash[find_number], i};
            else
                hash[nums[i]] = i;
                
        }
        return {};
    }
        
};