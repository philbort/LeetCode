/*

96. Unique Binary Search Trees 

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */

class Solution {

public:

    int numTrees(int n) {

        if(n < 2)
            return 1;
        
        // Initialize double to avoid overflow
        vector<double> cnt(n+1);
        
        cnt[0] = 1;
        cnt[1] = 1;
        
        for (int i = 2; i <= n; i++)
        {
            for(int j = 0; j < i/2; j++)
            {
                cnt[i] +=cnt[j] * cnt[i-j-1];
            }
            cnt[i] *= 2;
            if(i%2)
                cnt[i] += cnt[i/2]*cnt[i/2];
        }
        return (int) cnt[n];
    }
};