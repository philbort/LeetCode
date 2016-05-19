/*

119. Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {

public:

    vector<int> getRow(int rowIndex) {

        if (rowIndex < 0)  return vector<int> ();

        vector<int> result(rowIndex+1, 0);
        
        for (int i = 0; i < rowIndex+1; i++) {
            result[0] = result[i] = 1;
            for(int j = i-1; j > 0; j--)
                result[j] += result[j-1];
        }
        return result;
    }
};
