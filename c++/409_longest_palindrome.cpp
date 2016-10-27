/*

409. Longest Palindrome

Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int longestPalindrome(string s) {
        vector<int> hash(52, 0);
        for(char c: s) {
            if(c <= 'Z')
                hash[c-'A']++;
            else
                hash[c-'a'+26]++;
        }
        int DoubleCnt = 0;
        bool Single = false;
        for(int i = 0; i < 52; i++) {
            if(hash[i] > 1)
                DoubleCnt += 2*(hash[i]/2);
            if(!Single && hash[i]%2 != 0)
                Single = true;
        }
        return DoubleCnt + (Single? 1: 0);
    }
};
