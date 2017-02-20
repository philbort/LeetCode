/*

463. Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). 
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16


*/

class Solution {
public:
    // Time: O(m*n)
    // Space: O(1)
    int islandPerimeter(vector<vector<int>>& grid) {
        int Ones = 0, Adjacent = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    Ones++;
                    if(i && grid[i-1][j])  Adjacent++;
                    if(j && grid[i][j-1])  Adjacent++;
                }
            }
        }
        return 4 * Ones - 2 * Adjacent;
    }
};
