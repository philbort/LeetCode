/*

169. Majority Element 

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

class Solution {

public:

    int majorityElement(vector<int>& nums) {

        std::sort(nums.begin(),nums.end());

        return nums[nums.size()/2];
    }
};

/*

O(n) solution:

public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;

        }
        return major;
    }
}

*/