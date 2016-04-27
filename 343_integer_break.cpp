/*

343. Integer Break 

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

*/

class Solution {

public:

    int integerBreak(int n) {
    	/*
			2 -> 1x1 = 1
			3 -> 1x2 = 2
			4 -> 2x2 = 4
			5 -> 2x3 = 6
			6 -> 3x3 = 9
			7 -> 2x2x3 = 12
			8 -> 2x3x3 = 18
			9 -> 3x3x3 = 27
			10 -> 2x2x3x3 = 36
			11 -> 2x3x3x3 = 54
    	*/
		switch (n)
		{
    		case 2:
    			return 1;
    		case 3:
    			return 2;
    		case 4:
    			return 4;
    		case 5:
    			return 6;
    		case 6:
    			return 9;
            default:
    			return 3 * integerBreak(n - 3);
        }
    }
};