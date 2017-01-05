/*

66. Plus One

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/

class Solution {

public:
    // Time: O(n)
    // Space: O(1)
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n-1; i >= 0; i--)
        {
            /* since only plus one, if we see 
               a 9, we change to 0. Otherwise
               we do a plus 1 and no need to 
               continue.
            */
            if(digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i]++;
                return digits;
            }
        }
        /* if we finished the loop, that means
           we need to add a digit, and that only
           happens if all digits are 9. So the 
           result is 1 plus trailing 0s.
           To avoid insert in the beginning, we 
           can just change the first digit to 1
           and push back a 0 at the back.
        */
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

/*  first solution:

    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int plusOne = 1;
        for (int i = n-1; i >= 0; i--)
        {
            digits[i] += plusOne;
            if(digits[i]>9) plusOne = 1;
            else    plusOne = 0;
            digits[i] %= 10;
        }
        if(plusOne)
            digits.insert(digits.begin(),plusOne);
        return digits;
    }
*/
