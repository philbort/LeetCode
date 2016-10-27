/*

40. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combo;
        helper(candidates, 0, target, combo, result);
        return result;
    }
private:
    void helper(vector<int>& candidates, int start, int target, 
                vector<int>& combo, vector<vector<int>>& result) {
        if(!target) {
            result.push_back(combo);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target < candidates[i])
                return;
            // This skips the duplicates
            if (i != start &&
                candidates[i] == candidates[i-1])
                continue;
            combo.push_back(candidates[i]);
            // "i+1" here to avoid the same candidate
            helper(candidates, i+1, target - candidates[i], combo, result);
            combo.pop_back();
        }
    }
};
