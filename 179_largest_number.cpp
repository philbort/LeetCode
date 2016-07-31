/*

179. Largest Number 

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Customerized sort by comparing string 
        sort(nums.begin(), nums.end(), [](const int a,const int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string result;
        for (int i = 0; i < nums.size(); i++)
            result += to_string(nums[i]);
        // If '0', make sure to not output "00" etc.
        // Also, '' for char, "" for string
        return result[0] == '0' ? "0" : result; 
    }   
};
