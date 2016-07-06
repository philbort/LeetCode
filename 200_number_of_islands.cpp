/*

200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

*/

class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())    return 0;
        int result = 0;
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    result++;
                    setToZero(grid, i, j);
                }
            }
        }
        return result;
    }
    
private:
    // Set all the adjacent "1"s to "0"
    void setToZero(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if(i > 0 && grid[i-1][j] == '1')
            setToZero(grid, i-1, j);
        if(i < grid.size() - 1 && grid[i+1][j] == '1')
            setToZero(grid, i+1, j);
        if(j > 0 && grid[i][j-1] == '1')
            setToZero(grid, i, j-1);
        if(j < grid[0].size() - 1 && grid[i][j+1] == '1')
            setToZero(grid, i, j+1);
    }
};
