/*

59. Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {

public:

    vector<vector<int>> generateMatrix(int n) {
        if(n <= 0)  return vector<vector<int>> ();
        int left = 0, right = n - 1, up = 0, down = n -1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int k = 1;
        while (true)
        {
            if (left > right)   break;
            for (int i = left; i <= right; i++)
                matrix[up][i] = k++;
            up++;
            
            if (up > down)  break;
            for (int i = up; i <= down; i++)
                matrix[i][right] = k++;
            right--;
            
            if (left > right)   break;
            for (int i = right; i >= left; i--)
                matrix[down][i] = k++;
            down--;
            
            if (up > down)  break;
            for (int i = down; i >= up; i--)
                matrix[i][left] = k++;
            left++;
        }
        return matrix;
    }
};
