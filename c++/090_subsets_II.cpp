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
        /* For alll the duplicates, use "cnt" to count how 
           many times they appear. In the result, the duplicate
           should either appear none, once, twice, .. till cnt.
        */
        vector<vector<int>> result(1, vector<int>());
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()) {
            // Track the number of duplicate apperance
            int cnt = 0;
            while(i + cnt < nums.size() && nums[i+cnt] == nums[i])
                cnt++;
            int m = result.size();
            for (int j = 0; j < m; j++) {
                vector<int> current = result[j];
                // All the combination for the duplicates
                for(int k = 0; k < cnt; k++) {
                    current.push_back(nums[i]);
                    result.push_back(current);
                }
            }
            i += cnt;
            
        }
        return result;
    }
};

/* Recursion:

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
    
*/
