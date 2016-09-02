/*

169. Majority Element 

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

class Solution {
public:
    // Time: O(n)  Space: O(1)
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0) {
                majority = nums[i];
                count = 1;
            }
            else if(majority == nums[i])
                count++;
            else
                count--;
            if(count > nums.size()/2)
                return majority;
        }
        return majority;
    }
};

/*

O(nlogn) solution:

    int majorityElement(vector<int>& nums) {

        std::sort(nums.begin(),nums.end());

        return nums[nums.size()/2];
    }

*/
