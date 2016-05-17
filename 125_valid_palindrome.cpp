/*

125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

*/

class Solution {

public:

    bool isPalindrome(string s) {
    	
        int n = s.size();
        if ( n < 2)
            return true;
        int i = 0, j = n - 1;
        while(i < j)
        {
            if ( !isalnum(s[i]) )  //isalnum returns true if number or letter
                i++;
            else if ( !isalnum(s[j]) )
                 j--;
            else if ( tolower(s[i++]) != tolower(s[j--]) )
                 return false;
        }
        return true;
    }
};
