/*

242. Valid Anagram

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

*/

class Solution {

public:
	
    bool isAnagram(string s, string t) {
        
        // Sizes have to be the same
        if ( s.size() != t.size() )
            return false;
            
        //  Create a hash table
        vector<int> table(26,0);
        
        // Register all the letters from s
        // and unregister all the letters from t
        for (int i = 0; i < s.size(); i++)
        {
            table[s[i] - 'a']++;
            table[t[i] - 'a']--;
        }
        
        // If anagram, all the letter numbers
        // should be zero
        for (int i = 0; i < 26; i++)
        {
            if (table[i] != 0)
                return false;
        }
        
        return true;
    }
};