/*

329. Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/

class Solution {

public: 
	
    // Dynamic programming and DFS. O(mn) time and space 
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())  return 0;
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(matrix, dp, i, j));
            }
        }
        return result;
    }

private:

    int dfs(vector<vector<int>>& matrix, vector<vector<int>> & dp, int i, int j) {
        if(dp[i][j] > 0)
            return dp[i][j];
        int a = 0, b = 0, c = 0, d = 0;
        if(i > 0 && matrix[i-1][j] > matrix[i][j])
            a = dfs(matrix, dp, i-1, j);
        // Be aware it's "m-1" here not "m"
        if(i < m - 1 && matrix[i+1][j] > matrix[i][j])
            b = dfs(matrix, dp, i+1, j);
        if(j > 0 && matrix[i][j-1] > matrix[i][j])
            c = dfs(matrix, dp, i, j-1);
        // Be aware it's "n-1" here not "n"
        if(j < n - 1 && matrix[i][j+1] > matrix[i][j])
            d = dfs(matrix, dp, i, j+1);
        dp[i][j] = max(max(a, b), max(c, d)) + 1;
        return  dp[i][j];
    }
    int m, n;
};
