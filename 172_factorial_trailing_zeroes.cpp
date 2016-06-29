/*

172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/

class Solution {
	
public:
    int trailingZeroes(int n) {
        int m = 0;
        /* There are always more 2s
           than 5s, so only count 5s.
   	*/
        while(n > 0)
        {
            n/=5;
            m += n;
        }
        return m;
    }
};

/* Fancy recursion:

int trailingZeroes(int n) {
return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}

*/
