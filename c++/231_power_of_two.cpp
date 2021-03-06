/*

231. Power of Two 

Given an integer, write a function to determine if it is a power of two.

*/


class Solution {
public:
    // Time: O(1)
    // Space: O(1)
    bool isPowerOfTwo(int n) {
       return n > 0 && !( n&(n-1) );
    }
};
