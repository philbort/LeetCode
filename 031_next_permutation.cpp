/*

31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    // Algorithm from Wikipedia:
    // https://en.wikipedia.org/wiki/Permutation
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        // For "1 2 3 8 7 6 5", k = 2
        for (int i = nums.size()-2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
        /* If it is in descending order, return
           the ascending order per instruction
        */
        if(k == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int l = k+1; // nums[k+1] definitly works 
        // For "1 2 3 8 7 6 5", l = 6
        for (int i = nums.size()-1; i>k+1;i--){
            if(nums[i] > nums[k]){
                l = i;
                break;
            }
        }
        // "1 2 3 8 7 6 5" to "1 2 5 8 7 6 3"
        swap(nums[k], nums[l]);
        // Finally "1 2 5 3 6 7 8"
        reverse(nums.begin()+k+1, nums.end());
    }
};
