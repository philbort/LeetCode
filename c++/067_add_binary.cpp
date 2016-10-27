/*

67. Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

class Solution {

public:

    string addBinary(string a, string b) {
    	
        if (a.empty())  return b;
        if (b.empty())  return a;
        
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int sum = 0;
        while ( i >= 0 || j >= 0 || sum)
        {
            sum += i >= 0 ? a[i--] - '0' : 0;
            sum += j >= 0 ? b[j--] - '0' : 0;
            ans = char(sum%2 + '0') + ans;
            sum /= 2;
        }
        return ans;
    }
};
