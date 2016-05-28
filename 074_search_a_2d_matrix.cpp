/*

74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/

class Solution {

public:

    // treat matrix as a sorted array
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	
        if(matrix.empty())  return false;
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (matrix[mid/col][mid%col] == target)
                return true;
            else if( matrix[mid/col][mid%col] > target)
                right = mid -1;
            else
                left = mid + 1;
        }
        return false; 
        /* if we do while(left < right)
           we can return matrix[left/col][left%col] == target;
           Same thing but could be easier for book keeping
        */
    }
};


/*  treat as a matrix

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())  return false;
        int up = 0, down = matrix.size() - 1;
        while (up <= down)
        {
            int row = up + (down - up)/2;
            if (matrix[row][0] == target)
                return true;
            else if (matrix[row][0] > target)
                down = row-1;
            else if (matrix[row].back() < target)
                up = row+1;
            else {
                int left = 0, right = matrix[row].size() - 1;
                while ( left <= right)
                {
                    int col = left + (right - left)/2;
                    if (matrix[row][col] == target)
                        return true;
                    else if (matrix[row][col] > target)
                        right = col - 1;
                    else
                        left = col + 1;
                }
                return false;
            }
        }
        return false;
    }
    
*/
