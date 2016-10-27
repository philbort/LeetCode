/*

367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

*/

class Solution {

public:

    bool isPerfectSquare(int num) {
        long x = num;
        while( x*x > num ){
            x = (x + num/x)/2;
        }
        return x*x == num;
    }
};

/*

bool isPerfectSquare(int num) {
        if (num < 0)    return false;
        int left = 0, right = num;
        while(left < right) {
            // Use int here doesn't work
            long mid = left + (right - left)/2;
            if( mid * mid == num )
                return true;
            else if (mid * mid > num)
                right = mid;
            else
                left = mid + 1;
        }
        return left*left == num;
    }
    
*/
