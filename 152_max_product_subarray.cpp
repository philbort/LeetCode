/*

152. Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/

class Solution {

public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())    return 0;
        int max_sum_so_far = nums[0];
        int current_max_sum_so_far = nums[0];
        int current_min_sum_so_far = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            // If the current number is < 0, we need to multiple it by the current
            // min to get a max number
            if(nums[i] < 0)
                swap(current_max_sum_so_far, current_min_sum_so_far);
            
            // Other than the situation above, we do the regular tracking just 
            // like the buy/sell stock problem     
            current_max_sum_so_far = max(current_max_sum_so_far*nums[i], nums[i]);
            // For the reason above, we have to track current min all the time
            current_min_sum_so_far = min(current_min_sum_so_far*nums[i], nums[i]);
            
            max_sum_so_far = max(current_max_sum_so_far, max_sum_so_far);

        }
        return max_sum_so_far;
    }
};
