/*

12. Integer to Roman   

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

*/


class Solution {

public:

    string intToRoman(int num) {
        const string M[] = {"", "M", "MM", "MMM"};
        const string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};