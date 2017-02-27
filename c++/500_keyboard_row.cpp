/*

500. Keyboard Row

Given a List of words, 
return the words that can be typed using letters of alphabet on 
only one row's of American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> r1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> r2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> r3 = {'z','x','c','v','b','n','m'};
        vector<unordered_set<char>> r = {r1, r2, r3};
        vector<string> res;
        int row;
        for(string & word: words) {
            for(int i = 0; i < 3; i++) {
                if(r[i].find(tolower(word[0])) != r[i].end())
                    row = i;
            }
            bool valid = true;
            for(int j = 1; j < word.size(); j++) {
                if(r[row].find(tolower(word[j])) == r[row].end()) {
                    valid = false;
                    break;
                }
            }
            if(valid)   res.push_back(word);
        }
        return res;
    }
};
