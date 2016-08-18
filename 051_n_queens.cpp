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
