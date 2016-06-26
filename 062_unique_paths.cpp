/*

62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Note: m and n will be at most 100.

*/

class Solution {
public:
    // Basically n choose k combination
    int uniquePaths(int m, int n) {
        
        // Use double to avoid over flow
        double ans = 1;
        
        // total choosen combo
        int total = m - 1 + n - 1;
        
        // Use the smaller number of combo for speed
        int combo = n-1 > m-1? m-1 : n-1;
        
        if (total == combo)
            return 1;
            
        for (int i = 0; i < combo; i++)
            ans *= (total-i);
        for (int i = combo; i > 1; i--)
            ans /= i;
        return (int)ans;
        
    }
};
