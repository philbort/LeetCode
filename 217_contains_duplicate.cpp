/*

217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

*/

class Solution {
public:
    // Use unordered_map, O(n) time and space
    // however, O(1) time at best if the duplicate
    // appears early i.e., no need to traverse the
    // entire thing
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num: nums) {
            if(++map[num] > 1)
                return true;
        }
        return false;
    }
};

/* Use unordered_set, O(n) time and space

    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();        
    }
    
*/
