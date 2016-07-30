/*

189. Rotate Array 

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if( n < 2 || k == 0 || k%n == 0)
            return;
        k %= n;
        
        int tmp;
        int i = 0, j = n-k-1;
        /* from
           [1,2,3,4,5,6,7]
           to 
           [4,3,2,1,5,6,7]
        */
        while(i<j)
            swap(nums[i++],nums[j--]);
        /* from
           [4,3,2,1,5,6,7]
           to 
           [4,3,2,1,7,6,5]
        */
        i = n-k;
        j = n-1;
        while(i<j)
            swap(nums[i++],nums[j--]);
        /* from
           [4,3,2,1,7,6,5]
           to 
           [5,6,7,1,2,3,4]
        */
        i = 0;
        j = n-1;
        while(i<j)
            swap(nums[i++],nums[j--]);
    }
};
