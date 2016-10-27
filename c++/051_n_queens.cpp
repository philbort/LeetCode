/*

51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<string>> result;
        vector<string> cur(n, string(n,'.'));
        backtracking(result, cur, 0);
        return result;
    }
private:
    void backtracking(vector<vector<string>>& result,
                      vector<string>& cur, int row) {
        if(row == n) {
            result.push_back(cur);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(valid(cur, row, col)) {
                cur[row][col] = 'Q';
                backtracking(result, cur, row + 1);
                cur[row][col] = '.';
            }
        }
    }
    bool valid(vector<string>& cur, int row, int col) {
        for(int i = 0; i < row; i++) {
            if (cur[i][col] == 'Q')
                return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(cur[i][j] == 'Q')
                return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++) {
            if(cur[i][j] == 'Q')
                return false;
        }
        return true;
    }
    int n;
};

/* fancy solution to track the diagonals:

The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 2 * n - 1. 
When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row. 
We can use three arrays to indicate if the column or the diagonal had a queen before, if not, we can put a queen in this position and continue.

  *    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \ 
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
  
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, 
                      std::vector<std::string> &nQueens, 
                      std::vector<int> &flag_col, 
                      std::vector<int> &flag_45, 
                      std::vector<int> &flag_135, 
                      int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};

*/
