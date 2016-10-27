/*

13. Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

*/

class Solution {
public:
    int romanToInt(string s) 
    {
        if(s.size() == 0)
            return 0;
        unordered_map<char, int> T = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };
    
       int sum = T[s.back()];
       for (int i = s.size() - 2; i >= 0; --i) 
       {
           if (T[s[i]] < T[s[i + 1]])
           {
               sum -= T[s[i]];
           }
           else
           {
               sum += T[s[i]];
           }
       }
    
       return sum;
    }
};