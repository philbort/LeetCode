/*

29. Divide Two Integers 

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Take care of overflow
        if( divisor == 0 ||
            ( dividend == INT_MIN &&
              divisor == -1) )
              return INT_MAX;
        // Get the sign of the result
        int sign = ((dividend < 0)^(divisor < 0)) ? -1 : 1;
        // Treat them as positive integers
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int result = 0;
        while(dvd >= dvs)
        {
            long long temp = dvs, multiple = 1;
            while(dvd >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }
        return sign*result;
    }
};
