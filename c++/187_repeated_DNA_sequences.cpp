/*

187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

*/

class Solution {

public:

    /* Since we only have A, C, G, T, convert the string to 
       integer to save memory. In binary, A=0101, C=0103, 
       G=0107, and T=0124. So we only need 3 bits to store
       each character. 30 bits total for a string which could
       be accommodated by a single 32-bit integer.
   */
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> result;
        if (n <= 10) return result;
        unordered_map<int, bool> map;
        int i = 0, str2int = 0;
        // Store the first 9 chars
        while (i < 9)
        {
            // use 7 to mask the last 3 bits
            str2int = str2int << 3 | s[i++] & 7;
        }
        while (i < n)
        {
            // 10 chars are 30 bits, so use 0x3FFFFFFF to mask
            str2int = str2int << 3 & 0x3FFFFFFF | s[i] & 7;
            // If not found, never appears
            if (map.find(str2int) == map.end())
                /* Set to false means appeared once, use boolean
                   to save memory since we don't really care how
                   many times a string appears, only care if it
                   never appeared, once, or twice or more.
               */
                map[str2int] = false;
            else if( map[str2int] == false) {
                result.push_back(s.substr(i-9,10));
                // True means appeared more than once
                map[str2int] = true;
            }
            i++;
        }
        return result;
    }
};

/* First solution, do not take into account there are only 4 letters possible
   Time ok but use a lot of memory to store the strings
   
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> result;
        if (n < 11) return result;
        unordered_map<string, int> map;
        for (int i = 0; i < n - 9; i++)
            map[s.substr(i,10)]++;
        for (auto element : map)
        {
            if (element.second > 1)
                result.push_back(element.first);
        }
        return result;
    }
    
*/
