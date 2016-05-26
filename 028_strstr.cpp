/*

28. Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

class Solution {

public:
	
    int strStr(string haystack, string needle) {
        
        // i < haystack.size() - needle.size() + 1 doesn't work, why???
        for (int i = 0; i < (int)(haystack.size()-needle.size()+1); i++)
        {
            int j = 0;
            while (j < needle.size() && haystack[i+j] == needle[j])
                j++;
            if (j == needle.size()) 
                return i;
        }
        return -1;
    }
};

