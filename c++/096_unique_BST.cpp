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
        
        // 1 for 0 or 1 node
        if(n < 2)   return 1;
        vector<int> cnt(n+1);
        cnt[0] = cnt[1] = 1;
        
        for (int i = 2; i <= n; i++)
        {
           /* Cycle through the root,
           i.e., how many on the left side of 
           the root and how many on the right
           side of the root.
           Only do half (i/2) since the other
           half is the same
           */
            for(int j = 0; j < i/2; j++)
            {
                cnt[i] +=cnt[j] * cnt[i-j-1];
            }
            // Multiply for the other half
            cnt[i] *= 2;
            /* if even number of node, include 
            the middle one (non-symmetric one)
            */
            if(i%2)
                cnt[i] += cnt[i/2]*cnt[i/2];
        }
        return cnt[n];
    }
};
