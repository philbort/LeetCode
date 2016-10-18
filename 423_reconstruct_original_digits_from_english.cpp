/*

423. Reconstruct Original Digits from English

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    string originalDigits(string s) {
        int hash[26] = {0};
        int num[10] = {0};
        for(char c: s)  hash[c - 'a']++;
        
        num[0] = hash['z' - 'a'];
        num[2] = hash['w' - 'a'];
        num[4] = hash['u' - 'a'];
        num[6] = hash['x' - 'a'];
        num[8] = hash['g' - 'a'];
        
        num[3] = hash['h' - 'a'] - num[8];
        num[5] = hash['f' - 'a'] - num[4];
        num[7] = hash['v' - 'a'] - num[5];
        num[9] = hash['i' - 'a'] - num[5] - num[6] - num[8];
        num[1] = hash['n' - 'a'] - num[7] - 2*num[9];
        
        string result;
        for(int i = 0; i <= 9; i++) {
            for(int j = num[i]; j > 0; j--)
                result.push_back(i + '0');
        }
        return result;
    }
};

