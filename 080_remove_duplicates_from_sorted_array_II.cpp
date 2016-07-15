/*

80. Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.

*/

class Solution {
	
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 3)
            return size;
        int cnt = 2;
        for (int i = 2; i < size; i++){
            if(nums[i] != nums[cnt-2])
                nums[cnt++] = nums[i];
        }
        return cnt;
    }
};

