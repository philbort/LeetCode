/*

3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

class Solution {

public:
	
    int lengthOfLongestSubstring(string s) {
        
        /* 256 is the length of the ascii table.
           If we know the size of the hash table,
           do not use unordered_map anymore,
           use a fixed size vector.
        */
        vector<int> dict(256, -1); 
        
        // -1 to denote the character is not presented yet
        int maxLen = 0, start = -1;
        
        for (int i = 0; i < s.size(); i++) {
            // char can be used for indexing directly
            if( dict[s[i]] > start)
                start= dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);

        }
        return maxLen;
    }
};
