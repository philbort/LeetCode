/*

448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            while(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i+1)
                res.push_back(i+1);
        }
        return res;
    }
};
