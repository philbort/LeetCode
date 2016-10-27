/*

221. Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.

*/

class Solution {

public:
	
    // O(col) space complexity:

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())     return 0;
        int row = matrix.size(), col = matrix[0].size();
        // Only need to save the current row
        vector<int> dp(col);
        int result = 0;
        // The first row (boundary condition)
        for (int j = 0; j < col; j++) {
            dp[j] = matrix[0][j] - '0';
            result = max(result, dp[j]);
        }
        // Go through the rest row by row
        for (int i = 1; i < row; i++) {
            /* left_upper is the "dp[i-1][j-1]",
               need to save it before update */
            int left_upper = dp[0];
            // Column boundary condition
            dp[0] = matrix[i][0] - '0';
            result = max(result, dp[0]);
            
            // Go through the columns
            for (int j = 1; j < col; j++) {
                // Save the value for left_upper before update
                int temp = dp[j];
                if (matrix[i][j] == '1') {
                    dp[j] = min(dp[j - 1], min(dp[j], left_upper)) + 1;
                    result = max(result, dp[j]);
                }
                else {
                    // Make sure to update the 0s for the new row
                    dp[j] = 0;
                }
                left_upper = temp;
            }
        }
        return result * result;
    }
};

/*  O(2*col) space complexity:

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())     return 0;
        int row = matrix.size(), col = matrix[0].size();
        // Only need to save two rows
        vector<vector<int>> dp(2, vector<int>(col));
        int result = 0;
        // The first row (boundary condition)
        for (int j = 0; j < col; j++) {
            dp[0][j] = matrix[0][j] - '0';
            result = max(result, dp[0][j]);
        }
        // Indices for current and previous rows
        int curRow = 1, preRow = 0;
        // Go through the rest row by row
        for (int i = 1; i < row; i++) {
            // Column boundary condition
            dp[curRow][0] = matrix[i][0] - '0';
            result = max(result, dp[curRow][0]);
            // Go through the columns
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '1') {
                    dp[curRow][j] = min(dp[preRow][j - 1], 
                                        min(dp[preRow][j], dp[curRow][j - 1])) + 1;
                    result = max(result, dp[curRow][j]);
                }
                else
                    // Make sure to update the 0s for the new row
                    dp[curRow][j] = 0;
            }
            // swap current and previous row indices (as we only have two rows)
            curRow = preRow;
            preRow = 1 - curRow;
        }
        return result * result;
    }
*/

/* Original O(row*col) space complexity:

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())     return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int result = 0;
        for (int j = 0; j < col; j++) {
            dp[0][j] = matrix[0][j] - '0';
            result = max(result, dp[0][j]);
        }
        for (int i = 1; i < row; i++) {
            dp[i][0] = matrix[i][0] - '0';
            result = max(result, dp[i][0]);
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result * result;
    }

*/
