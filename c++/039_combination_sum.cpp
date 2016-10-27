/*

39. Combination Sum

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            combo.push_back(candidates[i]);
            // Still "i" here so we can include the same candidate
            helper(candidates, i, target - candidates[i], combo, result);
            combo.pop_back();
        }
    }
};

/* Dynamic programming:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int size = candidates.size();
        if (size == 0) return result;
        sort(candidates.begin(), candidates.end());
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
        dp[0].push_back(vector<int>());
        
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < size && candidates[j] <= i; ++j) {
                for (int k = 0; k < dp[i - candidates[j]].size(); ++k) {
                    vector<int> temp = dp[i - candidates[j]][k];
                    if (temp.size() && (temp[temp.size() - 1] > candidates[j])) continue;
                    temp.push_back(candidates[j]);
                    dp[i].push_back(temp);
                }
            }
        }
        return dp[target];
    }

*/
