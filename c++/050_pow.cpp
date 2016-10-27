/*

50. Pow(x, n)

Implement pow(x, n).

*/

class Solution {
	
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        /* don't do:
           if (n<0)  n = -n
           will have overflow problem when n = INT_MIN
           recall:
                INT_MAX: 2147483647
                INT_MIN: -2147483648
        */
        if ( n==-1 ) return 1/x;
        return myPow(x*x,n/2)* ( n%2==0? 1:
                                         n>0? x : 1/x );
    }
};
