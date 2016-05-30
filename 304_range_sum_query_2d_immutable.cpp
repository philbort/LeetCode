/*

304. Range Sum Query 2D - Immutable

Given a 2D matrix matrix, 
find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.

*/

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

class NumMatrix {
	
public:

    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        int row = matrix.size();
        int col = matrix[0].size();
        /* Add a row and a column of 0s to handle boundary conditions,
           be careful of the index below. Sum is basically 1 higher
           than matrix in both row and column index.
        */ 
        Sum = vector<vector<int>> (row+1, vector<int> (col+1, 0));
        
        /* if matrix = [1, 2, 3
                        4, 5, 6
                        7, 8, 9]
           then sum = [0, 0,   0,  0
                       0, 1,   3,  6
                       0, 5,  12, 21
                       0, 12, 27, 45]
        */
        for (int i = 1; i < row+1; i++)
        {
            for (int j = 1; j < col+1; j++)
                Sum[i][j] = Sum[i][j-1] + 
                            matrix[i-1][j-1] + 
                            Sum[i-1][j] - 
                            Sum[i-1][j-1];
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        /* if sumRegion(1, 1, 2, 2)
           5+6+8+9 = 28 = 45 - 12 -6 + 1
           be careful of the index
        */
        return ( Sum[row2+1][col2+1] - 
                 Sum[row1][col2+1] -
                 Sum[row2+1][col1] +
                 Sum[row1][col1] );
                            
    }
private:
    vector<vector<int>> Sum;
};
