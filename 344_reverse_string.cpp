/*

344. Reverse String

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".


*/

class Solution {
public:
    string reverseString(string s) {
        char tmp;
        int len = s.size();
        for (int i = 0, j = len-1; i < j;i++,j--)
        {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
        return s;
    }
};