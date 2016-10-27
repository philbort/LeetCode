/*

371. Sum of Two Integers

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

*/

class Solution {

public:

    int getSum(int a, int b) {
        int sum = 0;
        bool carry = false;
        for (int i = 0; i < 32; i++) {
            // Get the last digits of a and b
            int d1 = a & 1, d2 = b & 1;
            // Update the current digit of sum
            sum |= ((d1^d2^carry) << i);
            // Update the carry
            carry = (d1&d2) | (d1&carry) | (d2&carry);
            // Update a and b
            a >>= 1;
            b >>= 1;
            // If all zeros, no need to continue
            if ( !a && !b && !carry)
                break;
        }
        return sum;
    }
};

/* WTF:

    int getSum(int a, int b) {
        int sum = a;

        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }

        return sum;
    }

*/