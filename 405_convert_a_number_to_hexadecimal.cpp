/*

405. Convert a Number to Hexadecimal 

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. 
If the number is zero, it is represented by a single zero character '0'; 
otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"

*/

class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    string toHex(int num) {
        if(!num) return "0";
        string result;
        // Convert two's complement negative number to positive
        unsigned int unsigned_num = num;
        // Convert every 4 digits
        while(unsigned_num) {
            result += hex[unsigned_num & 15];
            unsigned_num >>= 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
private:
    const string hex = "0123456789abcdef";
};
