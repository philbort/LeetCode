/*

90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        getsubset(nums, 0, current, result);
        return result; 
    }
private:
    void getsubset(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for(int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i-1]) {
                current.push_back(nums[i]);
                getsubset(nums, i+1, current, result);
                current.pop_back();
            }
        }
    }    
    
};
