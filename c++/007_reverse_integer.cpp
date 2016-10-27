/*

7. Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

For the purpose of this problem, 
assume that your function returns 0 when the reversed integer overflows.

*/

class Solution {

public:
	
    int reverse(int x) {
        if ( x < 10 && x > -10 )
            return x;
        // Use double to avoid overflow
        double y = 0;
        while(x)
        {
            y = y*10 + x%10;
            x /= 10;
            // return 0 when overflow
            if( y > INT_MAX || y < INT_MIN )
                return 0;
        }
        return (int) y;
    }
};