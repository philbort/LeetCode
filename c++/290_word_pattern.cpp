/*

290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

*/

class Solution {
    
public:

    bool wordPattern(string pattern, string str) {
    
    // map for the words in the str
    unordered_map<string, int> word_map;
    
    // pattern size is known (lower case letters),
    // use fixed size vector
    vector<int> letter_map(26,0);
    
    // isstringstream to extract the words from str
    istringstream in(str);
    
    int i = 0, n = pattern.size();
    // >> is the operator to extract word by isstringstream
    for (string word; in >> word; ++i) {
        
        if ( // str size is bigger than pattern
             i == n ||
             /* number of the same words and pattern should be the same,
                effectively to check this case:
                pattern = "abba", str = "dog dog dog dog" 
             */
             letter_map[pattern[i]-'a'] != word_map[word]) 
            return false;
        /* Set the count for words and pattern letters,
           default value for vector and map is 0,
           so we start from i+1 here
        */
        letter_map[pattern[i]-'a'] = word_map[word] = i + 1;
    }
    /* Whether we compared to all the pattern words
       (i.e., sizes have to be the same).
       If pattern is longer, return false
    */
    return i == n;
    }
};
