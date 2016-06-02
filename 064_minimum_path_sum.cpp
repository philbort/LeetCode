/*

64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())   return 0;
        // Initialize a row
        vector<int> sum(grid[0].size());
        // Intialize the first value
        sum[0] = grid[0][0];
        // The first row
        for (int i = 1; i < grid[0].size();i++)
            sum[i] = sum[i-1] + grid[0][i];
        // Rest of the rows
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size();j++) {
                if (j == 0)
                    sum[j] += grid[i][j];
                else
                    sum[j] = grid[i][j] + min(sum[j-1],sum[j]);
            }
        }
        return sum.back();
    }
};
