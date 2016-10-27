
/*

78. Subsets

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // This inserts a [] as the first element
        vector<vector<int>> result(1, vector<int>());
        /* Take the current number, and add it to the
           end of all the current vectors.
           e.g., [1, 2]:
           first we have [],
           add 1 to it: [], [1],
           then add 2: [], [1], [2], [1,2]
        
        */
        for(int i = 0; i < nums.size(); i++) {
            // Need to declare the size here since
            // it changes in the loop below
            int m = result.size();
            for(int j = 0; j < m; j++) {
                vector<int> current = result[j];
                current.push_back(nums[i]);
                result.push_back(current);
            }
        }
        return result;
    }
};

/* WTF bit manipulation solution:

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num_subset = pow(2, nums.size()); 
        vector<vector<int> > res(num_subset, vector<int>());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < num_subset; j++)
                if ((j >> i) & 1)
                    res[j].push_back(nums[i]);
        return res;  
    }

*/

/*  recursive backtracking:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        getsubset(nums, 0, current, result);
        return result;
    }
private:
    void getsubset(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for(int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            getsubset(nums, i+1, current, result);
            current.pop_back();
        }
    }
    
*/
