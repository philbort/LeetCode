/*

9. Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.

*/

class Solution {

public:

    bool isPalindrome(int x) {
        // Negative number is not
        if ( x < 0 )
            return false;
        // Single digit positive number is
        if ( x < 10 )
            return true;
        // Use double to avoid overflow
        double n = 0;
        int x_cpy = x;
        while( x_cpy )
        {
            n = n*10 + x_cpy%10;
            x_cpy /= 10;
        }
        return (int) n == x;
    }
};
