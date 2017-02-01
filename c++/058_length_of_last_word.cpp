/*

58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/

class Solution {

public:
    // Time: O(n)
    // Space: O(1)
    int lengthOfLastWord(string s) {
        int result = 0;
        for(int n = s.size()-1; n>=0; n--)
        {
            if(s[n] != ' ')
                result++;
            else
            {	// Make sure it's not the last character and not consective space
                if(n < s.size()-1 && s[n+1] != ' ')
                    return result;
            }
        }
        return result;
    }
};
