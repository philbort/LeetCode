/*

54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
    // Time: O(m*n)
    // Space: O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if (matrix.empty()) return vector<int> ();
        int m = matrix.size(), n = matrix[0].size();
        // We already know the size
        vector<int> result(m*n);
        
        int left = 0, right = n - 1, up = 0, down = m - 1;
        int ind = 0;
        while (true)
        {
            // from left to right
            if (left > right)   break;
            for (int i = left; i <= right; i++)
                result[ind++] = matrix[up][i];
            up++;
            
            // from up to down
            if (up > down)  break;
            for (int i = up; i <= down; i++)
                result[ind++] = matrix[i][right];
            right--;
            
            // from right to left
            if (left > right)   break;
            for (int i = right; i >= left; i--)
                result[ind++] = matrix[down][i];
            down--;
            
            // from down to up
            if (up > down)  break;
            for (int i = down; i >= up; i--)
                result[ind++] = matrix[i][left];
            left++;

        }
        return result;
    }
};
