/*

342. Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

*/

class Solution {

public:
    // Time: O(1)
    // Space: O(1)
    bool isPowerOfFour(int num) {
        
        return ( num > 0 && (num&(num-1))==0 && (num & 0x55555555) == num );
    }
};

// return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
