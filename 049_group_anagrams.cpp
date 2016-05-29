/*

49. Group Anagrams

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

*/

class Solution {

public:
	
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.empty())   return result;
        /* Use unordered_map to store the strings,
           sorted letters are the keys, the actual strings
           are the values.
        */
        unordered_map<string,vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }
        for (auto anagram: map) {
            sort(anagram.second.begin(), anagram.second.end());
            result.push_back(anagram.second);
        }
        return result;
    }

};
