/*

264. Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

*/

class Solution {
	
public:
    int nthUglyNumber(int n) {
        if (n < 1)
            return 0;
        if (n == 1)
            return 1;
        vector<int> UglyNumber;
        UglyNumber.push_back(1);
        int Number2 = 0, Number3 = 0, Number5 = 0;
        int num;
        for (int i = 1; i < n; i++)
        {
            num = min(UglyNumber[Number2] * 2, min(UglyNumber[Number3]*3, UglyNumber[Number5]*5));
            if(num == UglyNumber[Number2] * 2)
                Number2++;
            if ( num == UglyNumber[Number3]*3)
                Number3++;
            if ( num == UglyNumber[Number5]*5)
                Number5++;
            UglyNumber.push_back(num);
        }
        return UglyNumber.back();
    }
};
