/*

8. String to Integer (atoi)

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.

*/

class Solution {

public:
	
    int myAtoi(string str) {
        int n = str.size();
        long ans = 0;
        int sign = 1;
        int i = 0;
        while (i < n)
        {
            // Skip the white space in beginning
            while(str[i] == ' ')
                i++;
            // Choose the sign
            if(str[i] == '-' || str[i] == '+')
                sign = (str[i++] == '-') ? -1 : 1;
            while (str[i] >= '0' && str[i] <= '9') {
                ans = ans * 10 + str[i++] - '0';
                if (ans*sign >= INT_MAX)
                    return INT_MAX;
                if (ans*sign <= INT_MIN)
                    return INT_MIN;
            }
            /* Return the result once the char is not
               numerical anymore.
               For example, "-0012a2" should return -12
            */
            return ans*sign;
        }
        // Prevent warning, should never reach here
        return ans*sign;
    }
};

