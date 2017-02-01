/*

238. Product of Array Except Self 

Given an array of n integers where n > 1, nums, 
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

*/

class Solution {
public:
    /* A left to right pass of everything on the left side
       plus a right to left pass of everything on the right
       side
    */
    // Time: O(n)
    // Space: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0)  return vector<int> ();
        
        // Initialize the output to 1
        vector<int> res(n,1);
        
        // First pass, multiply everything on the left 
        // side of the number
        for (int i = 1; i < n; i++)
            res[i] = nums[i-1] * res[i-1];
            
        // Second pass, multiply everything on the right
        // side of the number
        int right_prod = 1;
        for (int i = n-1; i >= 0; i--)
        {
            res[i] *= right_prod;
            right_prod *= nums[i];
        }
        // Then we have everything from the left and right sides
        // except the number itself
        return res;
    }
};
