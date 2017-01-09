/*

326. Power of Three

Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

*/

class Solution {
public:
    // Time: O(1)
    // Space: O(1)
    bool isPowerOfThree(int n) {
        double ans = log10(n)/log10(3);
        return ans == (int) ans;
    }
};

/*

bool isPowerOfThree(int n) {
    int maxPowerOfThree = (int)Math.pow(3, (int)(Math.log(0x7fffffff) / Math.log(3)));
    return n>0 && maxPowerOfThree%n==0;
}

*/
