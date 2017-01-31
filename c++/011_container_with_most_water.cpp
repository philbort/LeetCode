/*

11. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

*/

class Solution {

public:
    // Time: O(n)
    // Space: O(1)
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        if ( j < 1 )
            return 0;
        int area = 0;
        while( i < j ) {
            int h = min(height[i],height[j]);
            area = max(area, (j-i)*h);
            while( height[i] <= h && i < j)
                i++;
            while( height[j] <= h && i < j)
                j--;
            
        }
        return area;
    }
};

/* Brute force:
    // Time: O(n^2)
    // Space: O(1)
    int maxArea(vector<int>& height) {
        int n = height.size();
        if ( n < 2 )
            return 0;
        int area = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
                area = max(area,(j-i)*min(height[i],height[j]));
        }
        return area;
    }
    
*/
