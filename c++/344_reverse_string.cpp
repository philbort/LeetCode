/*

344. Reverse String

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".


*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j)    swap(s[i++], s[j--]);
        return s;
    }
};
