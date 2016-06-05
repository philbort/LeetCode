/*

91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/

class Solution {
	
public:
    // O(n) time, O(1) space
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        vector<int> result(2,1);
        for (int i = 1; i < s.size(); i++) {
            // If the current value is 0, invalid the previous decode way
            if (s[i] == '0')
                result[1] = 0;
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <='6') ) {
                int tmp = result[1];
                result[1] = result[0] + result[1];
                result[0] = tmp;            
            }
            else
                result[0] = result[1];
        }
        return result[1];
    }
};


/* O(n) space

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        // Add one value for boundary condition
        vector<int> result(s.size()+1);
        result[0] = result[1] = 1;
        for (int i = 1; i < s.size(); i++) {
            // If the current value is 0, invalid the previous decode way
            if (s[i] == '0')
                result[i] = 0;
            if (s[i-1] == '1' || 
                (s[i-1] == '2' &&
                 s[i] <='6') )
                result[i+1] = result[i-1] + result[i];
            else
                result[i+1] = result[i];
        }
        return result.back();
    }
    
*/
