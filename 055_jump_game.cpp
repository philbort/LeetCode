/*

55. Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.


*/

class Solution {
	
public:
    /* Dynamic programming, keep checking
       the furthest we can reach
    */
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2)
            return true;
        int max_reach = 0;
        // i <= max_reach is the key
        for(int i = 0; i <= max_reach; i++){
            max_reach = max(max_reach, i + nums[i]);
            if(max_reach >= nums.size() - 1 )
                return true;
        }
        return false;
    }
};

/*  Check all the 0 and negative points whether we can
    jump over them

    bool canJump(vector<int>& nums) {
        if(nums.size() < 2)
            return true;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] <= 0) {
                bool canJumpThisOne = false;
                for (int j = i - 1; j >= 0; j--) {
                    if(nums[j] > i - j) {
                        canJumpThisOne = true;
                        break;
                    }
                }
                if(!canJumpThisOne)
                    return false;
            }
        }
        return true;
    }
