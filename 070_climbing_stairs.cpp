/*

70. Climbing Stairs   

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

class Solution {

public:

    int climbStairs(int n) {

        vector<int> cnt(n+1,0);
        
        cnt[0] = cnt[1] = 1;
        
        for (int i = 2; i <= n; i++)
            cnt[i] = cnt[i-1] + cnt[i-2];
        return cnt[n];
    }
};
