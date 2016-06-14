/*

38. Count and Say

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*/

class Solution {
	
public:

    string countAndSay(int n) {
        if (n < 1)  return string ();
        string result = "1";
        for (int i = 1; i < n; i++) {
            string cur = "";
            for (int j = 0; j < result.size(); j++) {
                int cnt = 1;
                while (j < result.size() - 1 && result[j] == result[j+1]) {
                    cnt++;
                    j++;
                }
                cur += to_string(cnt) + result[j];    
            }
            result = cur;
        }
        return result;
    }
};
