/*

205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

*/

class Solution {

public:
	
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
            
        // 127 is the size of ASCII
	    vector<char> mapStoT(127, 0);
	    vector<char> mapTtoS(127, 0);
	    
    	for (int i = 0; i < s.size(); ++i)
    	{
    		char s_char = s[i], t_char = t[i];
    		if (mapStoT[s[i]] == 0 && mapTtoS[t[i]] == 0)
    		{
    			mapStoT[s[i]] = t[i];
    			mapTtoS[t[i]] = s[i];
    		}
    		else if (mapTtoS[t[i]] != s[i] || mapStoT[s[i]] != t[i])
    			return false;
    	}
    	return true;
    }
};
