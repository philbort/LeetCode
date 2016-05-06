/*

69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.

*/

class Solution {

public:

    int mySqrt(int x) {

        double result = x/2.0;

        while( fabs(result * result - x) > 0.1 )
        {
                result = (result + x/result) / 2;
        }
        return (int) result;
    }
};