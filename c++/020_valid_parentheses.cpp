/* 

20. Valid Parentheses   

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {

public:

    bool isValid(string s) {
    	
        int n = s.size();
        stack<char> a;
        unordered_map<char,char> p = { {']','['},
                                       {')','('},
                                       {'}','{'} };
        for(int i = 0; i < n; i++)
        {
            if( s[i] == '(' ||
                s[i] == '[' ||
                s[i] == '{' )
                a.push(s[i]);
                
            else if( s[i] == ')' ||
                     s[i] == ']' ||
                     s[i] == '}' )
             {
                 if (a.empty() || p[s[i]] != a.top())
                    return false;
                 else
                    a.pop();
             }
        }
        // should have nothing left in the stack
        return a.empty();
    }
};