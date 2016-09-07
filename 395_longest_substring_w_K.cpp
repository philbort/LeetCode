/*

395. Longest Substring with At Least K Repeating Characters

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that 
every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

*/

class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size());
    }
private:
    int helper(string s, int k, int start, int end) {
        // Hash table for known size
        int map[26] = {0};
        // Hash the counter
        for (int i = start; i < end; i++)
            map[s[i] - 'a']++;
        int max_len = 0;
        for (int i = start; i < end; ) {
            // Skip the less-than-k chars in the beginning
            while(i < end && map[s[i] - 'a'] < k)
                i++;
            // Boundary condition
            if(i == end)
                break;
            // Count the number of qualified chars
            int l = i;
            while(l < end && map[s[l] - 'a'] >= k)
                l++;
            // If we covered the entire (sub)string, return
            if(i == start && l == end)
                return end - start;
            // Update the maximum length
            max_len = max(max_len, helper(s, k, i, l));
            // Find a new starting point
            i = l;
        }
        return max_len;
    }
};
