/*

63. Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/

class Solution {
	
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Check the size
        if ( m == 0 || n == 0)
            return 0;
            
        // If either the beginning or the end value is 1    
        if ( obstacleGrid[0][0] == 1 ||
             obstacleGrid[m-1][n-1] == 1)
             return 0;
             
        vector<int> uniquePath(n,0);
        uniquePath[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    uniquePath[j] = 0;
                else if (j > 0)
                    uniquePath[j] += uniquePath[j-1];
            }
        }
        return uniquePath[n-1];
    }
};
