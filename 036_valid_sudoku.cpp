/*

36. Valid Sudoku

Determine if a Sudoku is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/

class Solution {

public:

    bool isValidSudoku(vector<vector<char>>& board) {

        bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
        
        for (int i = 0; i < 9; i++) {
            for(int j = 0; j <9; j++) {
                
                if ( board[i][j] != '.' ) {
                    int num = board[i][j] - '1';
                    int k = i/3*3 + j/3; // WTF
                    if( row[i][num] || col[j][num] || box[k][num])
                        return false;
                    else
                        row[i][num] = col[j][num] = box[k][num] = true;
                }
            }
        }
        return true;
    }
};

