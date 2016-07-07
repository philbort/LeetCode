/*

201. Bitwise AND of Numbers Range 

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

*/

class Solution {
	
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        /* If m and n are different,
           the least significant bit 
           should always be zero.
           So we find both m and n to
           the right until m and n are
           the same.
        */
        while(m != n){
            m >>= 1;
            n >>= 1;
            result++;
        }
        return m<<result;
    }
};


/* Fancy recursion solution:

    int rangeBitwiseAnd(int m, int n) {
         return (m == n) ? m : (rangeBitwiseAnd(m>>1, n>>1) << 1);
    }
    
*/
