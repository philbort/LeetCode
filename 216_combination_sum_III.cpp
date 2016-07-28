/*

216. Combination Sum III

Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combo;
        helper(result, combo, 1, k, n);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& combo, int start, int k, int n) {
        if(k == 0 && n == 0){
            result.push_back(combo);
            return;
        }
        for(int i = start; i <= 9; i++) {
            if(k == 0 || n - i < 0)
                return;
            combo.push_back(i);
            helper(result, combo, i+1, k-1, n-i);
            combo.pop_back();
        }
    }
};
