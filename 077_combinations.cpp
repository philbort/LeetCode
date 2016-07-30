/*

77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        // Pre-allocate the memory for k since we know the size
        vector<int> cur(k);
        helper(1, n, k, cur, result);
        return result;
    }
private:
    void helper(int start, int end, int k, vector<int>& cur, vector<vector<int>>& result) {
        if (!k) {
            result.push_back(cur);
            return;
        }
        for(int i = start; i <= end; i++) {
            /* instead of cur.push_back(i)
               and cur.pop_back();
               just do this since we know 
               the size:
            */
            // cur.push_back(i);
            cur[cur.size() - k] = i;
            helper(i+1, end, k-1, cur, result);
            // cur.pop_back();
        }
        
    }
};

