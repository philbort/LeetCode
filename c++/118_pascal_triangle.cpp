/*

118. Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {

public:

    vector<vector<int>> generate(int numRows) {

        if (!numRows)
            return vector<vector<int>> ();

        vector<vector<int>> ans(numRows);
        
        for (int i = 0; i < numRows; i++)
        {
            // have to resize, or use push_back
            ans[i].resize(i+1);  
            ans[i][0] = ans[i][i] = 1;
            for (int j = 1; j < i; j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        return ans;
    }
};