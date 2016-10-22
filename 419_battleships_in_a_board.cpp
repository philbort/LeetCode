/*

419. Battleships in a Board

Given an 2D board, count how many different battleships are in it. 
The battleships are represented with 'X's, empty slots are represented with '.'s. 
You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. 
In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

Example:

X..X
...X
...X
In the above board there are 2 battleships.

Invalid Example:

...X
XXXX
...X
This is not a valid board - as battleships will always have a cell separating between them.

Your algorithm should not modify the value of the board.

*/

class Solution {
public:
    // Time: O(m*n)
    // Space: O(1)
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty())   return 0;
        int result = 0, m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j]=='X' && 
                    (i==0 || board[i-1][j]!='X') && 
                    (j==0 || board[i][j-1]!='X')) 
                    result++;
            }
        }
        return result;
    }
};
