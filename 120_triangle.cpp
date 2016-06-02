/*

120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

class Solution {
	
public:
    // From bottom to top, I guess it's cleaner
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())    return 0;
        vector<int> sum = triangle.back(); // O(n) space
        for (int i = triangle.size()-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++)
                sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
        }
        return sum[0];
    
    }
};

/*
    // From top to bottom
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())    return 0;
        int row = triangle.size();
        vector<int> sum(row,0);  // O(n) space
        for (int i = 0; i < row; i++) {
            // from right to left since the left values are overwritten
            for (int j = i; j >= 0; j--) {
                if ( j == 0 )
                    sum[j] += triangle[i][j];
                else if ( j == i)
                    sum[j] = sum[j-1] + triangle[i][j];
                else
                    sum[j] = triangle[i][j] +  min(sum[j-1], sum[j]) ;
            }
        }
        return *min_element(sum.begin(), sum.end());
    }
*/
