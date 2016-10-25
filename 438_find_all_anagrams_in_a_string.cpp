/*

438. Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if(m < n)  return {};
        vector<int> hash1(26, 0), hash2(26, 0);
        vector<int> result;
        for(int i = 0; i < n; i++) {
            hash1[s[i] - 'a']++;
            hash2[p[i] - 'a']++;
        }
        if(hash1 == hash2)
            result.push_back(0);
        for(int i = n; i < m; i++) {
            hash1[s[i] - 'a']++;
            hash1[s[i-n] - 'a']--;
            if(hash1 == hash2)
                result.push_back(i-n+1);
        }
        return result;

    }
};
