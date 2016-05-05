/*

345. Reverse Vowels of a String   

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

*/

class Solution {

public:

    string reverseVowels(string s) {

        if(s.size() < 2)
            return s;

        set<char> vowel({'a','o','e','i','u','A','O','E','I','U'});

        int i = 0, j = s.size();
        
        while(i<j)
        {
            if( vowel.find(s[i]) == vowel.end())
                i++;
            if( vowel.find(s[j]) == vowel.end())
                j--;
            if( vowel.find(s[i]) != vowel.end() &&
                vowel.find(s[j]) != vowel.end() )
                {
                    if (s[i] != s[j])
                        std::swap(s[i],s[j]);
                    i++;
                    j--;
                }
        }
        return s;
    }
};