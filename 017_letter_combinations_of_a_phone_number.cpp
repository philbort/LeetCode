/*

17. Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

class Solution {

public:

    vector<string> letterCombinations(string digits) {

        vector<string> result;
        if(digits.empty())  return result;
        string map[10] = {"","","abc","def","ghi","jkl",
                          "mno","pqrs","tuv","wxyz"};
        result.push_back("");
        
        for (int i = 0; i < digits.size(); i++) {
            // Whenever there is a "0" or "1", result is empty
            if(digits[i] == '0' || digits[i] == '1')
                return vector<string> ();
            // The current level    
            vector<string> cur;
            string c = map[digits[i] - '0'];
            for (int j = 0; j < c.size(); j++){
                for (int k = 0; k < result.size(); k++)
                    cur.push_back(result[k] + c[j]);
            }
            /* Assign result to the current level. Cannot just
               add cur to result, otherwise for "23", all the 
               "a", "b", "c" will still stay in the result
            */
            result = cur;
        }
        return result;
    }
};
