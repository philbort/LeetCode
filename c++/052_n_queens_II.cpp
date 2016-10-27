/*

52. N-Queens II

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/

class Solution {
public:
    int totalNQueens(int n) {
        this->n = n;
        int result = 0;
        vector<string> cur(n, string(n,'.'));
        backtracking(result, cur, 0);
        return result;
    }
private:
    void backtracking(int& result, vector<string>& cur, int row) {
        if(row == n) {
            result++;
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


/* Add a fancy solution to track the diagonals:

class Solution {
public:
int totalNQueens(int n) {

    int count = 0;
    vector<bool> cols(n, true);
    vector<bool> main(2 * n - 1, true);
    vector<bool> anti(2 * n - 1, true);
    helper(0, count, cols, main, anti);
    return count;
}
private:
void helper(int s, int& count, vector<bool>& cols, vector<bool>& main, vector<bool>& anti)
{
    if (s == cols.size())
    {
        count++;
        return;
    }
    for (int i = 0; i < cols.size(); i++)
    {
        if (cols[i] && main[s + i] && anti[s + cols.size() - 1 - i])
        {
            cols[i] = main[s + i] = anti[s + cols.size() - 1 - i] = false;
            helper(s + 1, count, cols, main, anti);
            cols[i] = main[s + i] = anti[s + cols.size() - 1 - i] = true;
        }
    }
}
};

*/