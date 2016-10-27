/*

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

*/

class Solution {

public:

    string longestCommonPrefix(vector<string>& strs) {
    	
        if (strs.empty()) return string ();
        if (strs.size() == 1)   return strs[0];
        string prefix;
        for (int i = 0; i < strs[0].size(); i++)
        {
            for(int j = 1; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i])
                {
                    return prefix;
                }
            }
            prefix.push_back(strs[0][i]);
        }
        return prefix;
        
    }
};
