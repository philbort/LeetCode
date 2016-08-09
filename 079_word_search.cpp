/*

79. Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if( board.empty() || word.empty() )
            return false;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (gridSearch(word, 0, board, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    int m, n;  // Sizes of the board
    
    bool gridSearch(string& word, int k, vector<vector<char>>& board, int i, int j) {
        // Check the boundaries
        if ( i < 0 || i > m - 1 || 
             j < 0 || j > n - 1 )
            return false;
        // Already visited or does not match
        if(board[i][j] == '\0' || word[k] != board[i][j])
            return false;
        // Matches the end, we find it!
        if(k == word.size() - 1 && word[k] == board[i][j])
            return true;
        // Cache the current char
        char tmp = board[i][j];
        // Replace it with \0 to mark the visited
        board[i][j] = '\0';
        // DFS
        bool ret =  (gridSearch(word,k+1, board, i-1, j) ||
                     gridSearch(word,k+1, board, i+1, j) ||
                     gridSearch(word,k+1, board, i, j-1) ||
                     gridSearch(word,k+1, board, i, j+1) );
        // Mark it back
        board[i][j] = tmp;
        
        return ret;

    }
};
