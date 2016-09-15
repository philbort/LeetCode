/*

37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/

class Solution {
public:
    // Time: O(n^3) ?? Not sure
    // Space: O(n^2)
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = i/3*3 + j/3;
                    row[i][num] = col[j][num] = cell[k][num] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
private:
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if(i == 9) return true;
        if(j == 9) return dfs(board, i+1, 0);
        if(board[i][j] != '.') return dfs(board, i, j+1);
        
        int k = i/3*3 + j/3;
        for(int num = 0; num < 9; num++) {
            if(row[i][num] || col[j][num] || cell[k][num])
                continue;
            board[i][j] = num + '1';
            row[i][num] = col[j][num] = cell[k][num] = true;
            if(dfs(board, i, j+1))   return true;
            board[i][j] = '.';
            row[i][num] = col[j][num] = cell[k][num] = false;    
        }

        return false;
    }
    bool row[9][9], col[9][9], cell[9][9];
};
