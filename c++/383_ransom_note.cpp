/*

383. Ransom Note 

 Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  
write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines; 
 otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

class Solution {
public:
    // Since we know the strings are consist of a-z
    // we can use a size pre-defined vector rathan than
    // unordered_map
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> map(26, 0);
        for (int i = 0; i < magazine.size(); i++)
                map[magazine[i] - 'a']++;
                
        for (int j = 0; j < ransomNote.size(); j++) {
            if( --map[ransomNote[j] -'a'] < 0)
                return false;
        }
        return true;
    }
};

/*  Use unordered_map

    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (int i = 0; i < magazine.size(); i++)
        // map[magazine[i]] default is 0 if not in the hash table
                map[magazine[i]]++;
                
        for (int j = 0; j < ransomNote.size(); j++) {
            if( --map[ransomNote[j]] < 0)
                return false;
        }
        return true;
    }
    
*/
