/*

397. Integer Replacement

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1

*/

class Solution {
public:
    // Time: O(1)
    // Space: O(1)
    int integerReplacement(int n) {
        if(n == INT_MAX)    return 32;
        int cnt = 0;
        while(n != 1) {
            // Even numbers
            while(!(n&1)){
                n >>= 1;
                cnt++;
            }
            if(n == 1)  return cnt;
            // Corner case
            if(n == 3)  return cnt + 2;
            // Odd number to minus
            else if(!((n >> 1)&1) && n > 0)
                n -= 1;
            // Odd number to plus one
            else
                n += 1;
            cnt++;
        }
        return cnt;
    }
};
