/*

6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {

public:
	
    string convert(string s, int numRows) {
        if( numRows <= 1 || s.size() <= numRows)  
            return s;
        string *temp = new string[numRows];
        int curRow = 0, rowStep = 1;
        for (int i = 0; i < s.size(); i++) {
            temp[curRow].push_back(s[i]);
            // Move down
            if (curRow == 0)
                rowStep = 1;
            // Move up
            if (curRow == numRows -1)
                rowStep = -1;
            curRow += rowStep;
        }
        string result(temp[0]);
        for (int i = 1; i < numRows;i++)
            result.append(temp[i]);
        // Garbage collection
        delete[] temp;
        temp = NULL;
        
        return result;
        
        
    }
};
