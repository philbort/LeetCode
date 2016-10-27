/*

137. Single Number II

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/


class Solution {

public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        int ans = 0;
        
        // Get the counts for every bit 
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < 32; j++)
            {
                bits[j] += nums[i] & 1;
                nums[i] >>= 1;
                if (!nums[i])
                    break;
            }
        }
        // Every bit%3 should be either 0 or 1
        for (int j = 0; j < 32; j++)
        {
            // If 1, there is a bit for the number
            if (bits[j]%3 != 0)
            {
                ans |= 1 << j;
            }
        }
        return ans;
    }
};



/*

class Solution {
  public:
    int singleNumber(vector<int>& nums) {
        int counterOne = 0;
        int counterTwo = 0;

        for (int i = 0; i < nums.size(); i++){
            counterOne = (~counterTwo) & (counterOne ^ nums[i]);
            counterTwo = (~counterOne) & (counterTwo ^ nums[i]);
        }
        return counterOne;
    }
};

*/