/*

318. Maximum Product of Word Lengths

Given a string array words, 
find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

*/

class Solution {
	
public:
    // Time: O(n^2)
    // Space: O(n)
    int maxProduct(vector<string>& words) {
        if (words.size() < 2)
            return 0;
        int ans = 0, n = words.size();
        vector<int> bitmap(n, 0);  // or long int ???
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
                bitmap[i] |= ( 1 << ( words[i][j] - 'a' ) );
        }
        
        int product = 0;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if ( (bitmap[i] & bitmap[j]) == 0)   // Cannot miss the ()
                {
                    product = (int) words[i].size() * (int) words[j].size();
                    ans =  max(ans, product);
                }
            }
        }
        return ans;
    }
};
