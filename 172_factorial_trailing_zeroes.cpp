/*

172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/

class Solution {
	
public:
    int trailingZeroes(int n) {
        int m = 0;
        while(n > 0)
        {
            n/=5;
            m += n;
        }
        return m;
    }
};
